<?php
/**
 * View/edit testcases
 *
 * Part of the DOMjudge Programming Contest Jury System and licenced
 * under the GNU GPL. See README and COPYING for details.
 */

$pagename = basename($_SERVER['PHP_SELF']);

$probid = @$_REQUEST['probid'];

require('init.php');

$INOROUT = array('input','output');
$TYPE_INOROUT = array('open_input','open_output','hidden_input','hidden_output');

// Download testcase
if ( isset ($_GET['fetch']) && in_array($_GET['fetch'], $INOROUT)) {
	$rank  = $_GET['rank'];
	$fetch = $_GET['fetch'];
	$filename = $probid . $rank . "." . substr($fetch,0,-3);

	$size = $DB->q("MAYBEVALUE SELECT OCTET_LENGTH($fetch)
	                FROM testcase WHERE probid = %s AND rank = %i",
	               $probid, $rank);

	// sanity check before we start to output headers
	if ( $size===NULL || !is_numeric($size)) error("Problem while fetching testcase");

	header("Content-Type: application/octet-stream; name=\"$filename\"");
	header("Content-Disposition: inline; filename=\"$filename\"");
	header("Content-Length: $size");

	// This may not be good enough for large testsets, but streaming them
	// directly from the database query result seems overkill to implement.
	echo $DB->q("VALUE SELECT SQL_NO_CACHE $fetch FROM testcase
	             WHERE probid = %s AND rank = %i", $probid, $rank);

	exit(0);
}

$data = $DB->q('KEYTABLE SELECT rank AS ARRAYKEY, testcaseid, testcasetype, rank, description,
                OCTET_LENGTH(input)  AS size_input,  md5sum_input,
                OCTET_LENGTH(output) AS size_output, md5sum_output
                FROM testcase WHERE probid = %s ORDER BY rank', $probid);

// Reorder testcases
if ( isset ($_GET['move']) ) {
	$move = $_GET['move'];
	$rank = (int)$_GET['rank'];

	// First find testcase to switch with
	$last = NULL;
	$other = NULL;
	foreach( $data as $curr => $row ) {
		if ( $curr==$rank && $move=='up' ) {
			$other = $last;
			break;
		}
		if ( $rank==$last && $move=='down' && $last!==NULL ) {
			$other = $curr;
			break;
		}
		$last = $curr;
	}

	if ( $other!==NULL ) {
		// (probid, rank) is a unique key, so we must switch via a
		// temporary rank, and use a transaction.
		$tmprank = 999999;
		$DB->q('START TRANSACTION');
		$DB->q('UPDATE testcase SET rank = %i
		        WHERE probid = %s AND rank = %i', $tmprank, $probid, $other);
		$DB->q('UPDATE testcase SET rank = %i
		        WHERE probid = %s AND rank = %i', $other, $probid, $rank);
		$DB->q('UPDATE testcase SET rank = %i
		        WHERE probid = %s AND rank = %i', $rank, $probid, $tmprank);
		$DB->q('COMMIT');
		auditlog('testcase', $probid, 'switch rank', "$rank <=> $other");
	}

	// Redirect to the original page to prevent accidental redo's
	header('Location: testcase.php?probid=' . urlencode($probid));
	return;
}

$title = 'Testcases for problem '.htmlspecialchars(@$probid);

require(LIBWWWDIR . '/header.php');

echo "<div class='main-container'>\n";

if ( ! $probid ) error("Missing or invalid problem id");

echo "<h1>" . $title ."</h1>\n\n";

$result = '';
if ( isset($_POST['probid']) && IS_ADMIN ) {

	$maxrank = 0;
	foreach($data as $rank => $row) {
	foreach($INOROUT as $inout) {

		if ( $rank>$maxrank ) $maxrank = $rank;

		$fileid = 'update_'.$inout;
		if ( !empty($_FILES[$fileid]['name'][$rank]) ) {

			// Check for upload errors:
			checkFileUpload ( $_FILES[$fileid]['error'][$rank] );

			$content = file_get_contents($_FILES[$fileid]['tmp_name'][$rank]);
			if ( $DB->q("VALUE SELECT count(testcaseid)
 			             FROM testcase WHERE probid = %s AND rank = %i",
			            $probid, $rank) ) {
				$DB->q("UPDATE testcase SET md5sum_$inout = %s, $inout = %s
				        WHERE probid = %s AND rank = %i",
				       md5($content), $content, $probid, $rank);
				auditlog('testcase', $probid, 'updated', "$inout rank $rank");
			} else {
				$DB->q("INSERT INTO testcase (probid,rank,md5sum_$inout,$inout)
				        VALUES (%s,%i,%s,%s)",
				       $probid, $rank, md5($content), $content);
				auditlog('testcase', $probid, 'added', "$inout rank $rank");
			}
			$result .= "<li>Updated $inout for testcase $rank from " .
			    htmlspecialchars($_FILES[$fileid]['name'][$rank]) .
				" (" . htmlspecialchars($_FILES[$fileid]['size'][$rank]) .
				" B)</li>\n";
		}
	}

	if ( isset($_POST['description'][$rank]) ) {
		$DB->q('UPDATE testcase SET description = %s WHERE probid = %s
		        AND rank = %i', $_POST['description'][$rank], $probid, $rank);
		auditlog('testcase', $probid, 'updated description', "rank $rank");

		$result .= "<li>Updated description for testcase $rank</li>\n";
	}

	} // end: foreach $data

	if ( !empty($_FILES['add_open_input']['name']) ||
		 !empty($_FILES['add_open_output']['name']) ||
		 !empty($_FILES['add_hidden_input']['name']) ||
		 !empty($_FILES['add_hidden_output']['name']) ) {

		$content = array();
		$rank = $maxrank + 1;
		foreach($TYPE_INOROUT as $inout) {
			if ( empty($_FILES['add_'.$inout]['name']) ) {
				warning("No $inout file specified for new testcase, ignoring.");
			} else {
				checkFileUpload ( $_FILES['add_'.$inout]['error'] );
				$content[$inout] = file_get_contents($_FILES['add_'.$inout]['tmp_name']);
			}
		}

		if ( !empty($content['open_input']) && !empty($content['open_output']) &&
			 !empty($content['hidden_input']) && !empty($content['hidden_output'])) {

			// Insert open testcase
			$DB->q("INSERT INTO testcase
			        (probid,testcasetype,rank,md5sum_input,md5sum_output,input,output,
			         description)
			        VALUES (%s,%i,%i,%s,%s,%s,%s,%s)",
			       $probid, 1, $rank, md5(@$content['open_input']), md5(@$content['open_output']),
			       @$content['open_input'], @$content['open_output'], @$_POST['open_add_desc']);
			auditlog('testcase', $probid, 'added', "rank $rank");

			// Insert hidden testcase
			$DB->q("INSERT INTO testcase
			        (probid,testcasetype,rank,md5sum_input,md5sum_output,input,output,
			         description)
			        VALUES (%s,%i,%i,%s,%s,%s,%s,%s)",
			       $probid, 0, ++$rank, md5(@$content['hidden_input']), md5(@$content['hidden_output']),
			       @$content['hidden_input'], @$content['hidden_output'], @$_POST['hidden_add_desc']);
			auditlog('testcase', $probid, 'added', "rank $rank");

			$result .= "<li>Added new testcase $rank from " .
			    htmlspecialchars($_FILES['add_open_input']['name']) .
			    " (" . htmlspecialchars($_FILES['add_open_input']['size']) . " B) and " .
			    htmlspecialchars($_FILES['add_open_output']['name']) .
			    " (" . htmlspecialchars($_FILES['add_open_output']['size']) . " B) and " .
			    htmlspecialchars($_FILES['add_hidden_input']['name']) .
			    " (" . htmlspecialchars($_FILES['add_hidden_input']['size']) . " B) and " .
			    htmlspecialchars($_FILES['add_hidden_output']['name']) .
			    " (" . htmlspecialchars($_FILES['add_hidden_output']['size']) . " B)</li>\n";
		}
	}
}
if ( !empty($result) ) {
	echo "<ul>\n$result</ul>\n\n";

	// Reload testcase data after updates
	$data = $DB->q('KEYTABLE SELECT rank AS ARRAYKEY, testcaseid, testcasetype, rank, description,
	                OCTET_LENGTH(input)  AS size_input,  md5sum_input,
	                OCTET_LENGTH(output) AS size_output, md5sum_output
	                FROM testcase WHERE probid = %s ORDER BY rank', $probid);
}

echo "<p><a href=\"problem.php?id=" . urlencode($probid) . "\">back to problem " .
	htmlspecialchars($probid) . "</a></p>\n\n";

if ( IS_ADMIN ) {
	echo addForm('', 'post', null, 'multipart/form-data') .
	    addHidden('probid', $probid);
}

if ( count($data)==0 ) {
	echo "<p class=\"nodata\">No testcase(s) yet.</p>\n";
} else {
	?>
<table class="list testcases">
<thead>
	<tr>
		<th scope="col">#</th>
		<th scope="col">testcase type</th>
		<th scope="col">download</th>
		<th scope="col">size</th>
		<th scope="col">md5</th>
		<?php if ( IS_ADMIN ) echo '<th scope="col">upload new</th>'; ?>
		<th scope="col">description</th>
		<th scope="col">delete</th>
	</tr>
</thead>
<tbody>
<?php
}
foreach( $data as $rank => $row ) {
	foreach($INOROUT as $inout) {
		echo "<tr>";
		if ( $inout=='input' ) {
			// Reorder function
			/*
			echo "<td rowspan=\"2\" class=\"testrank\">" .
			    "<a href=\"./testcase.php?probid=" . urlencode($probid) .
			    "&amp;rank=$rank&amp;move=up\">&uarr;</a>$rank" .
			    "<a href=\"./testcase.php?probid=" . urlencode($probid) .
			    "&amp;rank=$rank&amp;move=down\">&darr;</a></td>";
			*/
			echo "<td rowspan=\"2\" class=\"testrank\">$rank</td>";
			
			$type = $row['testcasetype'] ? 'Open' : 'Hidden';
			echo "<td rowspan=\"2\" class=\"testtype\"><center>$type</center></td>";
		}
		echo "<td class=\"filename\"><a href=\"./testcase.php?probid=" .
		    urlencode($probid) . "&amp;rank=$rank&amp;fetch=" . $inout . "\">" .
		    htmlspecialchars($probid) . $rank . "." . substr($inout,0,-3) . "</a></td>" .
		    "<td class=\"testsize\">" . htmlspecialchars($row["size_$inout"]) . "&nbsp;B</td>" .
		    "<td class=\"testmd5\">" . htmlspecialchars($row["md5sum_$inout"]) . "</td>";
		if ( IS_ADMIN ) {
		    echo "<td>" . addFileField("update_".$inout."[$rank]") . "</td>";
		}
		if ( $inout=='input' ) {
			if ( IS_ADMIN ) {
				echo "<td rowspan=\"2\" class=\"testdesc\" onclick=\"editTcDesc($rank)\">" .
				    "<textarea id=\"tcdesc_$rank\" name=\"description[$rank]\" cols=\"50\" rows=\"2\">" .
				    htmlspecialchars($row['description']) . "</textarea></td>";

				// delete both open/hidden testcase
				if ($rank % 2) {
					echo "<td rowspan=\"4\" class=\"editdel\">" .
					    "<a href=\"delete.php?table=testcase&amp;testcaseid=$row[testcaseid]" . 
					    "&amp;referrer=" . urlencode('testcase.php?probid='.$probid) . "\">" .
					    "<img src=\"../images/delete.png\" alt=\"delete\"" .
					    " title=\"delete this testcase\" class=\"picto\" /></a></td>";
				}

				// hide edit field if javascript is enabled
				echo "<script type=\"text/javascript\" language=\"JavaScript\">" .
				    "hideTcDescEdit($rank);</script>";
			} else {
				echo "<td rowspan=\"2\" class=\"testdesc\">" .
				    htmlspecialchars($row['description']) . "</td>";
			}
		}
		echo "</tr>\n";
	}
}

if ( count($data)!=0 ) echo "</tbody>\n</table>\n";

if ( IS_ADMIN ) {
?>
<h3>Create new testcase</h3>

<table>
	<tr><th colspan="2">Open testcase</th>
	<tr><td>Input testdata:</td><td colspan="2"><?php echo addFileField('add_open_input') ?></td></tr>
	<tr><td>Output testdata:</td><td colspan="2"><?php echo addFileField('add_open_output') ?></td></tr>
	<tr><td>Description:</td><td colspan="2"><?php echo addInput('open_add_desc','',30); ?></td></tr>
	<tr><td colspan="3">&nbsp</td></tr>
	<tr><th colspan="2">Hidden testcase</th>
	<tr><td>Input testdata:</td><td colspan="2"><?php echo addFileField('add_hidden_input') ?></td></tr>
	<tr><td>Output testdata:</td><td colspan="2"><?php echo addFileField('add_hidden_output') ?></td></tr>
	<tr><td>Description:</td><td colspan="2"><?php echo addInput('hidden_add_desc','',30); ?></td></tr>
</table>
<?php

	echo "<br />" . addSubmit('Submit all changes') . addEndForm();
}

echo "</div>\n";

require(LIBWWWDIR . '/footer.php');
