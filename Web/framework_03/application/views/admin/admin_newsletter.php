<h1><?php url(lang('title_admin'), 'admin/admin_category'); ?> <i class="icon-arrow-right2"></i> Newsletter</h1>
<?php
if (isset($errors) && count($errors) > 0)
{
	echo "<ul class='errors'>";
	foreach ($errors as $k => $v)
		echo "<li>$v</li>";
	echo "</ul>";
}
else if (isset($success))
{
	echo "<ul class='success'>";
		echo "<li>$success</li>";
	echo "</ul>";
}
?>
<form method="post" action="">
<div class="field">
<input type="text" class="full" placeholder="<?php echo lang('form_subject'); ?>" name="subject">
</div>
<div class="field">
	<textarea class="fullarea_comment" type="text" placeholder="<?php echo lang('form_message'); ?>" name="message"></textarea>
</div>
<div class="field">
	<input class="btn" type="submit" name="submit" value="<?php echo lang('btn_send'); ?>" />
</div>
</form>
