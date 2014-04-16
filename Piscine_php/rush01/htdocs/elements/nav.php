<?php

$route = "$_SERVER[REQUEST_URI]";

function classIf ($el) {
	global $route;
	if ($el === $route)
		echo ' class="active"';
}

?>
<nav>
	<ul>
		<li<?php classIf('/index.php'); ?>><a href="index.php"><i class="icon-home"></i> Accueil</a></li>
		<li<?php classIf('/ladder.php'); ?>><a href="ladder.php"><i class="icon-menu"></i> Ladder</a></li>
		<?php
		include_once('request.php');
		if (isset($_SESSION['login']) && isset($_SESSION['passwd']))
		{
			if (auth($_SESSION['login'], $_SESSION['passwd']) == 1)
			{?>
				<li<?php classIf('/lobby.php'); ?>><a href="lobby.php"><i class="icon-tree"></i> Lobby</a></li>
			<?php }
		}?>
	</ul>
</nav>
