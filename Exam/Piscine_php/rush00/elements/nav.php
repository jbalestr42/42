<?php

include_once('request.php');
$route = "$_SERVER[REQUEST_URI]";

function classMatch ($el) {
	global $route;
	if (preg_match($el, $route))
		echo ' class="active"';
}

function classIf ($el) {
	global $route;
	if ($el === $route)
		echo ' class="active"';
}

?>
<nav>
	<ul>
		<li<?php classIf('/index.php'); ?>><a href="index.php"><i class="icon-home"></i> Accueil</a></li>
		<li<?php classMatch('/^\/articles?.php.*/'); ?>><a href="articles.php"><i class="icon-music"></i> Instruments</a></li>
		<?php
		if (isset($_SESSION['login']) && isset($_SESSION['passwd']))
		{
			if (auth($_SESSION['login'], $_SESSION['passwd']))
			{?>
				<li<?php classIf('/account.php'); ?>><a href="account.php"><i class="icon-user3"></i> Compte</a></li>
			<?php
				if (getLevel($_SESSION['login']) == 10) {?>
					<li<?php classMatch('/^\/admin/'); ?>><a href="admin.php"><i class="icon-user4"></i> Administration</a></li>
			<?php
				}
			}
		} ?>
	</ul>
		<?php
		if (isset($_SESSION['cart']) && count($_SESSION['cart']) > 0)
		{?>
	<ul class="cart">
			<li<?php classIf('/cart.php'); ?>><span class="title"><i class="icon-cart"></i> Panier</span>
			<?php }
			if (!isset($_SESSION))
				session_start();
			if (isset($_SESSION['cart']) && count($_SESSION['cart']) > 0)
			{?>
				<ul>
				<?php
				foreach ($_SESSION['cart'] as $i => $c)
				{?>
				<li><span class="quantity"><?php echo $c['quantity']; ?></span><span class="name"><?php echo $c['name']; ?></span><a href="delete_cart_id.php?id=<?php echo $i; ?>">  <i class="icon-cancel-circle"></i></a></li>
				<?php }?>
				</ul>
			</li>
			<li class="validate"><a href="orders.php" class="btn"><i class="icon-checkmark"></i >Commander</a></li>
	</ul>
		<?php }?>
</nav>
