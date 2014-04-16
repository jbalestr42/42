<?php

include_once('request.php');
startSession();

$_SESSION['login'] = null;
$_SESSION['passwd'] = null;
header("Location: index.php");

?>
