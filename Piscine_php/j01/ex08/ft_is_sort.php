<?php

function ft_is_sort($str)
{
	$tab = $str;
	$rtab = $str;
	sort($tab);
	rsort($rtab);
	if ($tab == $str || $rtab = $str)
		return (1);
	return (0);
}

?>
