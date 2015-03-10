<div class="navbar">
  <div class="navbar-inner">
    <a class="brand" href="index.php">Online Judge</a>
    <ul class="nav">
      <li><a href="index.php">Home</a></li>
      <li><a href="problems.php">Problems</a></li>
      <?php	if ( IS_ADMIN ) { ?>
	  <li><a href="judgehosts.php" accesskey="j">Judgehosts</a></li>
	  <?php   } ?>
	  <li><a href="teams.php" accesskey="t">teams</a></li>
	  <?php	if ( $nunread_clars > 0 ) { ?>
	  <li><a class="new" href="clarifications.php" accesskey="c" id="menu_clarifications">clarifications (<?php echo $nunread_clars?> new)</a></li>
	  <?php	} else { ?>
	  <li><a href="clarifications.php" accesskey="c" id="menu_clarifications">clarifications</a></li>
	  <?php	} ?>
	  <li><a href="submissions.php" accesskey="s">submissions</a></li>
	  <li><a href="scoreboard.php" accesskey="b">scoreboard</a></li>
    </ul>
  </div>
</div>

<div id="menutopright">
<?php

putClock();

$refresh_flag = !isset($_COOKIE["domjudge_refresh"]) || (bool)$_COOKIE["domjudge_refresh"];

if ( isset($refresh) ) {
	echo "<div id=\"refresh\">\n" .
	    addForm('toggle_refresh.php', 'get') .
	    addHidden('enable', ($refresh_flag ? 0 : 1)) .
	    addSubmit(($refresh_flag ? 'Dis' : 'En' ) . 'able refresh', 'submit') .
	    addEndForm() . "</div>\n";
}

echo "</div>\n";
