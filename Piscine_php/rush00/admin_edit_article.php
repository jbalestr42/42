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
	if (!isset($_POST['price']) || !is_numeric($_POST['price']) || $_POST['price'] < 1)
		array_push($errors, 'Remplissez le prix correctement');
	if (!isset($_POST['image']) || $_POST['image'] === '')
		array_push($errors, 'Il est important de mettre une image');
	if (!isset($_POST['description']) || $_POST['description'] === '')
		array_push($errors, 'Une description ?');
	if (count($errors) === 0) {
		if (false === update_article(array(
			'id' => $_POST['id'],
			'name' => $_POST['name'],
			'price' => $_POST['price'],
			'description' => $_POST['description'],
			'image_url' => $_POST['image'],
			'category_id' => $_POST['category']
		))) {
			array_push($errors, "Un probleme est survenu");
		} else {
			header("Location: admin_articles.php");
		}
	}
}

$res = getResults("SELECT * FROM articles WHERE id = ".$_GET['id']);
if (count($res) === 0)
	header("Location: index.php");

$article = $res[0];

?>
<!DOCTYPE html>
<html>
	<head>
		<title>Admin - Article</title>
		<?php include('elements/head.php'); ?>
	</head>
	<body>
		<?php include('elements/header.php'); ?>
		<div class="container">
			<?php include('elements/nav.php'); ?>
			<section>
				<h1><a href="admin.php">Administration</a> <i class="icon-arrow-right2"></i> <a href="admin_articles.php">Instruments</a> <i class="icon-arrow-right2"></i> <?= $article['name']; ?></h1>
				<div class="bloc">
					<h3>modifier un article</h3>
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
							<input autofocus type="text" placeholder="nom" name="name" class="full" value="<?php echo isset($_POST['name']) ? $_POST['name'] : $article['name']; ?>">
						</div>
						<div class="field">
							<input type="number" min="1" placeholder="prix" name="price" value="<?php echo isset($_POST['price']) ? $_POST['price'] : $article['price']; ?>">
						</div>
						<div class="field">
							Cat&eacute;gorie :
							<select name="category">
<?php

$categories = getResults("SELECT * FROM categories");

foreach ($categories as $categ) {

?>
								<option value="<?= $categ['id']; ?>"<?php if ((isset($_POST['category']) && $_POST['category'] === $categ['id']) || (!isset($_POST['category']) && $article['category_id'] === $categ['id'])) { echo 'selected'; } ?>><?= $categ['name']; ?></option>
<?php
} // end foreach categ
?>
							</select>
						</div>
						<div class="field">
							Description :
							<textarea name="description" class="full" rows="5"><?php echo isset($_POST['description']) ? $_POST['description'] : $article['description']; ?></textarea>
						</div>
						<div class="field flex-centered">
							<img width="200" src="<?php echo isset($_POST['image']) ? $_POST['image'] : $article['image_url']; ?>">
							<input type="text" value="<?php echo isset($_POST['image']) ? $_POST['image'] : $article['image_url']; ?>" name="image" placeholder="url de l'image">
						</div>
						<div class="field">
							<input type="hidden" value="<?= $article['id']; ?>" name="id">
							<input type="submit" value="Enregistrer" class="btn" name="submit">
						</div>
					</form>
				</div>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
