<h1><?php url(lang('title_user'), 'user/user_category'); ?> <i class="icon-arrow-right2"></i> <?php echo lang('user_cat_ticket'); ?></h1>
<div class="form">
	<form method="post" action="<?php echo site_url('user/user_create_ticket'); ?>">
		<div class="field">
			<input type="text" placeholder="<?php echo lang('forum_title'); ?>" name="title" class="full" value="">
			<textarea class="fullarea_comment" type="text" placeholder="<?php echo lang('form_message'); ?>" name="message"></textarea>
		</div>
		<div class="field">
			<input type="submit" value="<?php echo lang('btn_create'); ?>" class="btn" name="submit">
		</div>
	</form>
</div>
<hr>
<table>
	<thead>
		<tr>
		<th><strong><?php echo lang('ticket_title'); ?></strong></th>
			<th><strong><?php echo lang('ticket_status'); ?></strong></th>
			<th class="edit"><strong> <?php echo lang('text_edit'); ?></strong></th>
		</tr>
	</thead>
	<?php
	foreach ($tickets as $ticket)
	{
		echo "<tr>";
		echo "<td>".$ticket->title."</td>";
		if ($ticket->status == "OPEN")
			echo "<td class='ticket_open'>".$ticket->status."</td>";
		else if ($ticket->status == "CLOSE")
			echo "<td class='ticket_close'>".$ticket->status."</td>";
		else
			echo "<td class='ticket_inprogress'>".$ticket->status."</td>";
		echo "<td class='actions'>";
			url_icon_get("", "file", array('id' => $ticket->id), "user/user_look_ticket", lang('pop_look'));
			url_icon_get("", "remove", array('id' => $ticket->id), "user/user_delete_ticket", lang('pop_delete'));
		echo "</td>";
		echo "</tr>";
	} ?>
</table>