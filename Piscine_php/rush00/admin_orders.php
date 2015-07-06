<?php
include('lib.php');
include('request.php');
if (!isset($_SESSION))
	session_start();
if (getLevel($_SESSION['login']) < 10)
	header("Location: index.php");
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Admin - Users</title>
		<?php include('elements/head.php'); ?>
	</head>
	<body>
		<?php include('elements/header.php'); ?>
		<div class="container">
			<?php include('elements/nav.php'); ?>
			<section>
				<h1><a href="admin.php">Administration</a> <i class="icon-arrow-right2"></i> Commandes</h1>
				<hr>
					<table>
						<thead>
							<tr>
								<th><strong>Date</strong></th>
								<th><strong>Client</strong></th>
								<th><strong>Articles</strong></th>
							</tr>
						</thead>
						<?php
						$orders = get_orders();
						foreach ($orders as $c)
						{
							$user = get_user_by_id($c['user_id']); ?>
							<tr>
								<td><?php echo $c['date']; ?></td>
								<td><?php echo $user['login']; ?></td>
								<td>
									<?php
									$articles = unserialize($c['content']); ?>
									<table>
										<?php
										foreach ($articles as $a)
										{?>
											<tr>
											<td><?php echo $a['name']; ?></td>
											<td class="small right-aligned"><?php echo $a['quantity']; ?></td>
											<td class="mini"><i class="icon-close"></i></td>
											<td class="small"><?php echo $a['price']; ?> &euro;</td>
											</tr>
										<?php } ?>
									</table>
								</td>
							</tr>
						<?php } ?>
					</table>
			</section>
		</div>
		<?php include('elements/footer.php'); ?>
	</body>
</html>
