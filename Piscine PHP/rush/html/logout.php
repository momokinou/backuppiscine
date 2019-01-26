<?php

if (isset($_SESSION))
	echo "<div style=\"display: none\" id=\"logout_flag\">OUI</div>";
include("./index.php");
if (isset($_SESSION))
{
	foreach($_SESSION as $key => $value)
		$_SESSION[$key] = NULL;
}

?>