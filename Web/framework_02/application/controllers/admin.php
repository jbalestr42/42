<?php

class Admin extends CI_Controller
{
	public function __construct()
	{
		parent::__construct();
		if (get_level() < 10)
			redirect('index');
		$this->load->library('layout');
		$this->layout->set_default();
	}

	public function admin_category()
	{
		$this->layout->view('admin/admin_category');
	}

	public function admin_user()
	{
		$this->load->model('user_model', 'u_manager');
		$data['users'] = $this->u_manager->read();
		$this->layout->view('admin/admin_user', $data);
	}

	public function admin_edit_user()
	{
		if ($this->input->post('submit'))
		{
			$id = $this->input->post('idpost');
			$this->load->library('form_validation');
			$this->form_validation->set_rules('login', '"Login"', 'trim|required|min_length[1]|max_length[255]|alpha_dash|encode_php_tags|xss_clean');
			$this->form_validation->set_rules('email', '"E-mail address"', 'trim|required|max_length[255]|valid_email|xss_clean');
			$this->form_validation->set_rules('level', '"Level"', 'trim|required|xss_clean');
			if ($this->form_validation->run())
			{
				$login = $this->u_manager->read('login', array("id" => $id))[0];
				if ($this->u_manager->count(array("login" => set_value('login'))) == 0 || $login->login == set_value('login'))
				{
					if ($this->u_manager->update(array("id" => $id), array('login' => set_value('login'), 'mail' => set_value('email'), 'level' => set_value('level'))))
						redirect('admin/admin_user');
				}
				$data['errors'] = array("Login already used.");
			}
			else
				$data['errors'] = $this->form_validation->error_array();
			$data['user'] = $this->u_manager->read('*', array("id" => $id))[0];
			$this->layout->view('admin/admin_edit_user', $data);
		}
		else
		{
			$this->load->model('user_model', 'u_manager');
			$id = $this->input->get('id');
			$data['user'] = $this->u_manager->read('*', array("id" => $id))[0];
			if (isset($data['user']))
				$this->layout->view('admin/admin_edit_user', $data);
		}
	}

	public function admin_delete_user()
	{
		$this->load->model('user_model', 'u_manager');
		$id = $this->input->get('id');
		$this->u_manager->delete(array("id" => $id));
		redirect('admin/admin_user');
	}

	public function admin_create_user()
	{
		$this->load->model('user_model', 'u_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('login', '"Login"', 'trim|required|min_length[1]|max_length[255]|alpha_dash|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('email', '"E-mail address"', 'trim|required|max_length[255]|valid_email|xss_clean');
		$this->form_validation->set_rules('passwd', '"Password"', 'trim|required|max_length[255]|encode_php_tags|xss_clean|matches[passwdconf]');
		$this->form_validation->set_rules('passwdconf', '"Password confirmation"', 'trim|required|max_length[255]|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('level', '"Level"', 'trim|required|xss_clean');
		if ($this->form_validation->run())
		{
			$tmp = array("login" => set_value('login'), "mail" => set_value('email'), "password" => set_value('passwd'), "level" => set_value('level'));
			if ($this->u_manager->create($tmp))
				redirect('admin/admin_user');
			$data['errors'] = array(lang('err_login'));
		}
		else
			$data['errors'] = $this->form_validation->error_array();
		$this->layout->view('admin/admin_create_user', $data);
	}

	public function admin_newsletter()
	{
		$config['protocol'] = "smtp";
		$config['smtp_host'] = "smtp.gmail.com";
		$config['smtp_port'] = "587";
		$config['smtp_user'] = "jbalestr42@gmail.com";
		$config['smtp_pass'] = "nes69wayak";
		$config['smtp_crypto'] = "tls";
		$config['smtp_timeout'] = "5";
		$config['mailtype'] = "text";
		$config['charset']  = "utf-8";
		$config['newline'] = "\r\n";
		$this->load->library('email', $config);
		$this->load->library('form_validation');
		$this->form_validation->set_rules('subject', '"Subject"', 'trim|required|min_length[1]|max_length[255]|alpha_dash|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('message', '"Message"', 'trim|required|max_length[4096]|alpha_dash|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
		{
			$this->load->model('user_model', 'u_manager');
			$tmp = $this->u_manager->read("mail");
			$to = "";
			foreach ($tmp as $k)
			{
				$to .= $k->mail;
				if ($k != end($tmp))
					$to .= ", ";
			}
			$this->email->set_newline("\r\n");
			$this->email->from('jbalestr@student.42.fr');
			$this->email->to($to);
			$this->email->subject(set_value('subject'));
			$this->email->message(set_value('message'));
			if (!$this->email->send())
				$data['errors'] = $this->email->get_debugger_messages();
			else
				$data['success'] = "Mails sends successfully !";
		}
		else
			$data['errors'] = $this->form_validation->error_array();
		$this->layout->view('admin/admin_newsletter', $data);
	}

	public function admin_ticket()
	{
		$this->layout->add_js('define_admin_ticket');
		$this->load->model('user_model', 'u_manager');
		$this->load->model('ticket_model', 't_manager');
		$data['tickets'] = $this->t_manager->read_tickets();
		$data['admins'] = $this->u_manager->read("*", array("level" => 10));
		$data['in_charge'] = $this->t_manager->read_tickets_incharge($data['tickets']);
		$this->layout->view('admin/admin_ticket', $data);
	}
	
	public function admin_define_ticket($id_ticket)
	{
		$this->load->model('ticket_model', 't_manager');
		$this->load->model('user_model', 'u_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('id', '"id"', 'trim|required|is_natural|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
			$this->t_manager->update_ticket($id_ticket, set_value('id'));
		redirect('admin/admin_ticket');
	}
	
	public function admin_delete_ticket()
	{
		$this->load->model('ticket_model', 't_manager');
		$id = $this->input->get('id');
		$this->t_manager->delete_ticket($id);
		redirect('admin/admin_ticket');
	}

	public function admin_edit_status($id)
	{
		$this->load->model('ticket_model', 't_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('status', '"Status"', 'trim|required|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
			$this->t_manager->update_status($id, set_value('status'));
		redirect('admin/admin_edit_ticket/'.$id);
	}

	public function admin_edit_ticket($id = 0)
	{
		$this->load->model('ticket_model', 't_manager');
		if ($id === 0)
			$id = $this->input->get('id');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('message', '"Message"', 'trim|required|max_length[4096]|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
		{
			$this->load->model('user_model', 'u_manager');
			$id_user = $this->u_manager->read('*', array("login" => $this->session->userdata('login')))[0]->id;
			$this->t_manager->create_ticket_chat(array("id_ticket" => $id, "id_user" => $id_user, "message" => set_value('message')));
		}
		$data['ticket'] = $this->t_manager->read_ticket($id)[0];
		$data['chat'] = $this->t_manager->read_chat($id);
		$this->layout->view('admin/admin_edit_ticket', $data);
	}
}

?>
