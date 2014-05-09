<?php

class LangSwitch extends CI_Controller
{
	public function __construct() {
		parent::__construct();
		$this->load->helper('url');
	}

	function switch_language($language = "") {
		$this->load->helper('cookie');
		$this->load->library('user_agent');
		$language = ($language != "") ? $language : "english";
		set_cookie(array('name' => 'site_lang',
			'value' => $language,
			'expire' => '865000'));
		if ($this->agent->is_referral())
			redirect($this->agent->referrer());
		else
			redirect(site_url('index'));
	}
}
