<?php

namespace philemon\FtCalendarBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class DefaultController extends Controller
{
    public function indexAction($name)
    {
        return $this->render('philemonFtCalendarBundle:Default:index.html.twig', array('name' => $name));
    }
}
