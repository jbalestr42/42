<?php

namespace philemon\ModuleBundle\Updates;

use Doctrine\ORM\Event\LifecycleEventArgs;
use philemon\ModuleBundle\Entity\Module;
use philemon\ModuleBundle\Entity\Activity;
use CCDNForum\ForumBundle\Entity\Category as CCDNCategory;
use CCDNForum\ForumBundle\Entity\Forum as CCDNForum;
use CCDNForum\ForumBundle\Entity\Board as CCDNBoard;
use BladeTester\CalendarBundle\Entity\EventCategory as EventCategory;
use philemon\FtCalendarBundle\Entity\Event as Event;

class CategoryListener
{
	public function prePersist(LifecycleEventArgs $args)
	{
		$obj = $args->getEntity();
		$em = $args->getEntityManager();
		if ($obj instanceof Module)
		{
			$c = new CCDNCategory();
			$rep = $em->getRepository('CCDNForumForumBundle:Forum');
			$forum = $rep->findOneByName('default');
			$c->setName($obj->getName());
			$c->setForum($forum);
			$em->persist($c);
			$ec = new EventCategory();
			$ec->setName($obj->getName());
			$em->persist($ec);
			$em->flush();
		}
		else if ($obj instanceof Activity)
		{
			$c = new CCDNBoard();
			$rep = $em->getRepository('CCDNForumForumBundle:Category');
			$cat = $rep->findOneByName($obj->getModule()->getName());
			$c->setName($obj->getName());
			$c->setDescription($obj->getDescription());
			$c->setCategory($cat);
			$em->persist($c);
			$e = new Event();
			//$repo = $em->getRepository('BladeTesterCalendarBundle:EventCategory');
			//$ec = $repo->findOneByName($obj->getModule()->getName());
			$e->setTitle($obj->getName());
			$e->setDescription($obj->getDescription());
			$e->setStart($obj->getDateStart());
			$e->setEnd($obj->getDateEnd());
			//$e->setCategory($ec);
			$em->persist($e);
			$em->flush();
		}
	}

	public function preRemove(LifecycleEventArgs $args)
	{
		$obj = $args->getEntity();
		$em = $args->getEntityManager();
		if ($obj instanceof Activity)
		{
			$rep = $em->getRepository('BladeTesterCalendarBundle:Event');
			//$e = $rep->findByTitle($obj->getName());
			//$em->remove($e);
			//$em->flush();
		}
	}
}
