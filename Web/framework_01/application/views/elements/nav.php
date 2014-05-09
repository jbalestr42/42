<?php

function classMatch ($el) {
	$route = end(explode("/", "$_SERVER[REQUEST_URI]"));
	if (preg_match("/".$el."/", $route))
		echo ' class="active"';
}

function classIf ($el) {
	$route = end(explode("/", "$_SERVER[REQUEST_URI]"));
	if ($el === $route)
		echo ' class="active"';
}

?>
<nav>
	<ul>
		<li<?php classIf('index.html'); ?>><?php url_icon('Home', 'home', 'index'); ?></li>
		<?php if (get_level() > 0): ?>
			<li<?php classIf('user_category.html'); ?>><?php url_icon('User', 'user3', 'user/user_category'); ?></li>
		<?php endif; ?>
		<?php if (get_level() == 10): ?>
			<li<?php classMatch('admin'); ?>><?php url_icon('Admin', 'user4', 'admin/admin_category'); ?></li>
		<?php endif; ?>
	</ul>
</nav>
