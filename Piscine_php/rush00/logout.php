<?php

session_start();
$_SESSION['login'] = null;
$_SESSION['passwd'] = null;
if (isset($_SERVER['HTTP_REFERER']))
{
	$last = end(explode("/", $_SERVER['HTTP_REFERER']));
	if ($last == "admin.php")
		header("Location: index.php");
	else
		header("Location: $last");
}
else
	header("Location: index.php");

?>
