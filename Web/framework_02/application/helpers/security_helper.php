<?php

if (!defined('BASEPATH'))
	exit('No direct script access allowed');

if (!function_exists('check_auth'))
{
	function check_auth() {
		$CI = get_instance();
		$CI->load->model('user_model', 'u_manager');
		$login = $CI->session->userdata('login');
		$passwd = $CI->session->userdata('passwd');
		if (isset($login) && isset($passwd) && $login != "" && $passwd != "" && $CI->u_manager->auth($login, $passwd))
			return true;
		return false;
	}
}

if (!function_exists('get_level'))
{
	function get_level() {
		$CI = get_instance();
		$CI->load->model('user_model', 'u_manager');
		$login = $CI->session->userdata('login');
		$passwd = $CI->session->userdata('passwd');
		if (check_auth())
			return $CI->u_manager->get_level($login, $passwd);
		return 0;
	}
}

?>
