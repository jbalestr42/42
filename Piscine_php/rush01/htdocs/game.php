<?php
include_once('game/Board.class.php');
include_once('game/Player.class.php');
include_once('game/HonorableDuty.class.php');
include_once('request.php');
session_start();
 $_SESSION['is_init'] = 0;
if (isset($_SESSION['is_init']) && $_SESSION['is_init'] == 0 && isset($_SESSION['login']))
{
	$_SESSION['is_init'] = 1;
	$game = new Board();
	$player = new Player($_SESSION['login']);
	// choisir une faction random et instancier 3 ship de cette faction
	$player->addShip(new HonorableDuty(array("x" => 15, "y" => 10), Ship::WEST));
	$player->addShip(new HonorableDuty(array("x" => 20, "y" => 5), Ship::WEST));
	$player->addShip(new HonorableDuty(array("x" => 5, "y" => 31), Ship::WEST));
	$game->addPlayer($player);
	$_SESSION['board'] = $game;
}

?>
<!DOCTYPE html>
<html>
	<head>
		<title>Awesome Starship Battle 2</title>
		<?php include('elements/head.php'); ?>
	</head>
	<body>
		<?php include('elements/header.php'); ?>
		<div class="container">
			<?php include('elements/panel_player.php'); ?>
			<section>
			<canvas id="canvas" width="2102" height="1402"></canvas>
				<script language="javascript" type="text/javascript">
					var canvas = document.getElementById("canvas");
					var context = canvas.getContext("2d");
					context.lineWidth = 2;
					var px = 14;
					for(var h = 0; h <= 100; h++) {
						context.moveTo(0, h * px + 1);
						context.lineTo(canvas.width, h * px + 1);
					}
					for(var w = 0; w <= 150; w++) {
						context.moveTo(w * px + 1, 0);
						context.lineTo(w * px + 1, canvas.height);
					}
					context.stroke();
				</script>
<?php
if (isset($_SESSION['login']) && isset($_SESSION['passwd']))
{
	if (auth($_SESSION['login'], $_SESSION['passwd']) == 1)
	{
		if (!playerIsInGame($_SESSION['login']))
			header("Location: index.php");
		if (isset($_SESSION['board']))
		{
			$game = $_SESSION['board'];
			foreach ($game->getPlayer() as $p)
			{
				foreach ($p->getFleet() as $s)
				{
					$pos = $s->getPos();
					$pos["x"] += 399;
					$pos["y"] += 241;
					echo "<a href=\"game.php?posx=".$pos['x']."&posy=".$pos['y']."\"><div style=\"background-image: url('".$s->getSprite()."'); height: ".$s->getSize()['height']."px; width: ".$s->getSize()['width']."px; position: absolute; top: ".$pos['y']."px; left: ".$pos['x']."px; border: 1px solid black;\"></div></a>";
				}
			}
		}
	}
}
?>

			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
