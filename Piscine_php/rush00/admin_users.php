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
		<title>Admin - Users</title>
		<?php include('elements/head.php'); ?>
	</head>
	<body>
		<?php include('elements/header.php'); ?>
		<div class="container">
			<?php include('elements/nav.php'); ?>
			<section>
				<h1><a href="admin.php">Administration</a> <i class="icon-arrow-right2"></i> Utilisateurs</h1>
				<table>
<?php

$users = getResults("SELECT * FROM users");

foreach ($users as $user) {

?>

					<tr>
						<td><?= $user['login'];  ?></td>
						<td class="actions">
							<a href="admin_edit_user.php?id=<?= $user['id']; ?>"><i class="icon-pencil"></i></a>
							<a href="delete.php?table=users&id=<?= $user['id']; ?>"><i class="icon-remove"></i></a>
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
