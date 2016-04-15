#!/usr/bin/php
<?php

if (count($argv) > 2)
{
	$val = "0";
	$i = 0;
	$b = 0;
	foreach ($argv as $a)
	{
		if ($i < 2)
			$i++;
		else
		{
			$val = explode(":", $a);
			if ($val[0] == $argv[1])
			{
				$b = 1;
				$val = $val[1];
			}
		}
	}
	if ($b)
		echo $val."\n";
}

?>
