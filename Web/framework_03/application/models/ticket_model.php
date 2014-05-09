<?php

class Ticket_model extends FT_Model
{
	protected $table = "tickets";
	protected $table_chat = "tickets_chat";
	protected $table_incharge = "ticket_incharge";

	public function create(array $escaped_option)
	{
		if(empty($escaped_option))
			return false;
		return (bool)$this->db->set($escaped_option)
								->insert($this->table);
	}
	
	public function read_tickets()
	{
		return $this->db->select(
			$this->table.'.id as id,'.
			$this->table.'.message as message,'.
			$this->table.'.title as title,'.
			$this->table.'.status as status,'.
			'users.login as login,
			users.id as user_id')
						->from($this->table)
						->join('users', 'users.id = '.$this->table.'.id_user')
						->get()
						->result();
	}

	public function read_ticket($id)
	{
		return $this->db->select(
			$this->table.'.id as id,'.
			$this->table.'.message as message,'.
			$this->table.'.title as title,'.
			$this->table.'.status as status,'.
			'users.login as login,
			users.id as user_id')
						->from($this->table)
						->where(array($this->table.".id" => $id))
						->join('users', 'users.id = '.$this->table.'.id_user')
						->get()
						->result();
	}

	public function read_incharge()
	{
		return $this->db->select('*')
						->from($this->table_incharge)
						->get()
						->result();
	}

	public function read_tickets_incharge(array $tickets)
	{
		$data = array();
		foreach ($tickets as $ticket)
		{
			$tmp = $this->db->select(
			$this->table_incharge.'.id as id,'.
			$this->table_incharge.'.id_ticket as id_ticket,'.
			'users.login as login,
			users.id as user_id')
						->from($this->table_incharge)
						->where(array("id_ticket" => $ticket->id))
						->join('users', 'users.id = '.$this->table_incharge.'.id_admin')
						->get()
						->result();
						
			if (!empty($tmp))
				$data[] = $tmp;
		}
		if (isset($data[0]))
			return ($data);
		return array();
	}

	public function update_ticket($id_ticket, $id_admin)
	{
		if ((int) $this->db->where(array("id_ticket" => $id_ticket))
								->from($this->table_incharge)
								->count_all_results() < 1)
		{
			$this->db->set(array("status" => "INPROGRESS"))
								->where(array("id" => $id_ticket))
								->update($this->table);
			return (bool)$this->db->set(array("id_ticket" => $id_ticket, "id_admin" => $id_admin))
								->insert($this->table_incharge);
		}
		else
			return (bool) $this->db->set(array("id_admin" => $id_admin))
								->where(array("id_ticket" => $id_ticket))
								->update($this->table_incharge);
	}

	public function delete_ticket($id)
	{
		$incharge = $this->read('*', array("id" => $id));
		foreach ($incharge as $s)
		{
			$this->db->where(array("id_ticket" => $s->id))
				->delete($this->table_incharge);
			$this->db->where(array("id_ticket" => $s->id))
				->delete($this->table_chat);
		}
		return (bool) $this->db->where(array("id" => $id))
			->delete($this->table);
	}
	
	public function create_ticket_chat(array $escaped_option)
	{
		if(empty($escaped_option))
			return false;
		return (bool)$this->db->set($escaped_option)
								->insert($this->table_chat);
	}

	public function read_chat($id)
	{
		return $this->db->select(
			$this->table_chat.'.id as id,'.
			$this->table_chat.'.message as message,'.
			$this->table_chat.'.id_user as id_user,'.
			$this->table_chat.'.id_ticket as id_ticket,'.
			'users.login as login,
			users.id as user_id')
						->from($this->table_chat)
						->where(array("id_ticket" => $id))
						->join('users', 'users.id = '.$this->table_chat.'.id_user')
						->get()
						->result();
	}

	public function update_status($id_ticket, $status)
	{
		return (bool) $this->db->set(array("status" => $status))
							->where(array("id" => $id_ticket))
							->update($this->table);
	}
}

?>
