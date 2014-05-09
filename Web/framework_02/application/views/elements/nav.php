<?php

function classMatch ($el) {
	$tab = explode("/", "$_SERVER[REQUEST_URI]");
	$tab1 = explode("_", end($tab));
	$tab2 = explode("_", prev($tab));
	if (preg_match("/".$el."/", $tab2[0]) || preg_match("/".$el."/", $tab1[0]))
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
		<li<?php classIf('index.html'); ?>><?php url_icon(lang('menu_home'), 'home', 'index'); ?></li>
		<?php if (get_level() > 0): ?>
			<li<?php classMatch('user'); ?>><?php url_icon(lang('menu_user'), 'user3', 'user/user_category'); ?></li>
			<li<?php classMatch('forum'); ?>><?php url_icon(lang('menu_forum'), 'users', 'forum/forum_index'); ?></li>
		<?php endif; ?>
		<?php if (get_level() == 10): ?>
			<li<?php classMatch('admin'); ?>><?php url_icon(lang('menu_admin'), 'user4', 'admin/admin_category'); ?></li>
		<?php endif; ?>
	</ul>
</nav>
