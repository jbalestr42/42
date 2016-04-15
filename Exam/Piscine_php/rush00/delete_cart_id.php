<?php
include('request.php');
if (!isset($_SESSION))
	session_start();

if (isset($_GET['id']) && isset($_SESSION['cart'][$_GET['id']]))
{
	unset($_SESSION['cart'][$_GET['id']]);
	redirect_prev();
}

?>
