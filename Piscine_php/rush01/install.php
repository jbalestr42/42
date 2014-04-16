#!/usr/bin/php
<?php

include_once('connect.php');

if ($argc < 3)
{
	echo "./install.php login password\n";
	exit();
}

$user = $argv[1];
$pwd = $argv[2];

file_put_contents(".credentials", "$user\n$pwd");
$link = mysqli_connect('127.0.0.1', $user, $pwd);

if (!$link)
	die('Erreur de connexion ('.mysqli_connect_errno().') '.mysqli_connect_error());

if(mysqli_query($link, "CREATE DATABASE IF NOT EXISTS `awesomestarshipbattle2` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;"))
	echo "Executing query...\n";
if(mysqli_query($link, "USE `awesomestarshipbattle2`;"))
	echo "Executing query...\n";

if(mysqli_query($link, "DROP TABLE IF EXISTS `chat`;"))
	echo "Executing query...\n";
if(mysqli_query($link, "CREATE TABLE IF NOT EXISTS `chat` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `pseudo` varchar(255) NOT NULL,
  `message` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;"))
	echo "Executing query...\n";

if(mysqli_query($link, "INSERT INTO `chat` (`id`, `pseudo`, `message`) VALUES
(3, 'admin', 'Welcome :)');"))
	echo "Executing query...\n";

if(mysqli_query($link, "DROP TABLE IF EXISTS `games`;"))
	echo "Executing query...\n";
if(mysqli_query($link, "CREATE TABLE IF NOT EXISTS `games` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL DEFAULT 'new game',
  `players` varchar(255) NOT NULL,
  `status` enum('NONE','INPROGRESS','FINISHED') NOT NULL DEFAULT 'NONE',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=52 ;"))
	echo "Executing query...\n";

if(mysqli_query($link, "DROP TABLE IF EXISTS `users`;"))
	echo "Executing query...\n";
if(mysqli_query($link, "CREATE TABLE IF NOT EXISTS `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `login` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `ladder` int(11) NOT NULL DEFAULT '1000',
  `status` enum('NONE','LOBBY','GAME') NOT NULL DEFAULT 'NONE',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=18 ;"))
	echo "Executing query...\n";

?>
