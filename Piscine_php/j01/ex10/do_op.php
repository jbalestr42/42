#!/usr/bin/php
<?php

$res = 0;
if (count($argv) != 4)
	echo "Incorrect Parameters\n";
else
{
	if (trim($argv[2]) == "+")
		$res = trim($argv[1]) + trim($argv[3]);
	if (trim($argv[2]) == "-")
		$res = trim($argv[1]) - trim($argv[3]);
	if (trim($argv[2]) == "*")
		$res = trim($argv[1]) * trim($argv[3]);
	if (trim($argv[2]) == "/")
		$res = trim($argv[1]) / trim($argv[3]);
	if (trim($argv[2]) == "%")
		$res = trim($argv[1]) % trim($argv[3]);
	echo $res."\n";
}

?>
