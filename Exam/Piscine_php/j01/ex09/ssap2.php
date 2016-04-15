#!/usr/bin/php
<?php

$str = implode(" ", $argv);
$str = explode(" ", $str);
$str = array_filter($str, 'strlen');
unset($str[0]);
foreach ($str as $s)
{
	if (ctype_alpha($s[0]))
		$alpha[] = $s;
	else if (is_numeric($s[0]))
		$num[] = $s;
	else
		$spec[] = $s;
}
if ($alpha)
	natcasesort($alpha);
if ($num)
	sort($num, SORT_STRING);
if ($spec)
	natcasesort($spec);
$str = array_merge((array)$alpha, (array)$num, (array)$spec);
foreach ($str as $s)
	echo $s."\n";

?>
