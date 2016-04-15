<?php
include_once('request.php');
session_start();
addChat($_SESSION['login'], $_POST['message']);

header('Location: lobby.php');

?>
