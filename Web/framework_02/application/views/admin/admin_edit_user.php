<h1><?php url(lang('title_admin'), 'admin/admin_category'); ?> <i class="icon-arrow-right2"></i> <?php url(lang('title_user'), 'admin/admin_user'); ?> <i class="icon-arrow-right2"></i> <?php echo $user->login; ?></h1>
<?php
if (isset($errors) && count($errors) > 0)
{
	echo "<ul class='errors'>";
	foreach ($errors as $k => $v)
		echo "<li>$v</li>";
	echo "</ul>";
}
?>
<form method="post" action="">
	<input type="hidden" name="idpost" value="<?php echo $user->id; ?>">
	<div class="field">
		<input autofocus type="text" placeholder="<?php echo lang('form_username'); ?>" name="login" class="full" value="<?php echo $user->login; ?>">
	</div>
	<div class="field">
		<input type="text" placeholder="<?php echo lang('form_mail'); ?>" name="email" class="full" value="<?php echo $user->mail; ?>">
	</div>
	<div class="field">
		<?php echo lang('text_level'); ?>:
		<select name="level" class="btn">
			<option value="1" <?php if ($user->level == 1) echo "selected"; ?>>Normal</option>
			<option value="10" <?php if ($user->level == 10) echo "selected"; ?>>Admin</option>
		</select>
	</div>
	<div class="field">
		<input type="hidden" value="" name="id">
		<input type="submit" value="<?php echo lang('btn_save'); ?>" class="btn" name="submit">
	</div>
</form>
