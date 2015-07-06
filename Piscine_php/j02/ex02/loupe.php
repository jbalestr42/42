#!/usr/bin/php
<?php

function replace_title($tab)
{
	return preg_replace("/$tab[2]/", strtoupper($tab[2]), $tab[0]);
}

function replace($tab)
{
	$tab[0] = preg_replace("/$tab[3]/", strtoupper($tab[3]), $tab[0]);
	$tab[0] = preg_replace("/$tab[7]/", strtoupper($tab[7]), $tab[0]);
	$tab[0] = preg_replace("/$tab[4]/", strtolower($tab[4]), $tab[0]);
	return preg_replace("/$tab[5]/", strtoupper($tab[5]), $tab[0]);
}

function replace_sp($tab)
{
	return preg_replace("/$tab[2]/", strtoupper($tab[2]), $tab[0]);
}

if (count($argv) < 2)
	exit();
$lines = file_get_contents($argv[1]);
$tab = preg_replace_callback("/(<a href=.+>(.+)<\/a>)/U", "replace_sp", $lines);
$tab = preg_replace_callback("/(<a href=.+>((.*)(<.*>)(.*))*<\/a>)/U", "replace", $tab);
$tab = preg_replace_callback("/(.*)title=\"(.+)\"/", "replace_title", $tab);
echo $tab;

?>
