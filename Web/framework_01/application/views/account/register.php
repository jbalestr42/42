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
	<span>User name : </span>
	<input type="text" class="full" placeholder="login" name="login" value="<?php echo set_value('login'); ?>">
</div>
<div class="field">
	<span>E-mail address : </span>
	<input class="full" type="text" placeholder="email" name="email" value="<?php echo set_value('email'); ?>">
</div>
<div class="field">
	<span>Password : </span>
	<input class="full" type="password" name="passwd">
</div>
<div class="field">
	<span>Password confirmation : </span>
	<input class="full" type="password" name="passwdconf">
</div>
<div class="field">
	<input class="btn" type="submit" name="submit" value="Register" />
</div>
</form>
