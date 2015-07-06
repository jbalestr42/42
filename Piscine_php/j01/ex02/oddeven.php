#!/usr/bin/php
<?php
$number = 0;
while (42)
{
	echo "Entrez un nombre: ";
	$fd = fopen("php://stdin", "r");
	$number = trim(fgets($fd), " \n");
	if (feof($fd))
		break ;
	if (!is_numeric($number))
		echo "'$number' n'est pas un chiffre\n";
	else if ($number % 2 == 0)
		echo "Le chiffre $number est Pair\n";
	else
		echo "Le chiffre $number est Impair\n";
}
echo "\n";
?>
