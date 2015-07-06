<?php

function getBase () {
	if (file_exists(".credentials"))
	{
		$user = explode("\n", file_get_contents(".credentials"));
		$link = mysqli_connect('localhost', $user[0], $user[1], 'awesomestarshipbattle2');
		if (!$link)
			die('Erreur de connexion ('.mysqli_connect_errno().') '.mysqli_connect_error());
		return ($link);
	}
	die('No credential found !\n');
}

function closeBase($link)
{
	mysqli_close($link);
}

?>
