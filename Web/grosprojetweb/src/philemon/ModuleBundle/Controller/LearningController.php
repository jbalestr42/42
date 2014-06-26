<?php

namespace philemon\ModuleBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use philemon\ModuleBundle\Entity\Learning;
use philemon\ModuleBundle\Form\PdfFileType as PdfType;

class LearningController extends Controller
{
    public function indexAction()
	{
		$rep = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Module');
		$mod = $rep->findAll();
		$repa = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Activity');
		$act = $repa->findAll();
        //return $this->render('philemonModuleBundle:Learning:index.html.twig', array('mods' => $mod, 'act' => $act));
		$learning = new Learning();
        $form = $this->createForm(new PdfType(), $learning);

        if ($this->getRequest()->getMethod() === 'POST') {
            $form->bind($this->getRequest());
            if ($form->isValid()) {
                $em = $this->getDoctrine()->getEntityManager();
                $learning->uploadProfilePicture();
                $em->persist($learning);
                $em->flush();
            }
        }
        return $this->render('philemonModuleBundle:Learning:index.html.twig', 
                array (
                    'act' => $act,
                    'mods' => $mod,
                    'form' => $form->createView()
                    )
                );
	}

	public function showAction($activity_id)
	{
		$rep = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Activity');
		$act = $rep->find($activity_id);
		$repa = $this->getDoctrine()
					->getRepository('philemonModuleBundle:Learning');
		$learnings = $repa->findByActivity($act);
		return $this->render('philemonModuleBundle:Learning:show.html.twig', array('act' => $act, 'learnings' => $learnings));
	}
}
