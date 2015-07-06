<?php

function ft_split($str)
{
	$tab = explode(" ", $str);
	$tab = array_filter($tab, 'strlen');
	sort($tab, SORT_REGULAR);
	return ($tab);
}

?>
