<?php

class User_model extends FT_Model
{
	protected $table = "users";

	public function create($escaped_option = array(), $no_escaped_option = array())
	{
		if(empty($escaped_option) AND empty($no_escaped_option))
			return false;
		$escaped_option['password'] = hash("whirlpool", $escaped_option['password']);
		if ($this->count(array("login" => $escaped_option['login'])) > 0)
			return false;
		return (bool)$this->db->set($escaped_option)
								->set($no_escaped_option, null, false)
								->insert($this->table);
	}

	public function auth($login, $passwd)
	{
		if ($this->count(array("login" => $login, "password" => $passwd)) < 1)
			return false;
		return true;
	}
	
	public function get_level($login, $passwd)
	{
		$tmp = $this->db->select('level')
						->from($this->table)
						->where(array("login" => $login, "password" => $passwd))
						->get()
						->result();
		return $tmp[0]->level;
	}
}

?>
