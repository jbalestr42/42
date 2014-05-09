<h1><?php url(lang('title_forum'), 'forum/forum_index'); ?> <i class="icon-arrow-right2"></i> <?php url($category->title, 'forum/forum_category/'.$category->id); ?> <i class="icon-arrow-right2"></i> <?php url($sub_category->title, 'forum/forum_posts/'.$sub_category->id); ?></h1>
<h2><?php echo $post->title; ?></h2>
<div class="post">
	<?php echo $post->message; ?>
<div class="post_login"><?php echo $user->login; ?></div>
</div>
<?php
foreach ($comments as $comment)
{
	echo "<div class='comment'>";
	echo $comment->message;
	echo "<div class='post_login_comment'>";
	echo $comment->login." - ";
	echo "<span class='icon_plus' onclick='add_comment(".$comment->id.")'><i class='icon-plus'></i></span>";
	echo "</div></div>";
	foreach ($sub_comments as $sub)
	{
		if ($sub->id_comment === $comment->id)
		{
			echo "<div class='sub_comment'>";
			echo $sub->message;
			echo "<div class='post_login_comment'>";
			echo $sub->login."  ";
			echo "</div></div>";
		}
	}
	?>
	<form method="post" style="display: none;" class="form_comment_<?php echo $comment->id?>" action="<?php echo site_url('forum/forum_create_sub_comment/'.$comment->id.'/'.$post->id); ?>">
		<div class="field">
			<input class="fullarea_sub_comment" type="text" placeholder="<?php echo lang('form_comment'); ?>" name="message">
			<input type="submit" value="<?php echo lang('btn_comment'); ?>" class="btn_sub_comment" name="submit">
		</div>
	</form>
<?php } ?>
<hr>
<form method="post" action="<?php echo site_url('forum/forum_create_comment'); ?>">
	<div class="field">
		<textarea class="fullarea_comment" type="text" placeholder="<?php echo lang('form_message'); ?>" name="message"></textarea>
	</div>
	<div class="field">
		<input type="hidden" value="<?php echo $post->id; ?>" name="id_post">
		<input type="submit" value="<?php echo lang('btn_comment'); ?>" class="btn" name="submit">
	</div>
</form>
</div>
