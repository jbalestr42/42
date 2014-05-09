<?php

class Account extends CI_Controller
{
	public function __construct()
	{
		parent::__construct();
		$this->load->library('layout');
		$this->layout->set_default();
	}

	public function register()
	{
		$this->load->model('user_model', 'u_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('login', '"Login"', 'trim|required|min_length[1]|max_length[255]|alpha_dash|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('email', '"E-mail address"', 'trim|required|max_length[255]|valid_email|xss_clean');
		$this->form_validation->set_rules('passwd', '"Password"', 'trim|required|max_length[255]|encode_php_tags|xss_clean|matches[passwdconf]');
		$this->form_validation->set_rules('passwdconf', '"Password confirmation"', 'trim|required|max_length[255]|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
		{
			$tmp = array("login" => set_value('login'), "mail" => set_value('email'), "password" => set_value('passwd'));
			if ($this->u_manager->create($tmp))
				redirect('index', 'refresh');
			$data['errors'] = array("Login already used.");
		}
		else
			$data['errors'] = $this->form_validation->error_array();
		$this->layout->view('account/register', $data);
	}

	public function signin()
	{
		$this->load->model('user_model', 'u_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('login', '"Login"', 'trim|required|min_length[1]|max_length[255]|alpha_dash|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('passwd', '"Password"', 'trim|required|max_length[255]|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
		{
			if ($this->u_manager->auth(set_value('login'), hash("whirlpool", set_value('passwd'))))
			{
				$this->session->set_userdata('login', set_value('login'));
				$this->session->set_userdata('passwd', hash("whirlpool", set_value('passwd')));
				redirect('index', 'refresh');
			}
			$data['errors'] = array("login / password fail.");
		}
		else
			$data['errors'] = $this->form_validation->error_array();
		$this->layout->view('account/signin', $data);
	}
	
	public function logout()
	{
		$this->output->enable_profiler(true);
		if (check_auth())
			$this->session->unset_userdata(array('login' => '', 'passwd' => ''));
		redirect('index', 'refresh');
	}
}

?>
