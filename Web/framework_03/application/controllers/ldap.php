<?php

class Ldap extends CI_Controller
{
	public function __construct()
	{
		parent::__construct();
		if (!check_auth())
			redirect('index');
		$this->load->library('layout');
		$this->load->library('ldaplib');
		$this->layout->set_default();
	}

	public function ldap_index()
	{
		$this->load->library('form_validation');
		$this->form_validation->set_rules('login', '"Login"', '');
		$this->form_validation->set_rules('name', '"name"', '');
		$this->form_validation->set_rules('num', '"Mobile-phone"', '');
		if ($this->form_validation->run())
		{
			$this->session->unset_userdata("ldap_login");
			$this->session->unset_userdata("ldap_name");
			$this->session->unset_userdata("ldap_num");
		}
		$data['sort'] = $this->input->get("col");
		if (isset($data['sort']) && !empty($data['sort']))
		{
			if ($this->session->userdata('sort_type') == SORT_ASC)
				$this->session->set_userdata("sort_type", SORT_DESC);
			else
				$this->session->set_userdata("sort_type", SORT_ASC);
		}
		else
			$this->session->set_userdata("sort_type", SORT_ASC);
		$data['sort_type'] = $this->session->userdata('sort_type');
		$filter = "&(uid=*)";
		$data['ldap_login'] = "";
		$data['ldap_name'] = "";
		$data['ldap_num'] = "";
		$tmp = $this->session->userdata('ldap_login');
		if (empty($tmp))
			$tmp = set_value('login');
		if (!empty($tmp))
		{
			$this->session->set_userdata("ldap_login", $tmp);
			$data['ldap_login'] = $tmp;
			$filter .= "(uid=*".$tmp."*)";
		}
		$tmp = $this->session->userdata('ldap_name');
		if (empty($tmp))
			$tmp = set_value('name');
		if (!empty($tmp))
		{
			$this->session->set_userdata("ldap_name", $tmp);
			$data['ldap_name'] = $tmp;
			$filter .= "(cn=".$tmp."*)";
		}
		$tmp = $this->session->userdata('ldap_num');
		if (empty($tmp))
			$tmp = set_value('num');
		if (!empty($tmp))
		{
			$this->session->set_userdata("ldap_num", $tmp);
			$data['ldap_num'] = $tmp;
			$filter .= "(mobile-phone=".$tmp."*)";
		}
		$data['users'] = $this->ldaplib->get_users($filter);
		$this->layout->view('ldap/ldap_index', $data);
	}
}
?>
