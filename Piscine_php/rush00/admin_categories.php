<?php
include('request.php');
session_start();
if (getLevel($_SESSION['login']) < 10)
	header("Location: index.php");

$errors = array();
$success = false;

if (isset($_POST['submit'])) {
	if (!isset($_POST['name']) || $_POST['name'] === '')
		array_push($errors, 'Remplissez le nom, merci');
	if (count($errors) === 0) {
		if (false === create_category(array(
			'name' => $_POST['name']
		))) {
			array_push($errors, "Un probleme est survenu");
		} else {
			$_POST = array();
			$success = true;
		}
	}
}

?>
<!DOCTYPE html>
<html>
	<head>
		<title>Admin - Cat&eacute;gories</title>
		<?php include('elements/head.php'); ?>
	</head>
	<body>
		<?php include('elements/header.php'); ?>
		<div class="container">
			<?php include('elements/nav.php'); ?>
			<section>
				<h1><a href="admin.php">Administration</a> <i class="icon-arrow-right2"></i> Cat&eacute;gories</h1>
				<div class="bloc">
					<h3>ajouter une cat&eacute;gorie</h3>
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
					<div class="success">La cat&eacute;gorie a bien &eacute;t&eacute; cr&eacute;&eacute;e !</div>
<?php
} // end success
?>
					<form method="post">
						<div class="field">
							<input type="text" autofocus name="name" placeholder="nom" class="full">
						</div>
						<div class="field">
							<input type="submit" class="btn" name="submit" value="Enregistrer">
						</div>
					</form>
				</div>
				<table>
<?php

$categories = getResults("SELECT * FROM categories");

foreach ($categories as $categ) {

?>

					<tr>
						<td class="full"><?= $categ['name'];  ?></td>
						<td class="actions">
							<a href="admin_edit_categ.php?id=<?= $categ['id']; ?>"><i class="icon-pencil"></i></a>
							<a href="delete.php?table=categories&id=<?= $categ['id']; ?>"><i class="icon-remove"></i></a>
						</td>
					</tr>

<?php

} // end foreach categories

?>
				</table>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
