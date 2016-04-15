<?php
include_once('lib.php');

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
	mysqli_query($link, "INSERT INTO `users` (`login`, `password`, `level`) VALUES ('$login', '$passwd', 1)");
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

function getLevel($login)
{
	$login = escape_str($login);
	$res = getResults("SELECT * FROM users WHERE login='$login'");
	foreach ($res as $user)
	{
		if ($user['login'] == $login)
			return ($user['level']);
	}
	return (1);
}

function create_product($product)
{
	$ret = true;
	$link = getBase();
	$name = escape_str($product['name']);
	$price = escape_str($product['price']);
	$description = escape_str($product['description']);
	$category_id = escape_str($product['category_id']);
	$image_url = escape_str($product['image_url']);
	$ret = mysqli_query($link, "INSERT INTO `articles` (`name`, `price`, `category_id`, `description`, `image_url`) VALUES ('$name', '$price', $category_id, '$description', '$image_url')");
	closeBase($link);
	return (!$ret ? false : true);
}

function update_categ($categ)
{
	$ret = true;
	$link = getBase();
	$id = escape_str($categ['id']);
	$name = escape_str($categ['name']);
	$ret = mysqli_query($link, "
		UPDATE `categories`
		SET `name` = '$name'
		WHERE id = $id");
	closeBase($link);
	return (!$ret ? false : true);
}

function update_user($user)
{
	$ret = true;
	$link = getBase();
	$id = escape_str($user['id']);
	$login = escape_str($user['login']);
	$level = escape_str($user['level']);
	$ret = mysqli_query($link, "
		UPDATE `users`
		SET `login` = '$login',
		`level` = $level
		WHERE id = $id");
	closeBase($link);
	return (!$ret ? false : true);
}

function update_article($article)
{
	$ret = true;
	$link = getBase();
	$id = escape_str($article['id']);
	$name = escape_str($article['name']);
	$price = escape_str($article['price']);
	$description = escape_str($article['description']);
	$category_id = escape_str($article['category_id']);
	$image_url = escape_str($article['image_url']);
	$ret = mysqli_query($link, "
		UPDATE `articles`
		SET `name` = '$name',
		`price` = $price,
		`category_id` = $category_id,
		`description` = '$description',
		`image_url` = '$image_url'
		WHERE id = $id");
	closeBase($link);
	return (!$ret ? false : true);
}

function create_category($product)
{
	$ret = true;
	$link = getBase();
	$name = escape_str($product['name']);
	$ret = mysqli_query($link, "INSERT INTO `categories` (`name`) VALUES ('$name')");
	closeBase($link);
	return (!$ret ? false : true);
}

function redirect_prev()
{
	if (!isset($_SESSION))
		session_start();
	if (isset($_SERVER['HTTP_REFERER']))
	{
		$last = end(explode("/", $_SERVER['HTTP_REFERER']));
		if ($last == "signup.php")
			header("Location: index.php");
		else
			header("Location: $last");
	}
	else
		header("Location: index.php");
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

function get_user_by_id($id)
{
	$res = getResults("SELECT * FROM users WHERE id='$id'");
	if (count($res) > 0)
		return ($res[0]);
	return (0);
}

function get_price_by_id($id)
{
	$res = getResults("SELECT * FROM articles WHERE id='$id'");
	if (count($res) > 0)
		return ($res[0]['price']);
	return (0);
}

function add_order($login, $cart)
{
	$user = getResults("SELECT * FROM users WHERE login='$login'");
	$tmp = array();
	foreach ($cart as $i => $c)
	{
		$c['price'] = get_price_by_id($i);
		$tmp[] = $c;
	}
	date_default_timezone_set("Europe/Paris");
	if (count($user) > 0)
		exec_query("INSERT INTO `orders` (`user_id`, `content`, `date`) VALUES ('".$user[0]['id']."', '".serialize($tmp)."', '".date("Y-m-d H:i:s")."')");
}

function get_orders()
{
	$orders = getResults("SELECT * FROM orders");
	return ($orders);
}

?>
