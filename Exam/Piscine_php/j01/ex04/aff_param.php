#!/usr/bin/php
<?php

$i = 0;
foreach ($argv as $a)
{
	if ($i == 0)
		$i = 1;
	else
		echo $a."\n";
}

?>
