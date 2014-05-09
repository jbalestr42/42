<h1><?php url(lang('title_admin'), 'admin/admin_category'); ?> <i class="icon-arrow-right2"></i> <?php echo lang('title_ticket'); ?></h1>
<table>
	<thead>
		<tr>
			<th><strong><?php echo lang('ticket_title'); ?></strong></th>
			<th><strong><?php echo lang('ticket_user'); ?></strong></th>
			<th><strong><?php echo lang('ticket_status'); ?></strong></th>
			<th><strong><?php echo lang('ticket_incharge'); ?></strong></th>
			<th class="edit"><strong> <?php echo lang('text_edit'); ?></strong></th>
		</tr>
	</thead>
	<?php
	foreach ($tickets as $ticket)
	{
		echo "<tr>";
		echo "<td>".$ticket->title."</td>";
		echo "<td>".$ticket->login."</td>";
		if ($ticket->status == "OPEN")
			echo "<td class='ticket_open'>".$ticket->status."</td>";
		else if ($ticket->status == "CLOSE")
			echo "<td class='ticket_close'>".$ticket->status."</td>";
		else
			echo "<td class='ticket_inprogress'>".$ticket->status."</td>";
		$bool = 0;
		foreach ($in_charge as $admin)
		{
			if ($admin[0]->id_ticket == $ticket->id)
			{
				echo "<td>".$admin[0]->login."</td>";
				$bool = 1;
				break ;
			}
		}
		if (!$bool)
				echo "<td>".lang('text_nobody')."</td>";
		echo "<td class='actions'>";
		url_icon_get("", "pencil", array('id' => $ticket->id), "admin/admin_edit_ticket", lang('pop_edit'));
		url_icon_get("", "remove", array('id' => $ticket->id), "admin/admin_delete_ticket", lang('pop_delete'));
		echo "<span class='icon_arrow_down' onclick='define_admin_ticket(".$ticket->id.")'><i class='icon-arrow-down'></i></span>";
		echo "</td>";
		echo "</tr>";
	} ?>
</table>
<?php
foreach ($tickets as $ticket)
{ ?>
	<form method="post" style="display: none;" class="define_admin_<?php echo $ticket->id?>" action="<?php echo site_url('admin/admin_define_ticket/'.$ticket->id); ?>">
		<div class="field">
			<select name="id" class="btn">
			<?php
				foreach ($admins as $admin)
					echo '<option value="'.$admin->id.'">'.$admin->login.'</option>';
			?>
			</select>
			<input type="submit" value="<?php echo lang('btn_define'); ?>" class="btn_sub_comment" name="submit">
		</div>
	</form>
<?php } ?>