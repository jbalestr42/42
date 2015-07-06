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
				include_once('request.php');
				if (!$_SESSION)
					session_start();
				if ($_SESSION['cart'])
				{
					$total = 0;
					?>
					<table>
					<h1>Commande</h1>
					<hr>
					<thead>
						<tr>
							<th><strong>Nom</strong></th>
							<th><strong>Quantit&eacute;</strong></th>
							<th><strong>Prix</strong></th>
						</tr>
					</thead>
					<?php
					foreach ($_SESSION['cart'] as $i => $c) {?>
						<tr>
							<td><?php echo $c['name']; ?></td>
							<td><?php echo $c['quantity']; ?></td>
							<?php
							$price = get_price_by_id($i);
							$total += $price * $c['quantity'];
							?>
							<td><?php echo $price; ?> &euro;</td>
						</tr>
					<?php } ?>
						<tr>
							<td><strong>Total</strong></td>
							<td>&nbsp;</td>
							<td><?php echo $total; ?> &euro;</td>
						</tr>
					</table>
				<?php
				}
				if (isset($_SESSION['login']) && isset($_SESSION['passwd']) && auth($_SESSION['login'], $_SESSION['passwd']))
				{
					if (isset($_SESSION['cart']) && count($_SESSION['cart']) > 0 && isset($_POST['submit']))
					{
						add_order($_SESSION['login'], $_SESSION['cart']);
						$_SESSION['cart'] = null;
						header("Location: thanks.php");
					}
					else if (isset($_SESSION['cart']) && count($_SESSION['cart']))
					{?>
					<form method="post">
						<input type="hidden" name="submit" value="OK">
						<button class="btn" type="submit"><i class="icon-checkmark-circle"></i> Valider la commande</button>
					</form>
				<?php }
					else
						header("Location: index.php");
				}
				else {
?>
					<br>
					<ul class="errors unstyled">
						<li>Connectez vous pour valider la commande</li>
					</ul>
<?php
				}
?>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
