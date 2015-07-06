<?php
include('lib.php');

if (isset($_POST['submit'])) {
	if (!isset($_SESSION))
		session_start();
	if (!isset($_SESSION['cart']))
		$_SESSION['cart'] = array();
	if (!isset($_SESSION['cart'][$_POST['id']]))
	{
		$article = getResults("SELECT * FROM articles WHERE id = ".intval($_GET['id']));
		if (count($article) !== 0)
			$_SESSION['cart'][$_POST['id']] = array("quantity" => 0, "name" => $article[0]['name']);
	}
	if (isset($_SESSION['cart'][$_POST['id']]))
		$_SESSION['cart'][$_GET['id']]['quantity'] += $_POST['quantity'];
}
else {
	if (!isset($_SESSION))
		session_start();
	if (!isset($_GET['id']))
		header("Location: articles.php");
}

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
<?php
if (isset($_GET['id'])) {
	$article = getResults("SELECT * FROM articles WHERE id = ".intval($_GET['id']));
	if (count($article) === 0)
		header("Location: articles.php");
	$article = $article[0];
}
?>
				<div class="article">
					<img width="400" src="<?php echo $article['image_url']; ?>">
					<h1><?php echo $article['name']; ?></h1>
					<div class="price"><?php echo $article['price']; ?> &#x20AC;</div>
					<p><?php echo $article['description']; ?></p>
					<hr>
					<form method="post">
						<input type="hidden" value="<?php echo $article['id']; ?>" name="id">
						<input type="number" value="1" min="1" placeholder="quantit&eacute;" name="quantity">
						<input type="submit" name="submit" value="Ajouter au panier">
					</form>
				</div>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
