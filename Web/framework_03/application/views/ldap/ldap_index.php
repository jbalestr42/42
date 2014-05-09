<h1><?php echo lang('title_ldap'); ?></h1>
<div class="form">
<form method="post" action="<?php echo site_url('ldap/ldap_index'); ?>">
	<div class="field">
		<input autofocus type="text" placeholder="<?php echo lang('form_username'); ?>" name="login" class="full" value="<?php echo $ldap_login; ?>">
	</div>
	<div class="field">
		<input type="text" placeholder="<?php echo lang('ldap_name'); ?>" name="name" class="full" value="<?php echo $ldap_name; ?>">
	</div>
	<div class="field">
		<input type="text" placeholder="<?php echo lang('ldap_num'); ?>" name="num" class="full" value="<?php echo $ldap_num; ?>">
	</div>
	<div class="field">
		<input type="submit" value="<?php echo lang('btn_filter'); ?>" class="btn" name="submit">
	</div>
</form>
</div>
<br>
<table>
	<thead>
		<tr>
			<th><strong></strong></th>
			<th><strong><?php echo lang('ldap_login'); ?> <?php url_icon_get("", "loop3", array ("col" => "uid"), "ldap/ldap_index", lang('pop_sort'))?></strong></th>
			<th><strong><?php echo lang('ldap_name'); ?> <?php url_icon_get("", "loop3", array ("col" => "cn"), "ldap/ldap_index", lang('pop_sort'))?></strong></th>
			<th><strong><?php echo lang('ldap_birthday'); ?> <?php url_icon_get("", "loop3", array ("col" => "birth-date"), "ldap/ldap_index", lang('pop_sort'))?></strong></th>
			<th><strong><?php echo lang('ldap_num'); ?> <?php url_icon_get("", "loop3", array ("col" => "mobile-phone"), "ldap/ldap_index", lang('pop_sort'))?></strong></th>
		</tr>
	</thead>
<?php
$uid = array();
if (!isset($sort) || empty($sort))
	$sort = "uid";
foreach ($users as $key => $row)
	$uid[$key] = $row[$sort];
array_multisort($uid, $sort_type, $users);
foreach ($users as $user)
{
	$url = "https://cdn.42.fr/userprofil/commentview/".$user['uid'].".jpg";
	echo "<tr>";
	if ($user['picture'] != "(null)")
		echo "<td><img class='list_picture' src='".$url."' title='".$user['uid']."' alt='".$user['uid']."'></td>";
	else
		echo "<td><img class='list_picture' src='".img_url("empty.png")."'></td>";
	echo "<td>".$user['uid']."</td>";
	echo "<td>".$user['cn']."</td>";
	if ($user['birth-date'] != "(null)")
		echo "<td>".substr($user['birth-date'], 6, 2)."/".substr($user['birth-date'], 4, 2)."/".substr($user['birth-date'], 0, 4)."</td>";
	else
		echo "<td><td>";
	if ($user['mobile-phone'] != "(null)")
		echo "<td>".$user['mobile-phone']."</td>";
	else
		echo "<td><td>";
	echo "</tr>";
}
?>
</table>
