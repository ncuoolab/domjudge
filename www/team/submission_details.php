<?php
/**
 * Gives a team the details of a judging of their submission: errors etc.
 *
 * Part of the DOMjudge Programming Contest Jury System and licenced
 * under the GNU GPL. See README and COPYING for details.
 */

require('init.php');

if ( isset($_GET['tid']) && isset($_GET['fetch']) && isset($_GET['md5'])) {
	$tid = $_GET['tid'];
	$fetch = $_GET['fetch'];
	$md5 = $_GET['md5'];
	$data= $DB->q("MAYBETUPLE SELECT OCTET_LENGTH($fetch) AS size, testcasetype, probid, rank
                   FROM testcase WHERE testcaseid = %i AND md5sum_$fetch = %s", $tid, $md5);
	$size = $data['size'];
	$type = $data['testcasetype'];
	$filename = $data['probid'] . $data['rank'] . "." . substr($fetch, 0, -3);

	// Sanity check before we start to output headers
	if ( $type == 0 || $size === NULL || !is_numeric($size))
		error("Problem while fetching open testcase");

	header("Content-Type: application/octet-stream; name=\"$filename\"");
	header("Content-Disposition: inline; filename=\"$filename\"");
	header("Content-Length: $size");

	// This may not be good enough for large testsets, but streaming them
	// directly from the database query result seems overkill to implement.
	echo $DB->q("VALUE SELECT SQL_NO_CACHE $fetch FROM testcase
	             WHERE testcaseid = %i", $tid);

	exit(0);
}

$title = 'Submission details';
require(LIBWWWDIR . '/header.php');

$sid = (int)@$_GET['id'];

// select also on teamid so we can only select our own submissions
$row = $DB->q('MAYBETUPLE SELECT j.judgingid AS jid, p.probid, p.name AS probname, submittime,
               s.valid, l.name AS langname, result, output_compile, verified
               FROM judging j
               LEFT JOIN submission s USING (submitid)
               LEFT JOIN language   l USING (langid)
               LEFT JOIN problem    p ON (p.probid = s.probid)
               WHERE j.submitid = %i AND teamid = %s AND j.valid = 1',$sid,$login);

$testcase_rows = $DB->q('TABLE SELECT testcaseid AS tid, runresult, runtime, rank,
						md5sum_input, md5sum_output, description, testcasetype,
						output_run
					  	FROM judging_run
					  	INNER JOIN `testcase` USING(testcaseid)
					  	WHERE judgingid = %s', $row['jid']);

if( ! $row || (dbconfig_get('verification_required',0) && !$row['verified']) ) {
	echo "<p>Submission not found for this team or not judged yet.</p>\n";
	require(LIBWWWDIR . '/footer.php');
	exit;
}

// update seen status when viewing submission
$DB->q("UPDATE judging j SET j.seen = 1 WHERE j.submitid = %i", $sid);
?>

<div class="mainblock">
<h1>Submission details</h1>

<?php
if( ! $row['valid'] ) {
	echo "<p>This submission is being ignored.<br />\n" .
		"It is not used in determining your score.</p>\n\n";
}
?>

<table>
<tr><td scope="row">Problem:</td>
	<td><?php echo htmlspecialchars($row['probname'])?> [<span class="probid"><?php echo
	htmlspecialchars($row['probid']) ?></span>]</td></tr>
<tr><td scope="row">Submitted:</td>
	<td><?php echo printtime($row['submittime'])?></td></tr>
<tr><td scope="row">Language:</td>
	<td><?php echo htmlspecialchars($row['langname'])?></td></tr>
<tr><td scop="row">Final Result: </td>
	<td><?php echo printresult($row['result'], TRUE)?></td></tr>
</table>

<?php

// Print every runned testcases result

if ( $row['result'] == 'wrong-answer' ) {
	echo '<div class="innerblock">';
	echo '<div class="alert alert-error">';
	echo '<button type="button" class="close" data-dismiss="alert">&times;</button>';
	echo '<strong>Notice!&nbsp</strong>You got a wrong answer.<br>Here provided the open testcase(s) for you to test.';
	echo '</div>';
	echo '</div>';
}

$rowsCount = count($testcase_rows);

for ($i = 0; $i < $rowsCount; $i += 2) { 
	echo "<fieldset><legend>Testcase " . ($i / 2 + 1) . "</legend>";

	// For open testcase block
	$type = $testcase_rows[$i]['testcasetype'] ? 'Open Testcase' : 'Hidden Equivalent Testcase';
	echo "<div class=\"opentestcase\">";
	echo "<div class=\"well\">";
	echo "<center><strong><p>" . $type . "</p></strong></center>";
	if ( !empty($testcase_rows[$i]['description']) ) {
		echo "<p>Description : " . $testcase_rows[$i]['description'] . "</p>";
	}
	echo "<p>Runtime : " . $testcase_rows[$i]['runtime'] . " sec</p>";
	echo "<p>Result : " . printresult($testcase_rows[$i]['runresult'], TRUE) . "</p>";

	if ( $testcase_rows[$i]['runresult'] == 'wrong-answer' OR
		 $testcase_rows[$i + 1]['runresult'] == 'wrong-answer') {
		
		$tid = $testcase_rows[$i]['tid'];
		echo "<p>Download :\t<a href=\"./submission_details.php?tid=" . urlencode($tid) . 
			 "&amp;fetch=input&amp;md5=". $testcase_rows[$i]['md5sum_input'] . "\">Input</a> / " . 
		 	 "<a href=\"./submission_details.php?tid=" . urlencode($tid) . 
		 	 "&amp;fetch=output&amp;md5=". $testcase_rows[$i]['md5sum_output'] . "\">Output</a></p>";

		if ( strlen(@$testcase_rows[$i]['output_run']) > 0 ) {
			echo "<center><button id=\"watch\" type=\"button\" class=\"btn btn-mini btn-link\" data-toggle=\"button\" onclick=\"javascript:toggleOutput('output_run_$i')\">" . 
				 "Click to watch the program output</button></center>";
			echo "<pre id=\"output_run_$i\" class=\"output_run\">\n". htmlspecialchars(@$testcase_rows[$i]['output_run'])."\n</pre>\n\n";
		}
	}

	echo "</div>";
	echo "</div>";

	// For hidden testcase block
	$type = $testcase_rows[$i + 1]['testcasetype'] ? 'Open Testcase' : 'Hidden Equivalent Testcase';
	echo "<div class=\"hiddentestcase\">";
	echo "<div class=\"well\">";
	echo "<center><strong><p>" . $type . "</p></strong></center>";
	if ( !empty($testcase_rows[$i]['description']) ) {
		echo "<p>Description : " . $testcase_rows[$i + 1]['description'] . "</p>";
	}
	echo "<p>Runtime : " . $testcase_rows[$i + 1]['runtime'] . " sec</p>";
	echo "<p>Result : " . printresult($testcase_rows[$i + 1]['runresult'], TRUE) . "</p>";
	echo "</div>";
	echo "</div>";

	echo "</fieldset>";
	echo "<br>";
}

$show_compile = dbconfig_get('show_compile', 2);

if ( ( $show_compile == 2 ) ||
     ( $show_compile == 1 && $row['result'] == 'compiler-error') ) {

	echo "<h2>Compilation output</h2>\n\n";

	if ( strlen(@$row['output_compile']) > 0 ) {
		echo "<pre class=\"output_text\">\n".
			htmlspecialchars(@$row['output_compile'])."\n</pre>\n\n";
	} else {
		echo "<p class=\"nodata\">There were no compiler errors or warnings.</p>\n";
	}

	if ( $row['result'] == 'compiler-error' ) {
		echo "<p class=\"compilation-error\">Compilation failed.</p>\n";
	} else {
		echo "<p class=\"compilation-success\">Compilation successful.</p>\n";
	}
} else {
	echo "<p class=\"nodata\">Compilation output is disabled.</p>\n";
}

echo "</div>";

require(LIBWWWDIR . '/footer.php');
