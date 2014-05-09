<header>
	<div>
		<?php url_img('http://placehold.it/350x150', 'index'); ?>
	</div>
	<div class="header-right">
	<?php if (check_auth()): ?>
		<?php echo lang('text_hello'); ?> <?php echo $this->session->userdata('login'); ?> ! <?php url(lang('link_logout'), 'account/logout'); ?>
	<?php else: ?>
		<form method="post" action="<?php echo site_url('account/signin'); ?>">
		<input type="text" placeholder="<?php echo lang('form_username'); ?>" name="login">
			<input type="password" placeholder="<?php echo lang('form_password'); ?>" name="passwd">
			<input class="btn" type="submit" name="submit" value="<?php echo lang('btn_signin'); ?>" /> - <?php url(lang('link_register'), 'account/register'); ?>
		</form>
	<?php endif; ?>
		<div class="language">
			<?php url_img_class(img_url("flag_uk.jpg"), "icon_lang", 'langswitch/switch_language/english'); ?>
			<?php url_img_class(img_url("flag_fr.jpg"), "icon_lang", 'langswitch/switch_language/french'); ?>
		</div>
	</div>
</header>
