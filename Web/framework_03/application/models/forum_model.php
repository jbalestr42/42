<?php

class Forum_model extends FT_Model
{
	protected $table_cat = "forum_categories";
	protected $table_sub_cat = "forum_sub_categories";
	protected $table_posts = "forum_posts";
	protected $table_comments = "forum_comments";
	protected $table_sub_comments = "forum_sub_comments";

	public function read_categories($select = '*', $where = array())
	{
		return $this->db->select($select)
						->from($this->table_cat)
						->where($where)
						->get()
						->result();
	}

	public function read_sub_categories($id)
	{
		return $this->db->select('*')
						->from($this->table_sub_cat)
						->where(array("id_category" => $id))
						->get()
						->result();
	}

	public function read_sub_categories_by_id($id)
	{
		return $this->db->select('*')
						->from($this->table_sub_cat)
						->where(array("id" => $id))
						->get()
						->result();
	}

	public function read_post($id)
	{
		return $this->db->select('*')
						->from($this->table_posts)
						->where(array("id" => $id))
						->get()
						->result()[0];
	}

	public function read_posts($id_sub_cat)
	{
		return $this->db->select('*')
						->from($this->table_posts)
						->where(array("id_sub_cat" => $id_sub_cat))
						->get()
						->result();
	}

	public function read_sub_category($id)
	{
		return $this->db->select('*')
						->from($this->table_sub_cat)
						->where(array("id" => $id))
						->get()
						->result()[0];
	}

	public function read_category($id_sub_cat)
	{
		$data = $this->db->select('*')
						->from($this->table_sub_cat)
						->where(array("id" => $id_sub_cat))
						->get()
						->result();
		if ($data)
		{
			$title = $this->db->select('*')
						->from($this->table_cat)
						->where(array("id" => $data[0]->id_category))
						->get()
						->result();
			if ($title)
				return $title[0];
			else
				return false;
		}
		else
			return false;
	}

	public function read_title_sub_category($id_sub_cat)
	{
		return $this->db->select('*')
						->from($this->table_sub_cat)
						->where(array("id" => $id_sub_cat))
						->get()
						->result()[0];
	}

	public function read_sub_comments($id_post)
	{
		return $this->db->select('*')
						->from($this->table_sub_comments)
						->where(array("id_post" => $id_post))
						->join('users', 'users.id = '.$this->table_sub_comments.'.id_user')
						->get()
						->result();
	}

	public function read_comments($id_post)
	{
		return $this->db->select(
			$this->table_comments.'.id as id,'.
			$this->table_comments.'.message as message,'.
			'users.login as login,
			users.id as user_id')
						->from($this->table_comments)
						->where(array("id_post" => $id_post))
						->join('users', 'users.id = '.$this->table_comments.'.id_user')
						->get()
						->result();
	}

	public function create_sub_comment($escaped_option = array())
	{
		if(empty($escaped_option))
			return false;
		return (bool)$this->db->set($escaped_option)
								->insert($this->table_sub_comments);
	}

	public function create_comment($escaped_option = array())
	{
		if(empty($escaped_option))
			return false;
		return (bool)$this->db->set($escaped_option)
								->insert($this->table_comments);
	}

	public function create_post($escaped_option = array())
	{
		if(empty($escaped_option))
			return false;
		return (bool)$this->db->set($escaped_option)
								->insert($this->table_posts);
	}

	public function create_sub_category($escaped_option = array())
	{
		if(empty($escaped_option))
			return false;
		return (bool)$this->db->set($escaped_option)
								->insert($this->table_sub_cat);
	}

	public function create_category($escaped_option = array())
	{
		if(empty($escaped_option))
			return false;
		return (bool)$this->db->set($escaped_option)
								->insert($this->table_cat);
	}

	public function delete_category($id)
	{
		$sub = $this->read_sub_categories($id);
		foreach ($sub as $s)
			$this->delete_sub_category($s->id);
		return (bool) $this->db->where(array("id" => $id))
			->delete($this->table_cat);
	}

	public function delete_sub_category($id)
	{
		$posts = $this->read_posts($id);
		foreach ($posts as $post)
			$this->delete_post($post->id);
		return (bool) $this->db->where(array("id" => $id))
			->delete($this->table_sub_cat);
	}

	public function delete_post($id)
	{
		$comments = $this->read_comments($id);
		foreach ($comments as $comment)
		{
			$this->db->where(array("id_comment" => $comment->id))
					->delete($this->table_sub_comments);
			$this->db->where(array("id" => $comment->id))
					->delete($this->table_comments);
		}
		return (bool)$this->db->where(array("id" => $id))
			->delete($this->table_posts);
	}
}

?>
