<?php

class Forum extends CI_Controller
{
	public function __construct()
	{
		parent::__construct();
		if (!check_auth())
			redirect('index');
		$this->load->library('layout');
		$this->layout->set_default();
	}

	public function forum_index()
	{
		$this->load->model('forum_model', 'f_manager');
		$data['forums'] = $this->f_manager->read_categories();
		$this->layout->view('forum/forum_index', $data);
	}

	public function forum_category($id = 0)
	{
		$this->load->model('forum_model', 'f_manager');
		if (count($this->f_manager->read_categories('*', array("id" => $id))) < 1)
			redirect('forum/forum_index');
		$data['forums'] = $this->f_manager->read_sub_categories($id);
		$data['category'] = $this->f_manager->read_categories('*', array("id" => $id))[0];
		$this->layout->view('forum/forum_category', $data);
	}

	public function forum_posts($id = 0)
	{
		$this->load->model('forum_model', 'f_manager');
		if (count($this->f_manager->read_sub_categories_by_id($id)) < 1)
			redirect('forum/forum_index');
		$data['posts'] = $this->f_manager->read_posts($id);
		$data['category'] = $this->f_manager->read_category($id);
		$data['sub_category'] = $this->f_manager->read_title_sub_category($id);
		$this->layout->view('forum/forum_posts', $data);
	}

	public function forum_post($id = 0)
	{
		$this->layout->add_js('add_comment');
		$this->load->model('forum_model', 'f_manager');
		$this->load->model('user_model', 'u_manager');
		$data['post'] = $this->f_manager->read_post($id);
		if ($data['post'])
		{
			$data['category'] = $this->f_manager->read_category($data['post']->id_sub_cat);
			$data['sub_category'] = $this->f_manager->read_sub_category($data['post']->id_sub_cat);
			$data['user'] = $this->u_manager->read('*', array("id" => $data['post']->id_user))[0];
			$data['comments'] = $this->f_manager->read_comments($id);
			$data['sub_comments'] = $this->f_manager->read_sub_comments($id);
		}
		else
			redirect('forum/forum_index');
		$this->layout->view('forum/forum_post', $data);
	}

	public function forum_create()
	{
		if (get_level() < 10)
			redirect('index');
		$this->load->model('forum_model', 'f_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('title', '"'.lang('forum_title').'"', 'trim|required|min_length[1]|max_length[255]|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('description', '"'.lang('forum_description').'"', 'trim|required|min_length[1]|max_length[255]|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
		{
			$this->f_manager->create_category(array("title" => set_value('title'), "description" => set_value('description')));
		}
		redirect('forum/forum_index');
	}

	public function forum_create_sub()
	{
		if (get_level() < 10)
			redirect('index');
		$this->load->model('forum_model', 'f_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('title', '"'.lang('forum_title').'"', 'trim|required|min_length[1]|max_length[255]|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('description', '"'.lang('forum_description').'"', 'trim|required|min_length[1]|max_length[255]|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('id', '"id"', 'trim|required|is_natural|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
		{
			$this->f_manager->create_sub_category(array("id_category" =>set_value("id"), "title" => set_value('title'), "description" => set_value('description')));
		}
		redirect('forum/forum_category/'.set_value('id'));
	}

	public function forum_create_post()
	{
		$this->load->model('forum_model', 'f_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('title', '"'.lang('forum_title').'"', 'trim|required|min_length[1]|max_length[255]|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('message', '"'.lang('form_message').'"', 'trim|required|min_length[1]|max_length[4096]|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('id_cat', '"id category"', 'trim|required|is_natural|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('id_sub_cat', '"id sub category"', 'trim|required|is_natural|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
		{
			$this->load->model('user_model', 'u_manager');
			$id_user = $this->u_manager->read('*', array("login" => $this->session->userdata('login')))[0]->id;
			$this->f_manager->create_post(array("id_user" => $id_user, "id_cat" =>set_value("id_cat"), "id_sub_cat" => set_value('id_sub_cat'), "title" => set_value('title'), "message" => set_value('message')));
		}
		redirect('forum/forum_posts/'.set_value('id_sub_cat'));
	}

	public function forum_create_comment()
	{
		$this->load->model('forum_model', 'f_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('message', '"'.lang('form_message').'"', 'trim|required|min_length[1]|max_length[1024]|encode_php_tags|xss_clean');
		$this->form_validation->set_rules('id_post', '"id post"', 'trim|required|is_natural|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
		{
			$this->load->model('user_model', 'u_manager');
			$id_user = $this->u_manager->read('*', array("login" => $this->session->userdata('login')))[0]->id;
			$this->f_manager->create_comment(array("id_post" => set_value('id_post'), "id_user" => $id_user, "message" => set_value('message')));
		}
		redirect('forum/forum_post/'.set_value('id_post'));
	}

	public function forum_create_sub_comment($id_comment, $id_post)
	{
		$this->load->model('forum_model', 'f_manager');
		$this->load->library('form_validation');
		$this->form_validation->set_rules('message', '"'.lang('form_message').'"', 'trim|required|min_length[1]|max_length[1024]|encode_php_tags|xss_clean');
		if ($this->form_validation->run())
		{
			$this->load->model('user_model', 'u_manager');
			$id_user = $this->u_manager->read('*', array("login" => $this->session->userdata('login')))[0]->id;
			$this->f_manager->create_sub_comment(array("id_post" => $id_post, "id_comment" => $id_comment, "id_user" => $id_user, "message" => set_value('message')));
		}
		redirect('forum/forum_post/'.$id_post);
	}

	public function forum_delete_post($id = 0)
	{
		if (get_level() < 10)
			redirect('forum/forum_category');
		$this->load->model('forum_model', 'f_manager');
		$this->f_manager->delete_post($id);
		redirect('forum/forum_index');
	}

	public function forum_delete_sub_category($id = 0)
	{
		if (get_level() < 10)
			redirect('forum/forum_category');
		$this->load->model('forum_model', 'f_manager');
		$this->f_manager->delete_sub_category($id);
		redirect('forum/forum_index');
	}

	public function forum_delete_category($id = 0)
	{
		if (get_level() < 10)
			redirect('forum/forum_index');
		$this->load->model('forum_model', 'f_manager');
		$this->f_manager->delete_category($id);
		redirect('forum/forum_index');
	}

}

?>
