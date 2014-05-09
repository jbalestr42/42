<?php if (!defined('BASEPATH')) exit('No direct script access allowed');

class Ldaplib
{
	private $_state;
	private $_ldapconn;
	private $_ldaprdn;
	private $_ldappass;
	private $_ldapbind;

	public function __construct()
	{
		$this->_ldaprdn  = 'uid=jbalestr,ou=2013,ou=people,dc=42,dc=fr';
		$this->_ldappass = '';
		$this->_ldapconn = ldap_connect("ldap.42.fr")
			or die("Impossible de se connecter au serveur LDAP.");
		ldap_set_option($this->_ldapconn, LDAP_OPT_PROTOCOL_VERSION, 3);
		ldap_set_option($this->_ldapconn, LDAP_OPT_REFERRALS, 0);
		$this->_state = false;
		if ($this->_ldapconn)
		{
			$this->_ldapbind = ldap_bind($this->_ldapconn, $this->_ldaprdn, $this->_ldappass);
			if ($this->_ldapbind)
				$this->_state = true;
		}
	}

	public function get_users($filter = "&(uid=*ale*)")
	{
		$tab = array("cn", "uid", "birth-date", "picture", "mobile-phone");
		return $this->filter($filter, $tab);
	}

	public function filter($filter, $field = array())
	{
		if (!$this->_state)
			return ;
		$ldaptree  = 'dc=42,dc=fr';
		$result = ldap_search($this->_ldapconn, $ldaptree, "(".$filter.")", $field) or die ("Error in search query: ".ldap_error($this->_ldapconn));
		$data = ldap_get_entries($this->_ldapconn, $result);
		$tmp = array();
		$result = array();
		for ($i = 0; $i < $data['count']; $i++)
		{
			foreach ($field as $t)
			{
				if (isset($data[$i][$t][0]))
					$tmp[$t] = $data[$i][$t][0];
				else
					$tmp[$t] = "(null)";
			}
			$result[] = $tmp;
		}
		return $result;
	}
}
?>
