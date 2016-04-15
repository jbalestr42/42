<?php

if ($_GET['action'] == "set")
	setcookie($_GET['name'], $_GET['value'], time() + 60 * 60 * 24 * 30);
else if ($_GET['action'] == "get")
{
	$tmp = $_COOKIE[$_GET['name']];
	if ($tmp)
		echo $tmp."\n";
}
else if ($_GET['action'] == "del")
	setcookie($_GET['name'], "", time() - 1);

?>
