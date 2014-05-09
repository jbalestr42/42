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
<div class="field">
	<span><?php echo lang('form_username'); ?> : </span>
	<input type="text" class="full" placeholder="<?php echo lang('form_username'); ?>" name="login" value="<?php echo set_value('login'); ?>">
</div>
<div class="field">
	<span><?php echo lang('form_mail');?> : </span>
	<input class="full" type="text" placeholder="<?php echo lang('form_mail'); ?>" name="email" value="<?php echo set_value('email'); ?>">
</div>
<div class="field">
	<span><?php echo lang('form_password'); ?> : </span>
	<input class="full" type="password" name="passwd">
</div>
<div class="field">
	<span><?php echo lang('form_passwordconf'); ?> : </span>
	<input class="full" type="password" name="passwdconf">
</div>
<div class="field">
	<input class="btn" type="submit" name="submit" value="<?php echo lang('btn_register'); ?>" />
</div>
</form>
