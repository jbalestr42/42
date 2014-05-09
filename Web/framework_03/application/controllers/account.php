<?php

class Account extends CI_Controller
{
	public function __construct()
	{
		parent::__construct();
		$this->load->library('layout');
		$this->layout->set_default();
		$this->load->model('logger_model', 'l_manager');
	}

	public function register()
	{
		if (check_auth())
			redirect('index');
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
			{
				$id_user = $this->u_manager->read('*', array("login" => set_value('login')))[0]->id;
				$this->l_manager->create($id_user, "log_acc_create");
				redirect('index', 'refresh');
			}
			$data['errors'] = array("Login already used.");
		}
		else
			$data['errors'] = $this->form_validation->error_array();
		$this->layout->view('account/register', $data);
	}

	public function signin()
	{
		if (check_auth())
			redirect('index');
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
				$id_user = $this->u_manager->read('*', array("login" => set_value('login')))[0]->id;
				$this->l_manager->create($id_user, "log_login");
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
		if (check_auth())
		{
			if ($this->session->userdata('log_as') == "1")
			{
				$this->session->set_userdata('login', $this->session->userdata('admin_login'));
				$this->session->set_userdata('passwd', $this->session->userdata('admin_passwd'));
				$this->session->unset_userdata(array('admin_login' => '', 'admin_passwd' => ''));
				$this->session->set_userdata('log_as', "0");
			}
			else
				$this->session->unset_userdata(array('login' => '', 'passwd' => ''));
			$id_user = $this->u_manager->read('*', array("login" => $this->session->userdata('login')))[0]->id;
			$this->l_manager->create($id_user, "log_logout");
		}
		redirect('index');
	}
}

?>
