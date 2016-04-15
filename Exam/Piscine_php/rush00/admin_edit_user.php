<?php
include('request.php');
session_start();
if (getLevel($_SESSION['login']) < 10)
	header("Location: index.php");

if (!isset($_GET['id']) || !is_numeric($_GET['id']))
	header("Location: index.php");

$errors = array();
$success = false;

if (isset($_POST['submit'])) {
	if (!isset($_POST['login']) || $_POST['login'] === '')
		array_push($errors, 'Remplissez le nom, merci');
	if (!isset($_POST['level']) || !is_numeric($_POST['level']) || !in_array($_POST['level'], array(1, 10)))
		array_push($errors, 'Remplissez le niveau correctement');
	if (count($errors) === 0) {
		if (false === update_user(array(
			'id' => $_POST['id'],
			'login' => $_POST['login'],
			'level' => $_POST['level']
		))) {
			array_push($errors, "Un probleme est survenu");
		} else {
			$_SESSION['login'] = $_POST['login'];
			$_POST = array();
			$success = true;
		}
	}
}

$res = getResults("SELECT * FROM users WHERE id = ".$_GET['id']);
if (count($res) === 0)
	header("Location: index.php");

$user = $res[0];

?>
<!DOCTYPE html>
<html>
	<head>
		<title>Admin - User</title>
		<?php include('elements/head.php'); ?>
	</head>
	<body>
		<?php include('elements/header.php'); ?>
		<div class="container">
			<?php include('elements/nav.php'); ?>
			<section>
				<h1><a href="admin.php">Administration</a> <i class="icon-arrow-right2"></i> <a href="admin_users.php">Utilisateurs</a> <i class="icon-arrow-right2"></i> <?= $user['login']; ?></h1>
				<div class="bloc">
					<h3>modifier un utilisateur</h3>
<?php
if (count($errors)) {
?>
					<ul class="errors">
<?php
	foreach ($errors as $err) {
?>
						<li><?= $err; ?></li>
<?php
	} // end foreach errors
?>
					</ul>
<?php
} // end if count errors
?>
<?php
if ($success) {
?>
					<div class="success">L'utilisateur a bien &eacute;t&eacute; modifi&eacute; !</div>
<?php
} // end success
?>
					<form method="post">
						<div class="field">
							<input autofocus type="text" placeholder="login" name="login" class="full" value="<?php echo isset($_POST['login']) ? $_POST['login'] : $user['login']; ?>">
						</div>
						<div class="field">
							Niveau :
							<select name="level">
								<option value="1"<?php echo ((isset($_POST['level']) && $_POST['level'] == 1) || (!isset($_POST['level']) && $user['level'] == 1)) ? ' selected' : ''; ?>>Normal</option>
								<option value="10"<?php echo ((isset($_POST['level']) && $_POST['level'] == 10) || (!isset($_POST['level']) && $user['level'] == 10)) ? ' selected' : ''; ?>>Admin</option>
							</select>
						</div>
						<div class="field">
							<input type="hidden" value="<?= $user['id']; ?>" name="id">
							<input type="submit" value="Enregistrer" class="btn" name="submit">
						</div>
					</form>
				</div>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
