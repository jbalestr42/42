#!/usr/bin/php
<?php

function match_array($array, $elem)
{
	foreach($array as $a)
	{
		if (preg_match("/".$a."/", $elem))
			return (array_search($a, $array));
	}
	return (-1);
}

if (count($argv) < 2)
	exit();
$day = array("[lL]undi", "[mM]ardi", "[mM]ercredi", "[jJ]eudi", "[vV]endredi", "[sS]amedi", "[dD]imanche");
$month = array("01" => "[jJ]anvier", "02" => "[fF][eé]vrier", "03" => "[mM]ars", "04" => "[aA]vril", "05" => "[mM]ai", "06" => "[jJ]uin", "07" => "[jJ]uillet", "08" => "[aA]oi[uû]t", "09" => "[sS]eptembre", "10" => "[oO]ctobre", "11" => "[nN]ovembre", "12" => "[dD][ée]cembre");
$days = implode("|", array_values($day));
$months = implode("|", array_values($month));
if (preg_match("/^(".$days.") [1-3]?[0-9] (".$months.") [0-9]{4} [0-9]{2}:[0-9]{2}:[0-9]{2}$/", $argv[1]) == 1)
{
	$split = preg_split("/ /", $argv[1]);
	$date = $split[3].":".match_array($month, $split[2]).":".$split[1]." ".$split[4];
	date_default_timezone_set("Europe/Paris");
	$time = strtotime($date);
	$verif = date("Y:m:d G:i:s", $time);
	if (!empty($date) && $verif == $date)
		echo $time."\n";
	else
		echo "Wrong Format\n";
}

?>
