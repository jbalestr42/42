<?php
include('lib.php');
include('request.php');
session_start();
if (getLevel($_SESSION['login']) < 10)
	header("Location: index.php");
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
				<ul class="smart-list">
					<li>
						<a href="admin_articles.php">
							<i class="icon-music"></i>
							<span>Instruments</span>
						</a>
					</li>
					<li>
						<a href="admin_categories.php">
							<i class="icon-list2"></i>
							<span>Cat&eacute;gories</span>
						</a>
					</li>
					<li>
						<a href="admin_users.php">
							<i class="icon-users"></i>
							<span>Utilisateurs</span>
						</a>
					</li>
					<li>
						<a href="admin_orders.php">
							<i class="icon-drawer3"></i>
							<span>Commandes</span>
						</a>
					</li>
				</ul>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
