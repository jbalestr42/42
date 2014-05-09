<?php
if (!defined('BASEPATH'))
	exit('No direct script access allowed');

class FT_Model extends CI_Model
{
	public function create($escaped_option = array(), $no_escaped_option = array())
	{
		if(empty($escaped_option) AND empty($no_escaped_option))
			return false;
		return (bool)$this->db->set($escaped_option)
								->set($no_escaped_option, null, false)
								->insert($this->table);
	}

	public function read($select = '*', $where = array())
	{
		return $this->db->select($select)
						->from($this->table)
						->where($where)
						->get()
						->result();
	}
	
	public function update($where, $escaped_option = array(), $no_escaped_option = array())
	{
		if(empty($escaped_option) AND empty($no_escaped_option))
			return false;
		if(is_integer($where))
			$where = array('id' => $where);
		return (bool) $this->db->set($escaped_option)
								->set($no_escaped_option, null, false)
								->where($where)
								->update($this->table);
	}
	
	public function delete($where)
	{
		if(is_integer($where))
			$where = array('id' => $where);
		return (bool) $this->db->where($where)
								->delete($this->table);
	}

	// Si $field est un array, la variable $valeur sera ignorée par la méthode where()
	public function count($field = array(), $valeur = null)
	{
		return (int) $this->db->where($field, $valeur)
								->from($this->table)
								->count_all_results();
	}
}
