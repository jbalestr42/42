#!/usr/bin/php
<?php

function get_data($str)
{
	$c = curl_init($str);
	curl_setopt($c, CURLOPT_RETURNTRANSFER, 1);
	$data = curl_exec($c);
	curl_close($c);
	return $data;
}

if (count($argv) < 2)
	exit();
$text = get_data($argv[1]);

if (preg_match("/<img src=\"(.+)\" .+/", $text, $matches) > 0)
{
	exec("mkdir $argv[1]");
	unset($matches[0]);
	foreach($matches as $m)
	{
		$name = explode("/", $m);
		$fd = fopen($argv[1]."/".end($name), 'w');
		$data = get_data($m);
		fwrite($fd, $data);
		fclose($fd);
	}
}

?>
