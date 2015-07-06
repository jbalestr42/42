<?php

include_once('connect.php');

function getResults ($query) {
	$link = getBase();
	if ($result = mysqli_query($link, $query))
	{
		while ($tab[] = mysqli_fetch_assoc($result))
		{
		}
		mysqli_free_result($result);
		closeBase($link);
		array_pop($tab);
		return ($tab);
	}
}

?>
