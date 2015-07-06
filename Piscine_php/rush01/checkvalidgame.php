<?php

include_once('request.php');
session_start();

if (isset($_GET['gameid']) && isset($_SESSION['login']))
{
	if (canLaunchGame($_GET['gameid']))
	{
		echo "Game will launch !<br>";
		updateGameInProgress($_SESSION['login'], $_GET['gameid']);
	}
}

?>
