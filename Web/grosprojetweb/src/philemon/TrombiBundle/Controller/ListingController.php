<?php

namespace philemon\TrombiBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class ListingController extends Controller
{
    public function showAction($name)
	{
    $RpceArray = array();

    $host = "ldap://ldap.42.fr";
    $ldap = self::Init_LDAP($host);
	$RpceArray['NbUsers']   = 0;
    if ($ldap['state']) //Si la connexion est établie
	{
		$i = 0;
		$ele = array('uid=', 'first-name=', 'last-name=');
      $filter='uid='.$name.'*';
      $needed_things = array('uid', 'cn', 'dn', 'other'/*, 'first-name', 'last-name',
                              'scholarity', 'mobile-phone', 'email-address', 'postal-code',
							  'alias', 'other', 'degree', 'picture',  'gender', 'uidnumber' ,'gidnumber'*/);
	  while ($i < 3){
	    $filter = $ele[$i].$name.'*';
        $Results = self::Search_LDAP($ldap, $filter, $needed_things);
		$ListeUser = self::FormatSearch_LDAP($Results, $needed_things);
		if (empty($RpceArray['ListeUser'])){
			$RpceArray['ListeUser'] = $ListeUser;}
		else {$RpceArray['ListeUser'] = array_merge($RpceArray['ListeUser'], $ListeUser); }
		$RpceArray['NbUsers']   += count($ListeUser);
	  	$i++;}
      	$ldap = self::Close_LDAP($ldap);

		return $this->render('philemonTrombiBundle:Listing:show.html.twig', $RpceArray);
	}
}

  private function Init_LDAP($hostname, $login = "student", $pwd = "passwd")
  {
    $ldap = array();
    $ldap['base_dn'] 	= 'ou=2013,ou=people,dc=42,dc=fr';
    $ldap['user_dn'] 	= "uid=$login,".$ldap['base_dn'];
    $ldap['user_nm'] 	= $login."@42.FR";
    $ldap['link'] 		 = ldap_connect($hostname, 636);

    //Set LDAP Options
    ldap_set_option($ldap['link'], LDAP_OPT_PROTOCOL_VERSION, 3);
    ldap_set_option($ldap['link'], LDAP_OPT_REFERRALS, 0);

    //Binding
    $ldap['bind']       = self::Bind_LDAP($ldap['link']);

  	//Check
  	$ldap['state'] 		 = (($ldap['link'] != NULL) && ($ldap['bind']  != NULL));

  	return ($ldap);
  }
  private function Bind_LDAP($link, $udn='', $pwd='')
  { /* Fallback to connect with user infos if anonymous don't work */ /* maybe to modifiy infos, we gonna need authentificated connexion */
  	$bind = false;

  	if ($bind = ldap_bind($link))
      	return ($bind); //echo '--Connexion anonyme reussie--<br>';
      else
      {
      	//echo '--Connexion anonyme échouée--<br>';
     		if($bind = ldap_bind($link, $udn, $pwd))
     			return ($bind);//echo '--Connexion authentifiée reussie--<br>';
      }

      /* Try to Catch Errors commented for here
      if (!$bind){
    	    if (ldap_get_option($link, LDAP_OPT_DIAGNOSTIC_MESSAGE, $error)) {
    	        echo "Error Binding to LDAP: " . $error;
    	    } else {
    	        echo "Error Binding to LDAP: No additional information is available.";
    	    }
    	    echo "<br />";
    	}*/

  	return ($bind);
  }

  private function Search_LDAP($ldap, $filter='', $NeededArray = array())
  {
  	$res = ldap_search($ldap['link'], $ldap['base_dn'], $filter, $NeededArray)
      or die ("Error in search ldap: ".ldap_error($ldap['link']));

  	$data = ldap_get_entries($ldap['link'], $res);

  	return $data;
  }
  private function FormatSearch_LDAP($Results, $needed_things)
  {
  	$Ignored = array('count', 'objectClass');
  	$Rpce 	 = array();
  	$uid     = 0;
	$i = 0;
	foreach($Results as $index => $User)
	{
		if ($i == 0){$i = 1;}
		else{
          foreach($User as $var => $data)
		  {
          	if (in_array($var, $Ignored)) continue;
              if ($var && in_array($var, $needed_things))
              	$Rpce[$uid][$var] = (is_array($data) ? $data[0]: $data);
          }
          $uid++;}
      }

  	return $Rpce;
  }


  private function Close_LDAP($ldap)
  {
  	return ( (ldap_close ($ldap['link'])||ldap_unbind ($ldap['link'])) ? array() : false);
  }

}
