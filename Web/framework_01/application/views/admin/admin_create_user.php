<?php
if (isset($errors) && count($errors) > 0)
{
	echo "<ul class='errors'>";
	foreach ($errors as $k => $v)
		echo "<li>$v</li>";
	echo "</ul>";
}
?>
<h1><?php url('Admin', 'admin/admin_category'); ?> <i class="icon-arrow-right2"></i> <?php url('Users', 'admin/admin_user'); ?></h1>
<form method="post" action="">
	<div class="field">
		<input autofocus type="text" placeholder="login" name="login" class="full" value="">
	</div>
	<div class="field">
		<input type="text" placeholder="email" name="email" class="full" value="">
	</div>
	<div class="field">
		<input class="full" placeholder="password" type="password" name="passwd">
	</div>
	<div class="field">
		<input class="full" placeholder="password confirmation" type="password" name="passwdconf">
	</div>
	<div class="field">
		Level:
		<select name="level" class="btn">
			<option value="1">Normal</option>
			<option value="10">Admin</option>
		</select>
	</div>
	<div class="field">
		<input type="hidden" value="" name="id">
		<input type="submit" value="save" class="btn" name="submit">
	</div>
</form>
