<nav>
<?php

if (isset($_GET['posx']) && isset($_GET['posy']))
{
	$x = ($_GET['posx'] - 399) / 14;
	$y = ($_GET['posy'] - 241) / 14;
	if (isset($_SESSION['board']))
	{
		$game = $_SESSION['board'];
		foreach ($game->getPlayer() as $p)
		{
			foreach ($p->getFleet() as $s)
			{
				$pos = $s->getPos();
				if ($pos['x'] / 14 == $x && $pos['y'] / 14 == $y)
				{
					echo "Vaisseau de ".$p->getLogin()."<br>";
					echo $s->getName()."<br>";
					echo "pv : ".$s->getPv()."<br>";
					echo "pp : ".$s->getPp()."<br>";
					if (isset($_POST['top']))
						$s->turn("top");
					else if (isset($_POST['left']))
						$s->turn('left');
					else if (isset($_POST['right']))
						$s->turn('right');
					else if (isset($_POST['bot']))
						$s->turn('bot');
					else if (isset($_POST['go']))
						;
					$_SESSION['board'] = $game;
					?>
					<form method="post">
						<input class="btn" type="submit" name="top" value="^" /><br>
						<input class="btn" type="submit" name="left" value="<" />
						<input class="btn" type="submit" name="right" value=">" /><br>
						<input class="btn" type="submit" name="bot" value="v" /><br>
						<input class="btn" type="submit" name="go" value="Avancer" />
					</form>
					<?php break;
				}
			}
		}
	}
}

?>
</nav>
