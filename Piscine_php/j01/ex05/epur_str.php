#!/usr/bin/php
<?php
if (count($argv) > 1)
{
	$i = 0;
	$tab = explode(" ", $argv[1]);
	$tab = array_filter($tab, 'strlen');
	foreach ($tab as $t)
	{
		echo "$t";
		$i = $i + 1;;
		if ($i != count($tab))
			echo " ";
	}
	echo "\n";
}
?>
