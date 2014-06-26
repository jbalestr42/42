<?php

namespace philemon\LdapBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class LdapController extends Controller
{
    public function indexAction()
    {
        return $this->render('philemonLdapBundle:Ldap:index.html.twig');
	}

	public function contactsAction()
	{
		return $this->render('philemonLdapBundle:Ldap:contacts.html.twig');
	}
}
