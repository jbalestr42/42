<?php
class Index extends CI_Controller
{
	public function __construct()
	{
		parent::__construct();
		$this->load->library('layout');
		$this->layout->set_default();
	}

	public function index()
	{
		$this->layout->view('home');
	}

	public function _remap()
	{
		$this->index();
	}
}

?>
