<?php if (!isset($_SESSION)) { session_start(); } ?>
<header>
	<div>
		<a href="index.php"><img src="../css/imperial_eagle.jpg"></a>
	</div>
	<div class="header-right">
<?php
if (!isset($_SESSION['login']))
{ ?>
			<form method="post" action="login.php">
				<input type="text" placeholder="login" name="login">
				<input type="password" placeholder="password" name="passwd">
				<input class="btn" type="submit" name="submit" value="connexion" /> ou <a href="signup.php">inscription</a>
			</form>
<?php }
else
{ ?>
		Bonjour <?php echo $_SESSION['login']; ?>.
		<a class="btn" href="logout.php">D&eacute;connexion</a>
	</div>
<?php } ?>

<style>

	html { background: url(../css/starship-battle.jpg) no-repeat center center fixed; background-size:cover; }

</style>
</header>
