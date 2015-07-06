<?php
include('request.php');
?>
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
				<ul class="selection">
					<li<?php echo (!isset($_GET['categ'])) ? ' class="selected"' : ''; ?>><a href="articles.php">Tous</a></li>
<?php

$categories = getResults("SELECT * FROM categories ORDER BY name");

foreach ($categories as $categ) {

?>

					<li<?php echo (isset($_GET['categ']) && $_GET['categ'] == $categ['id']) ? ' class="selected"' : ''; ?>><a href="articles.php?categ=<?php echo $categ['id']; ?>"><?php echo $categ['name']; ?></a></li>

<?php

} // end foreach categories
?>
				</ul>
				<ul class="articles-list">
<?php
$categ_filter = isset($_GET['categ']) ? "WHERE category_id = ".intval($_GET['categ'])." " : "";
$articles = getResults("SELECT * FROM articles ".$categ_filter."ORDER BY name");
foreach ($articles as $article) {
?>
					<li><a href="article.php?id=<?php echo $article['id']; ?>">
						<img src="<?php echo ($article['image_url']); ?>">
						<div class="name"><?php echo ($article['name']); ?></div>
					</a></li>
<?php
} // end foreach article
?>
				</ul>
<?php
if (count($articles) === 0) {
?>
				<p>Aucun instrument dans cette cat&eacute;gorie...
<?php
} // fin if 0
?>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
