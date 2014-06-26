<?php

namespace philemon\UserBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use philemon\UserBundle\Entity\User as User;

class ProfileController extends Controller
{
    public function showAction($slug)
	{
		$id = -1;
		$mark = null;
		$mod = null;
		$rep = $this->getDoctrine()
					->getRepository('philemonUserBundle:User');
		$use = $rep->findBy(array('username' => $slug));
		foreach ($use as $elem){
			$id = $elem->getId();}
		if($id != -1){
		$rep = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Correction');

		$mark = $rep->findby(array('user' => $id));
		$rep = $this->getDoctrine()
					->getRepository('philemonModuleBundle:ModuleLogin');
		$mod = $rep->findby(array('user' => $id));}
		return $this->render('philemonUserBundle:Profile:show.html.twig', array ('use' => $use, 'mark' => $mark, 'mod' => $mod));
	}
}
