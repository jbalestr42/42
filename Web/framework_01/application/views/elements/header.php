<header>
	<div>
		<?php url_img('http://placehold.it/350x150', 'index'); ?>
	</div>
	<div class="header-right">
	<?php if (check_auth()): ?>
		Hello <?php echo $this->session->userdata('login'); ?> ! <?php url('Logout', 'account/logout'); ?>
	<?php else: ?>
		<form method="post" action="http://framework_01.local.42.fr:8080/account/signin.html">
			<input type="text" placeholder="login" name="login">
			<input type="password" placeholder="password" name="passwd">
			<input class="btn" type="submit" name="submit" value="sign-in" /> or <?php url('register', 'account/register'); ?>
		</form>
	<?php endif; ?>
	</div>
</header>
