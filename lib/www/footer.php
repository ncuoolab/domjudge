<?php
/**
 * Common page footer
 */ 
if (!defined('DOMJUDGE_VERSION')) die("DOMJUDGE_VERSION not defined.");

if ( DEBUG & DEBUG_TIMINGS ) {
	echo "<p>"; totaltime(); echo "</p>";
} ?>

<script src="../bootstrap/js/bootstrap-filestyle.min.js"></script>
</body>
</html>
