<?php

include_once('request.php');
session_start();

if (isset($_SESSION['login']) && isset($_SESSION['passwd']))
{
	if (auth($_SESSION['login'], $_SESSION['passwd']) == 1)
	{
		if (playerIsInGame($_SESSION['login']))
			header("Location: game.php");
		if (isset($_POST['create']) && isset($_POST['name']) && $_POST['name'] != "" && canCreateGame($_SESSION['login']))
		{
			$name = escape_str($_POST['name']);
			create_game($_POST['name'], $_SESSION['login']);
		}
		else if (isset($_POST['leave']) && isset($_POST['gameid']))
			withdrawPlayerFromGame($_SESSION['login'], $_POST['gameid']);
		else if (isset($_POST['join']) && isset($_POST['gameid']))
		{
			joinGame($_SESSION['login'], $_POST['gameid']);
			$_SESSION['gameid'] = $_POST['gameid'];
			header("Location: lobby.php");
			$_SESSION['is_init'] = 0;
		}
	}
	else
		header("Location: index.php");
}
else
	header("Location: index.php");
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
			<hr>
			<?php include('elements/nav.php'); ?>
			<section>
				<h1>Lobby</h1>
				<form action="minichat_post.php" method="post">
				<p>
				<label for="message">Message</label> :  <input type="text" name="message" id="message" />
				<input class="btn" type="submit" value="Send" />
				</p>
				</form>
				<?php
				include_once('request.php');
				$res = getChat();
				foreach($res as $donnees)
					echo '<p><strong>' . htmlspecialchars($donnees['pseudo']) . '</strong> : ' . htmlspecialchars($donnees['message']) . '</p>';
				?>
<script>
function checkGame(id) {
	if (window.XMLHttpRequest)
		xmlhttp = new XMLHttpRequest();
	else
		xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
	xmlhttp.onreadystatechange = function()
	{
		if (xmlhttp.readyState == 4 && xmlhttp.status == 200)
		{
			if (document.getElementById("info"))
			{
				document.getElementById("info").innerHTML = xmlhttp.responseText;
				setTimeout("location.href = 'lobby.php'", 2000);
			}
		}
	}
	xmlhttp.open("GET","checkvalidgame.php?gameid=" + id, true);
	xmlhttp.send();
}
</script>
<?php if (isset($_SESSION['gameid'])) { ?>
<script>
	var id = <?php echo $_SESSION['gameid']; ?> + "";
	setInterval("checkGame(id)", 3000);
</script>
<?php } ?>
				<hr>
				<?php
				if (canCreateGame($_SESSION['login']))
				{ ?>
					<form method="post">
						<input type="text" placeholder="New game" name="name">
						<input class="btn" type="submit" name="create" value="Creer une partie">
					</form>
				<?php }
				else if (!playerIsInGame($_SESSION['login'])){?>
					<div id="info"></div>
				<?php } ?>
				<table>
					<thead>
						<tr>
							<th><strong>Nom</strong></th>
							<th><strong>Cr&eacute;ateur</strong></th>
							<th><strong>Places</strong></th>
							<th><strong>Action</strong></th>
						</tr>
					</thead>
					<?php
					$games = getGames();
					foreach ($games as $g)
					{
						$players = explode(";", $g['players']); ?>
						<tr>
							<td><?php echo $g['name']; ?></td>
							<td><?php echo $players[0]; ?></td>
							<td><?php echo count($players)."/2"; ?></td>
							<?php
							if (in_array($_SESSION['login'], $players))
							{ ?>
								<td><form method="post">
									<input type="hidden" name="gameid" value="<?php echo $g['id']; ?>">
									<input class="btn" type="submit" name="leave" value="Quitter">
								</td></form>
							<?php
							}
							else if (canCreateGame($_SESSION['login']) && count($players) < 2)
							{ ?>
								<td><form method="post">
									<input type="hidden" name="gameid" value="<?php echo $g['id']; ?>">
									<input class="btn" type="submit" name="join" value="Rejoindre">
								</td></form>
							<?php } ?>
						</tr>
					<?php } ?>
				</table>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
