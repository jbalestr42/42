#!/usr/bin/php
<?php

function op($v1, $v2, $v3)
{
	if ($v2 == "+")
		$res = $v1 + $v3;
	if ($v2 == "-")
		$res = $v1 - $v3;
	if ($v2 == "*")
		$res = $v1 * $v3;
	if ($v2 == "/")
		$res = $v1 / $v3;
	if ($v2 == "%")
		$res = $v1 % $v3;
	echo $res."\n";
}

function valid_op($c)
{
	if ($c == "+" || $c == "-" || $c == "/" || $c == "*" || $c == "%")
		return (1);
	return (0);
}

function valid_char($c)
{
	if (is_numeric($c))
		return (1);
	return (valid_op($c));
}

function check_syntax($str)
{
	$i = 0;
	$tmp = explode(" ", $str);
	$tmp = array_filter($tmp, 'strlen');
	if (count($tmp) > 3)
		return (0);
	while ($i < strlen($str) && $str[$i] != " ")
	{
		if (!valid_char($str[$i]))
			return (0);
		if (is_numeric($str[$i]))
			$i++;
		else
			break ;
	}
	$v1 = substr($str, 0, $i);
	while ($i < strlen($str))
	{
		if ($str[$i] == " ")
			$i++;
		else
			break ;
	}
	if (!valid_op($str[$i]))
		return (0);
	$v2 = $str[$i];
	$i++;
	while ($i < strlen($str))
	{
		if ($str[$i] == " ")
			$i++;
		else
			break ;
	}
	$start = $i;
	while ($i < strlen($str))
	{
		if (!valid_char($str[$i]))
			return (0);
		if (is_numeric($str[$i]))
			$i++;
		else
			break ;
	}
	$v3 = substr($str, $start, $i);
	while ($i < strlen($str))
	{
		if (!valid_char($str[$i]))
			return (0);
		$i++;
	}
	op($v1, $v2, $v3);
	return (1);
}

$res = 0;
if (count($argv) != 2)
	echo "Incorrect Parameters\n";
else
{
	if (!check_syntax(trim($argv[1])))
		echo "Syntax Error\n";
}

?>
