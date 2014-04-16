<?php
include('connect.php');
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
				<h1>Bienvenue sur MiniMusicShop !</h1>
				<hr>
				<ul class="present-list">
<?php
$articles = getResults("SELECT * FROM articles ORDER BY RAND() LIMIT 10");
foreach ($articles as $article) {
?>
					<li><a href="article.php?id=<?php echo $article['id']; ?>">
						<img width="200" src="<?php echo ($article['image_url']); ?>">
					</a></li>
<?php
} // end foreach article
?>
				</ul>
				<a href="articles.php">Voir tous les instruments...</a>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
