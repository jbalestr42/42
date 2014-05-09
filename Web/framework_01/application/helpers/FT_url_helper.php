 <?php

if (!defined('BASEPATH'))
	exit('No direct script access allowed');

function site_url($uri = '')
{
	if(!is_array($uri))
		$uri = func_get_args();

	$CI =& get_instance();
	return $CI->config->site_url($uri);
}

function url($text, $uri = '')
{
	if(!is_array($uri))
	{
		$uri = func_get_args();
		array_shift($uri);
	}
	echo '<a href="'.site_url($uri).'">'.htmlentities($text).'</a>';
	return '';
}

function url_img($img, $uri = '')
{
	if(!is_array($uri))
	{
		$uri = func_get_args();
		array_shift($uri);
	}
	echo '<a href="'.site_url($uri).'"><img src="'.$img.'"></a>';
	return '';
}

function url_icon($text, $icon, $uri = '')
{
	if(!is_array($uri))
	{
		$uri = func_get_args();
		array_shift($uri);
		array_shift($uri);
	}
	echo '<a href="'.site_url($uri).'"><i class="icon-'.$icon.'"></i>'.htmlentities($text).'</a>';
	return '';
}

function url_icon_get($text, $icon, array $get, $uri)
{
	$str = "";
	foreach ($get as $k => $v)
	{
		$str .= $k."=".$v;
		if ($v != end($get))
			$str .= "&";
	}
	echo '<a href="'.site_url($uri).'?'.$str.'"><i class="icon-'.$icon.'"></i>'.htmlentities($text).'</a>';
}

?>
