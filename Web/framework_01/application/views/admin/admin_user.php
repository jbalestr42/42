<h1><?php url('Admin', 'admin/admin_category'); ?> <i class="icon-arrow-right2"></i> Users</h1>
<a href="<?php echo site_url('admin/admin_create_user'); ?>" class="btn">Add User</a><br/><br/>
<table>
	<thead>
		<tr>
			<th><strong>Login</strong></th>
			<th><strong>E-mail</strong></th>
			<th><strong>Level</strong></th>
			<th class="edit"><strong> Edit</strong></th>
		</tr>
	</thead>
	<?php
	foreach ($users as $user)
	{
		echo "<tr>";
		echo "<td>".$user->login."</td>";
		echo "<td>".$user->mail."</td>";
		echo "<td>".$user->level."</td>";
		echo "<td class='actions'>";
			url_icon_get("", "pencil", array('id' => $user->id), "admin/admin_edit_user");
			url_icon_get("", "remove", array('id' => $user->id), "admin/admin_delete_user");
		echo "</td>";
		echo "</tr>";
	} ?>
</table>
