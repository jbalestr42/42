<?php

class User extends CI_Controller
{
	public function __construct()
	{
		parent::__construct();
		$this->load->library('layout');
		$this->layout->set_default();
	}
	
	public function user_category()
	{
		$this->layout->view('user/user_category');
	}
}

?>
