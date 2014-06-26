<?php

namespace philemon\HomeBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use JMS\SecurityExtraBundle\Annotation\Secure;
use philemon\ModuleBundle\Entity\ModuleLogin as ModuleLogin;
use philemon\ModuleBundle\Entity\ActivityLogin as ActivityLogin;
use philemon\ModuleBundle\Entity\Correction as Correction;
use philemon\ModuleBundle\Entity;

class HomeController extends Controller
{
    public function indexAction()
    {
 		$user = $this->getUser();
		$rep = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Activity');
		$mod = $rep->findAll();
		$rep = $this->getDoctrine()
					->getRepository('philemonModuleBundle:ModuleLogin');
		$modl = $rep->findby(array('user' => $user->getId()));
		$rep = $this->getDoctrine()
					->getRepository('philemonModuleBundle:ActivityLogin');
		$actl = $rep->findby(array('user' => $user->getId()));
		$rep = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Correction');
		$mark = $rep->findby(array('user' => $user->getId()));
		$rep = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Correction');
		$cor = $rep->findby(array('corrector' => $user->getId()));
        return $this->render('philemonHomeBundle:Home:index.html.twig', array('mod' => $mod, 'mark' => $mark, 'cor' => $cor, 'modl' => $modl, 'actl' => $actl));
	}

}
