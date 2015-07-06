<?php
include('request.php');
session_start();

function redirect () {
	header("Location: index.php");
}

if (getLevel($_SESSION['login']) < 10)
	redirect();

if (!isset($_GET['table'])
	|| !in_array($_GET['table'], array('articles', 'categories'))
	|| !isset($_GET['id'])
	|| !is_numeric($_GET['id']))
	redirect();

exec_query("DELETE FROM `".$_GET['table']."` WHERE id = ".$_GET['id']);

if (isset($_SERVER['HTTP_REFERER']))
{
	$last = end(explode("/", $_SERVER['HTTP_REFERER']));
	header("Location: $last");
}
else
	header("Location: index.php");

?>
