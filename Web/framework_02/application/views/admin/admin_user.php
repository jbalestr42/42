<h1><?php url(lang('title_admin'), 'admin/admin_category'); ?> <i class="icon-arrow-right2"></i> <?php echo lang('title_user'); ?></h1>
<a href="<?php echo site_url('admin/admin_create_user'); ?>" class="btn"><?php echo lang('btn_adduser'); ?></a><br/><br/>
<table>
	<thead>
		<tr>
		<th><strong><?php echo lang('form_username'); ?></strong></th>
			<th><strong><?php echo lang('form_mail'); ?></strong></th>
			<th><strong><?php echo lang('text_level'); ?></strong></th>
			<th class="edit"><strong> <?php echo lang('text_edit'); ?></strong></th>
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
