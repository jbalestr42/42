<h1><?php url(lang('title_forum'), 'forum/forum_index'); ?> <i class="icon-arrow-right2"></i> <?php url($category->title, 'forum/forum_category/'.$category->id); ?> <i class="icon-arrow-right2"></i> <?php echo $sub_category->title; ?></h1>
<?php if (check_auth()): ?>
<div class="form">
<form method="post" action="<?php echo site_url('forum/forum_create_post'); ?>">
		<div class="field">
			<input type="text" placeholder="<?php echo lang('forum_title'); ?>" name="title" class="full" value="">
		</div>
		<div class="field">
			<textarea class="fullarea_comment" type="text" placeholder="<?php echo lang('form_message'); ?>" name="message"></textarea>
		</div>
		<div class="field">
		<input type="hidden" value="<?php echo $category->id; ?>" name="id_cat">
		<input type="hidden" value="<?php echo $sub_category->id; ?>" name="id_sub_cat">
			<input type="submit" value="<?php echo lang('btn_create'); ?>" class="btn" name="submit">
		</div>
	</form>
</div>
<br>
<?php
endif;
echo "<ul>";
foreach ($posts as $post)
{
	echo "<li class='forum_cat'><a href='".site_url('forum/forum_post/'.$post->id)."'>";
	echo $post->title;
	echo "</a>";
	if (get_level() == 10)
	{
		echo "   -   ";
		echo url_icon("", "remove", "forum/forum_delete_post/".$post->id);
	}
	echo "</li>";
}
echo "</ul>";
?>
