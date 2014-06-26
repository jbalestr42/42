<?php

use Symfony\Component\HttpKernel\Kernel;
use Symfony\Component\Config\Loader\LoaderInterface;

class AppKernel extends Kernel
{
    public function registerBundles()
    {
        $bundles = array(
            new Symfony\Bundle\FrameworkBundle\FrameworkBundle(),
            new Symfony\Bundle\SecurityBundle\SecurityBundle(),
            new Symfony\Bundle\TwigBundle\TwigBundle(),
            new Symfony\Bundle\MonologBundle\MonologBundle(),
            new Symfony\Bundle\SwiftmailerBundle\SwiftmailerBundle(),
            new Symfony\Bundle\AsseticBundle\AsseticBundle(),
            new Doctrine\Bundle\DoctrineBundle\DoctrineBundle(),
            new Sensio\Bundle\FrameworkExtraBundle\SensioFrameworkExtraBundle(),
            new philemon\HomeBundle\philemonHomeBundle(),
            new philemon\UserBundle\philemonUserBundle(),
            new JMS\AopBundle\JMSAopBundle(),
            new JMS\SecurityExtraBundle\JMSSecurityExtraBundle(),
            new JMS\DiExtraBundle\JMSDiExtraBundle($this),
            new FOS\UserBundle\FOSUserBundle(),
            new Sonata\DoctrineORMAdminBundle\SonataDoctrineORMAdminBundle(),
            new Sonata\CoreBundle\SonataCoreBundle(),
            new Sonata\BlockBundle\SonataBlockBundle(),
            new Knp\Bundle\MenuBundle\KnpMenuBundle(),
            new Sonata\AdminBundle\SonataAdminBundle(),
            new Knp\Bundle\PaginatorBundle\KnpPaginatorBundle(),
			new CCDNForum\ForumBundle\CCDNForumForumBundle(),
			new FR3D\LdapBundle\FR3DLdapBundle(),
            new Hackzilla\Bundle\FOSUserBridgeBundle\HackzillaFOSUserBridgeBundle(),
            new Hackzilla\Bundle\TicketBundle\HackzillaTicketBundle(),
            new philemon\LdapBundle\philemonLdapBundle(),
            new philemon\ModuleBundle\philemonModuleBundle(),
			new philemon\FtCalendarBundle\philemonFtCalendarBundle(),
			new BladeTester\CalendarBundle\BladeTesterCalendarBundle(),
      new philemon\TrombiBundle\philemonTrombiBundle(),
        );

        if (in_array($this->getEnvironment(), array('dev', 'test'))) {
            $bundles[] = new Symfony\Bundle\WebProfilerBundle\WebProfilerBundle();
            $bundles[] = new Sensio\Bundle\DistributionBundle\SensioDistributionBundle();
            $bundles[] = new Sensio\Bundle\GeneratorBundle\SensioGeneratorBundle();
        }

        return $bundles;
    }

    public function registerContainerConfiguration(LoaderInterface $loader)
    {
        $loader->load(__DIR__.'/config/config_'.$this->getEnvironment().'.yml');
    }

	public function __construct($environment, $debug)
	{
	    date_default_timezone_set( 'Europe/Paris' );
	    parent::__construct($environment, $debug);
	}
}
