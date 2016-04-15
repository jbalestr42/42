<?php

include_once('request.php');
startSession();

if (isset($_POST['login']) && isset($_POST['passwd']))
{
	if (auth($_POST['login'], hash("whirlpool", mysql_real_escape_string($_POST['passwd']))) == 1)
	{
		$_SESSION['login'] = $_POST['login'];
		$_SESSION['passwd'] = hash("whirlpool", mysql_real_escape_string($_POST['passwd']));
	}
}
redirect_prev();
?>
