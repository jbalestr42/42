#!/usr/bin/php
<?php

function get_param($name)
{
	if (!file_exists($name))
		exit();
	if (($handle = fopen($name, "r")) !== FALSE)
	{
		if (($data = fgetcsv($handle, 0, ";")) !== FALSE)
		{
			fclose($handle);
			return ($data);
		}
		fclose($handle);
	}
	else
		exit();
	return (0);
}

if (count($argv) != 3)
	exit();
$header = get_param($argv[1]);

$key = 0;
foreach ($header as $h)
{
	if ($h == $argv[2])
	{
		break ;
	}
	$key++;
}
if ($key == count($header))
	exit();

if (($handle = fopen($argv[1], "r")) !== FALSE)
{
	while (($data = fgetcsv($handle, 0, ";")) !== FALSE)
	{
		$nom[$data[$key]] = $data[0];
		$prenom[$data[$key]] = $data[1];
		$mail[$data[$key]] = $data[2];
		$IP[$data[$key]] = $data[3];
		$pseudo[$data[$key]] = $data[4];
	}
	fclose($handle);
}

while (42)
{
	echo "Entrez votre commande: ";
	$fd = fopen("php://stdin", "r");
	$line = fgets($fd);
	if (feof($fd))
		break ;
	eval($line);
}
echo "\n";

?>
