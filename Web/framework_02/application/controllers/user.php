<?php

class User extends CI_Controller
{
	public function __construct()
	{
		parent::__construct();
		if (!check_auth())
			redirect('index');
		$this->load->library('layout');
		$this->layout->set_default();
	}

	public function user_category()
	{
		$this->layout->view('user/user_category');
	}

	public function user_create_ticket()
	{
		$this->load->model('ticket_model', 't_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('title', '"'.lang('forum_title').'"', 'trim|required|min_length[1]|max_length[255]|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('message', '"'.lang('form_message').'"', 'trim|required|min_length[1]|max_length[4096]|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
		{
			$this->load->model('user_model', 'u_manager');
			$id_user = $this->u_manager->read('*', array("login" => $this->session->userdata('login')))[0]->id;
			$this->t_manager->create(array("id_user" => $id_user, "title" => set_value('title'), "message" => set_value('message')));
		}
		redirect('user/user_ticket');
	}

	public function user_ticket()
	{
		$this->load->model('ticket_model', 't_manager');
		$this->load->model('user_model', 'u_manager');
		$id_user = $this->u_manager->read('*', array("login" => $this->session->userdata('login')))[0]->id;
		$data['tickets'] = $this->t_manager->read('*', array("id_user" => $id_user));
		$this->layout->view('user/user_ticket', $data);
	}

	public function user_delete_ticket()
	{
		$this->load->model('ticket_model', 't_manager');
		$this->t_manager->delete(array("id" => $this->input->get('id')));
		redirect('user/user_ticket');
	}

	public function user_edit_status($id)
	{
		$this->load->model('ticket_model', 't_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('status', '"Status"', 'trim|required|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
			$this->t_manager->update_status($id, set_value('status'));
		redirect('user/user_look_ticket/'.$id);
	}

	public function user_look_ticket($id = 0)
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
		$data['user'] = $this->session->userdata('login');
		$data['chat'] = $this->t_manager->read_chat($id);
		$this->layout->view('user/user_look_ticket', $data);
	}
}

?>
