<?php

class Logger_model extends FT_Model
{
	protected $table = "logs";

	public function create($id_user, $str)
	{
		return (bool)$this->db->set(array("id_user" => $id_user, "action" => $str))
								->set(array("date" => "now()"), null, false)
								->insert($this->table);
	}

	public function read()
	{
		return $this->db->select(
			$this->table.'.id as id,'.
			$this->table.'.action as action,'.
			$this->table.'.date as date,'.
			'users.login as login,
			users.id as user_id')
						->from($this->table)
						->join('users', 'users.id = '.$this->table.'.id_user')
						->get()
						->result();
	}
}

?>
