<!DOCTYPE html>
<html>
	<head>
		<title>Inscription</title>
		<?php include('elements/head.php'); ?>
	</head>
	<body>
		<?php include('elements/header.php'); ?>
		<div class="container">
			<?php include('elements/nav.php'); ?>
			<section>
				<h1>Inscription</h1>
				<form method="post" action="signup.php">
					<div class="field">
						<span>Nom d'utilisateur : </span>
						<input type="text" class="full" placeholder="login" name="login" value="<?php echo isset($_POST['login']) ? $_POST['login'] : ""; ?>">
					</div>
					<div class="field">
						<span>Mot de passe : </span>
						<input class="full" type="password" name="passwd">
					</div>
					<div class="field">
						<span>Confirmation : </span>
						<input class="full" type="password" name="passwdconf">
					</div>
					<div class="field">
						<input class="btn" type="submit" name="submit" value="Inscription" />
					</div>
				</form>
				<?php
				include_once('request.php');
				if (isset($_POST['login']) && isset($_POST['passwd']) && isset($_POST['passwdconf']))
				{
					if ($_POST['passwd'] == $_POST['passwdconf'])
					{
						$res = create_user($_POST['login'], $_POST['passwd']);
						if ($res == -1)
							echo "Le nom d'utilisateur est deja utilis&eacute;";
						else
							header("Location: index.php");
					}
					else
						echo "Les mdp sont differents.";
				}
			?>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
