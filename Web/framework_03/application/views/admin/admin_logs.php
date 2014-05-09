<h1><?php url(lang('title_admin'), 'admin/admin_category'); ?> <i class="icon-arrow-right2"></i> Logs</h1>
<table>
	<thead>
		<tr>
		<th><strong><?php echo lang('form_username'); ?></strong></th>
			<th><strong><?php echo lang('form_action'); ?></strong></th>
			<th><strong><?php echo lang('form_date'); ?></strong></th>
		</tr>
	</thead>
	<?php
	foreach ($logs as $log)
	{
		echo "<tr>";
		echo "<td>".$log->login."</td>";
		$tab = explode(":", $log->action);
		if (count($tab) == 2)
			echo "<td>".lang($tab[0]).": ".$tab[1]."</td>";
		else
			echo "<td>".lang($log->action)."</td>";
		echo "<td>".$log->date."</td>";
		echo "</tr>";
	} ?>
</table>
