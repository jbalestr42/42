#!/usr/bin/php
<?php

if (count($argv) < 2)
	exit();
$tab = preg_filter("/[ \t]+/", " ", $argv[1]);
echo $tab."\n";
?>
