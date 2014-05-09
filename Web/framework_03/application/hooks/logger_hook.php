<?php

function add_log()
{
	if (check_auth())
	{
		$_CI =& get_instance();
		$_CI->load->model('logger_model', 'l_manager');
		$id_user = $_CI->u_manager->read('*', array("login" => $_CI->session->userdata('login')))[0]->id;
		$_CI->l_manager->create($id_user, "log_page: ".$_CI->uri->uri_string());
	}
}

?>
