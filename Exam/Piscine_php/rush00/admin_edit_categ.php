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
	if (!isset($_POST['name']) || $_POST['name'] === '')
		array_push($errors, 'Remplissez le nom, merci');
	if (count($errors) === 0) {
		if (false === update_categ(array(
			'id' => $_POST['id'],
			'name' => $_POST['name']
		))) {
			array_push($errors, "Un probleme est survenu");
		} else {
			header("Location: admin_categories.php");
		}
	}
}

$res = getResults("SELECT * FROM categories WHERE id = ".$_GET['id']);
if (count($res) === 0)
	header("Location: index.php");

$categ = $res[0];

?>
<!DOCTYPE html>
<html>
	<head>
		<title>Admin - Categ</title>
		<?php include('elements/head.php'); ?>
	</head>
	<body>
		<?php include('elements/header.php'); ?>
		<div class="container">
			<?php include('elements/nav.php'); ?>
			<section>
				<h1><a href="admin.php">Administration</a> <i class="icon-arrow-right2"></i> <a href="admin_categories.php">Cat&eacute;gories</a> <i class="icon-arrow-right2"></i> <?= $categ['name']; ?></h1>
				<div class="bloc">
					<h3>modifier une cat&eacute;gorie</h3>
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
					<div class="success">Enregistr&eacute; !</div>
<?php
} // end success
?>
					<form method="post">
						<div class="field">
							<input autofocus type="text" placeholder="nom" name="name" class="full" value="<?php echo isset($_POST['name']) ? $_POST['name'] : $categ['name']; ?>">
						</div>
						<div class="field">
							<input type="hidden" value="<?= $categ['id']; ?>" name="id">
							<input type="submit" value="Enregistrer" class="btn" name="submit">
						</div>
					</form>
				</div>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
