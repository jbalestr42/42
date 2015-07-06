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
	if (!isset($_POST['price']) || !is_numeric($_POST['price']) || $_POST['price'] < 1)
		array_push($errors, 'Remplissez le prix correctement');
	if (!isset($_POST['image']) || $_POST['image'] === '')
		array_push($errors, 'Il est important de mettre une image');
	if (!isset($_POST['description']) || $_POST['description'] === '')
		array_push($errors, 'Une description ?');
	if (count($errors) === 0) {
		if (false === create_product(array(
			'name' => $_POST['name'],
			'price' => $_POST['price'],
			'description' => $_POST['description'],
			'image_url' => $_POST['image'],
			'category_id' => $_POST['category']
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
		<title>Admin - Instruments</title>
		<?php include('elements/head.php'); ?>
	</head>
	<body>
		<?php include('elements/header.php'); ?>
		<div class="container">
			<?php include('elements/nav.php'); ?>
			<section>
				<h1><a href="admin.php">Administration</a> <i class="icon-arrow-right2"></i> Instruments</h1>
				<div class="bloc">
					<h3>ajouter un instrument</h3>
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
					<div class="success">L'article a bien &eacute;t&eacute; cr&eacute;&eacute; !</div>
<?php
} // end success
?>
					<form method="post" action="admin_articles.php">
						<div class="field">
							<input autofocus type="text" placeholder="nom" name="name" class="full" value="<?php echo isset($_POST['name']) ? $_POST['name'] : ""; ?>">
						</div>
						<div class="field">
							<input type="number" min="1" placeholder="prix" name="price" value="<?php echo isset($_POST['price']) ? $_POST['price'] : ""; ?>">
						</div>
						<div class="field">
							Cat&eacute;gorie :
							<select name="category">
<?php

$categories = getResults("SELECT * FROM categories");

foreach ($categories as $categ) {

?>
								<option value="<?= $categ['id']; ?>"><?= $categ['name']; ?></option>
<?php
} // end foreach categ
?>
							</select>
						</div>
						<div class="field">
							Description :
							<textarea name="description" class="full" rows="5"><?php echo isset($_POST['description']) ? $_POST['description'] : ""; ?></textarea>
						</div>
						<div class="field">
							<input type="text" value="<?php echo isset($_POST['image']) ? $_POST['image'] : ""; ?>" name="image" placeholder="url de l'image">
						</div>
						<div class="field">
							<input type="submit" value="Enregistrer" class="btn" name="submit">
						</div>
					</form>
				</div>
				<table>
<?php

$articles = getResults("SELECT articles.id, articles.name, categories.name as category FROM articles, categories WHERE articles.category_id = categories.id");

foreach ($articles as $article) {

?>

					<tr>
						<td><?= $article['name'];  ?></td>
						<td><?= $article['category'];  ?></td>
						<td class="actions">
							<a href="admin_edit_article.php?id=<?= $article['id']; ?>"><i class="icon-pencil"></i></a>
							<a href="delete.php?table=articles&id=<?= $article['id']; ?>"><i class="icon-remove"></i></a>
						</td>
					</tr>

<?php

} // end foreach articles

?>
				</table>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
