#!/usr/bin/php
<?php
if (count($argv) > 1)
{
	$i = 0;
	$tab = explode(" ", $argv[1]);
	$tab = array_filter($tab, 'strlen');
	foreach ($tab as $t)
	{
		if ($i != 0)
			echo "$t ";
		else
		{
			$tmp = $t;
			$i = 1;
		}
	}
	echo $tmp."\n";
}
?>
