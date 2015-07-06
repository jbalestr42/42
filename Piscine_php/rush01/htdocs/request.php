<?php

include_once('connect.php');

function startSession()
{
	if (!$_SESSION)
		session_start();
}

function getResults ($query) {
	$link = getBase();
	if ($result = mysqli_query($link, $query))
	{
		while ($tab[] = mysqli_fetch_assoc($result))
		{
		}
		mysqli_free_result($result);
		closeBase($link);
		array_pop($tab);
		return ($tab);
	}
}

function escape_str ($str) {
	$link = getBase();
	$res = mysqli_real_escape_string($link, $str);
	closeBase($link);
	return $str;
}

function create_user($login, $passwd)
{
	$link = getBase();
	$login = escape_str($login);
	$passwd = hash("whirlpool", escape_str($passwd));
	$res = getResults("SELECT * FROM users WHERE login='$login'");
	if (count($res) != 0)
		return (-1);
	mysqli_query($link, "INSERT INTO `users` (`login`, `password`) VALUES ('$login', '$passwd')");
	closeBase($link);
}

function exec_query($query) {
	$ret = true;
	$link = getBase();
	$ret = mysqli_query($link, $query);
	closeBase($link);
	return (!$ret ? false : true);
}

function auth($login, $passwd)
{
	$login = escape_str($login);
	$res = getResults("SELECT * FROM users WHERE login='$login'");
	foreach ($res as $user)
	{
		if ($user['password'] == $passwd)
			return (1);
	}
	return (-1);
}

function update_pwd($login, $oldpwd, $newpwd)
{
	$login = escape_str($login);
	$res = getResults("SELECT * FROM users WHERE login='$login'");
	foreach ($res as $user)
	{
		if ($user['password'] == $oldpwd)
		{
			exec_query("UPDATE users SET password='$newpwd' WHERE login='$login'");
			return (1);
		}
	}
	return (-1);
}

function canCreateGame($login)
{
	$login = escape_str($login);
	$res = getResults("SELECT * FROM users WHERE login='$login'");
	foreach ($res as $user)
	{
		if ($user['login'] == $login)
		{
			if ($user['status'] == 'NONE')
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

function create_game($name, $login)
{
	$link = getBase();
	$login = escape_str($login);
	mysqli_query($link, "UPDATE users SET status='LOBBY' WHERE login='$login'");
	mysqli_query($link, "INSERT INTO `games` (`name`, `players`) VALUES ('$name', '$login')");
	closeBase($link);
}

function withdrawPlayerFromGame($login, $id)
{
	$link = getBase();
	$login = escape_str($login);
	$res = getResults("SELECT * FROM games WHERE id='$id'");
	foreach ($res as $games)
	{
		$p = explode(";", $games['players']);
		$new = array();
		foreach ($p as $player)
		{
			if ($player != $login)
				$new[] = $player;
		}
	}
	mysqli_query($link, "UPDATE users SET status='NONE' WHERE login='$login'");
	if (count($new) == 0)
		mysqli_query($link, "UPDATE games SET status='FINISHED' WHERE id='$id'");
	else
		mysqli_query($link, "UPDATE games SET players='".implode(";", $new)."' WHERE id='$id'");
	closeBase($link);
}

function joinGame($login, $id)
{
	$link = getBase();
	$login = escape_str($login);
	$res = getResults("SELECT * FROM games WHERE id='$id'");
	if (isset($res[0]))
	{
		$p = explode(";", $res[0]['players']);
		if (count($p) < 2)
		{
			$p[] = $login;
			mysqli_query($link, "UPDATE users SET status='LOBBY' WHERE login='$login'");
			mysqli_query($link, "UPDATE games SET players='".implode(";", $p)."' WHERE id='$id'");
		}
	}
	closeBase($link);
}

function getGames()
{
	$res = getResults("SELECT * FROM games WHERE status='NONE'");
	return $res;
}

function canLaunchGame($id)
{
	$res = getResults("SELECT * FROM games WHERE id='$id'");
	if (isset($res[0]))
	{
		$p = explode(";", $res[0]['players']);
		if (count($p) == 2 && $res[0]['status'] == 'NONE')
			return (1);
	}
	return (0);
}

function playerIsInGame($login)
{
	$res = getResults("SELECT * FROM users WHERE login='$login'");
	if (isset($res[0]))
	{
		if ($res[0]['status'] == 'GAME')
			return (1);
	}
	return (0);
}

function updateGameInProgress($login, $id)
{
	$link = getBase();
	mysqli_query($link, "UPDATE games SET status='INPROGRESS' WHERE id='$id'");
	$res = getResults("SELECT * FROM games WHERE id='$id'");
	if (isset($res[0]))
	{
		$p = explode(";", $res[0]['players']);
		foreach ($p as $player)
			mysqli_query($link, "UPDATE users SET status='GAME' WHERE login='".$player."'");
	}
	closeBase($link);
}

function getChat()
{
	$res = getResults("SELECT pseudo, message FROM chat ORDER BY ID DESC LIMIT 0, 10");
	return $res;
}

function addChat($login, $message)
{
	$link = getBase();
	mysqli_query($link, "INSERT INTO `chat` (`pseudo`, `message`) VALUES ('$login', '$message')");
	closeBase($link);
}

function redirect_prev()
{
	if (!isset($_SESSION))
		session_start();
	if (isset($_SERVER['HTTP_REFERER']))
	{
		$last = end(explode("/", $_SERVER['HTTP_REFERER']));
		header("Location: $last");
	}
	else
		header("Location: index.php");
}

?>
