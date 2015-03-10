<?php
/**
 * Part of the DOMjudge Programming Contest Jury System and licenced
 * under the GNU GPL. See README and COPYING for details.
 */

require('init.php');
$title = htmlspecialchars($teamdata['name']);

// Download problem file
if ( isset($_GET['fetch']) && isset($_GET['probid']) ) {
	downloadProblemZIP($_GET['probid'], true);
	exit(0);
}

require(LIBWWWDIR . '/header.php');
require(LIBWWWDIR . '/forms.php');

// Don't use HTTP meta refresh, but javascript: otherwise we cannot
// cancel it when the user starts editing the submit form. This also
// provides graceful degradation without javascript present.
$refreshtime = 60;

$submitted = @$_GET['submitted'];

$fdata = calcFreezeData($cdata);

echo "<script type=\"text/javascript\">\n<!--\n";

if ( ENABLE_WEBSUBMIT_SERVER && $fdata['cstarted'] ) {
	$probdata = $DB->q('KEYVALUETABLE SELECT probid, name FROM problem
						WHERE cid = %i AND allow_submit = 1
						ORDER BY probid', $cid);

	echo "function getMainExtension(ext)\n{\n";
	echo "\tswitch(ext) {\n";
	foreach($langexts as $ext => $langid) {
		echo "\t\tcase '" . $ext . "': return '" . $langid . "';\n";
	}
	echo "\t\tdefault: return '';\n\t}\n}\n\n";

	echo "function getProbDescription(probid)\n{\n";
	echo "\tswitch(probid) {\n";
	foreach($probdata as $probid => $probname) {
		echo "\t\tcase '" . htmlspecialchars($probid) . "': return '" . htmlspecialchars($probname) . "';\n";
	}
	echo "\t\tdefault: return '';\n\t}\n}\n\n";
}

echo "initReload(" . $refreshtime . ");\n";
echo "// -->\n</script>\n";

// Put overview of team submissions (like scoreboard)
//putTeamRow($cdata, array($login));

echo "<div id=\"submitlist\">\n";

echo "<h1>Submissions</h1>\n\n";

if ( ENABLE_WEBSUBMIT_SERVER && $fdata['cstarted'] ) {
	echo addForm('upload.php','post',null,'multipart/form-data', null, ' onreset="resetUploadForm('.$refreshtime .');"');
	echo "<div id=\"submitform\">\n\n";
	echo "<span class=\"fileinputs\">\n\t";
	echo '<input type="file" class="filestyle" data-buttontext="Upload" data-classInput="input-medium" name="code[]" multiple>';
	echo "</span>";

	// Customize button style as well as setting up auto detect
	echo "<script type=\"text/javascript\">window.addEventListener('load', initFileUploads);</script>\n\n";

	$probs = array();
	foreach($probdata as $probid => $dummy) {
		$probs[$probid] = $probid;
	}
	$probs[''] = 'select problem';
	echo addSelect('probid', $probs, '', true);
	$langs = $DB->q('KEYVALUETABLE SELECT langid, name FROM language
			 WHERE allow_submit = 1 ORDER BY name');
	$langs[''] = 'select language';
	echo addSelect('langid', $langs, '', true);

	echo addSubmit('submit', 'submit', "return checkUploadForm();");

	echo addReset('cancel');

	echo "</div>";

	
	if ( dbconfig_get('sourcefiles_limit',100) > 1 ) {
		echo "<span id=\"auxfiles\"></span>\n" .
			"<span class=\"upload_btn\">" .
		  "<input type=\"button\" class=\"btn\" name=\"addfile\" id=\"addfile\" " .
		  "value=\"Add another source file\" onclick=\"addFileUpload();\" />\n" .
		  "</span>\n";
	}

	echo "</p>\n</form>\n\n";
}
// call putSubmissions function from common.php for this team.
$restrictions = array( 'teamid' => $login );
putSubmissions($cdata, $restrictions, null, $submitted);

echo "</div>\n\n";

echo "<div id=\"clarlist\">\n";
/*
$requests = $DB->q('SELECT * FROM clarification
                    WHERE cid = %i AND sender = %s
                    ORDER BY submittime DESC, clarid DESC', $cid, $login);

$clarifications = $DB->q('SELECT c.*, u.type AS unread FROM clarification c
                          LEFT JOIN team_unread u ON
                          (c.clarid=u.mesgid AND u.type="clarification" AND u.teamid = %s)
                          WHERE c.cid = %i AND c.sender IS NULL
                          AND ( c.recipient IS NULL OR c.recipient = %s )
                          ORDER BY c.submittime DESC, c.clarid DESC',
                          $login, $cid, $login);
*/

$problems = $DB->q('TABLE SELECT probid, cid, allow_submit, color, prob_file, OCTET_LENGTH(prob_file) AS size FROM problem
										WHERE cid = %i AND allow_submit = 1', $cid);

echo "<h1>Problem Overview</h1>\n";

if ( $problems == NULL ) {
	echo "<p class=\"nodata\">No problems.</p>\n\n";
} else {
	echo "<table class=\"table table-hover\">\n<thead>\n<tr>" . 
		 "<th scope=\"col\">problem</th>" . 
		 "<th scope=\"col\">file</th>" . 
	     "</tr>\n</thead>\n<tbody>";

	foreach ($problems as $prob) {
		echo "<tr><td>$prob[probid]</td><td>";

		if ( $prob['size'] !== NULL ) {
			echo "<a href=\"./index.php?fetch=prob_file&amp;probid=$prob[probid]\">Download</a>";
		} else {
			echo "<a>N/A</a>";
		}

		echo "</td></tr>";
	}

	echo "</tbody></table>";
}

echo "<br><br>";

/*
echo "<h1>Clarifications</h1>\n";

# FIXME: column width and wrapping/shortening of clarification text 
if ( $clarifications->count() == 0 ) {
	echo "<p class=\"nodata\">No clarifications.</p>\n\n";
} else {
	putClarificationList($clarifications,$login);
}

echo "<br><br>";
echo "<h1>Clarification Requests</h1>\n";

if ( $requests->count() == 0 ) {
	echo "<p class=\"nodata\">No clarification requests.</p>\n\n";
} else {
	putClarificationList($requests,$login);
}
*/
echo "</div>\n";

require(LIBWWWDIR . '/footer.php');
