<!doctype html>
<html>
	<head>
		<title><?php echo $titre; ?></title>
		<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>" />
		<?php foreach($css as $url): ?>
		<link rel="stylesheet" type="text/css" media="screen" href="<?php echo $url; ?>" />
		<?php endforeach; ?>
	</head>
	<body>
		<?php echo $header; ?>
		<div class="container">
			<?php echo $nav; ?>
			<section>
				<?php echo $output; ?>
			</section>
		</div>
		<?php echo $footer; ?>
		<?php foreach($js as $url): ?>
		<script type="text/javascript" src="<?php echo $url; ?>"></script>
		<?php endforeach; ?>
	</body>
</html>
