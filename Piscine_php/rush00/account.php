<!DOCTYPE html>
<html>
	<head>
		<title>minishop</title>
		<?php include('elements/head.php'); ?>
	</head>
	<body>
		<?php include('elements/header.php'); ?>
		<div class="container">
			<?php include('elements/nav.php'); ?>
			<section>
				<h1>Compte</h1>
				<hr>
				<form method="post">
					<div class="field">
						<span>Ancien mot de passe :</span>
						<input type="password" class="full" placeholder="ancien mot de passe" name="oldpasswd" autofocus>
					</div>
					<div class="field">
						<span>Nouveau mot de passe :</span>
						<input type="password" class="full" placeholder="nouveau mot de passe" name="newpasswd">
					</div>
					<input type="submit" name="submit" value="Enregistrer" class="btn">
				</form>
				<?php
				include_once('request.php');
				if (!isset($_SESSION))
					session_start();
				if (isset($_SESSION['login']) && isset($_SESSION['passwd']) && auth($_SESSION['login'], $_SESSION['passwd']))
				{
					if (isset($_POST['oldpasswd']) && isset($_POST['newpasswd']))
					{
						$oldpwd = hash("whirlpool", mysql_real_escape_string($_POST['oldpasswd']));
						$newpwd = hash("whirlpool", mysql_real_escape_string($_POST['newpasswd']));
						$res = update_pwd($_SESSION['login'], $oldpwd, $newpwd);
						if($res == 1)
						{
							$_SESSION['passwd'] = $newpwd;
							echo "Mot de passe chang&eacute; avec succ&egrave;s.";
						}
						else
							echo "Mot de pass incorect.";
					}
				}
				else
					header("Location: index.php");
				?>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
