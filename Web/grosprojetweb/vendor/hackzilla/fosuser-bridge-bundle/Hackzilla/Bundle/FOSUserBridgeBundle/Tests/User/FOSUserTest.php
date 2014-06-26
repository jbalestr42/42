<?php

namespace Hackzilla\Bundle\FOSUserBridgeBundle\Tests\User;

use Symfony\Bundle\FrameworkBundle\Test\WebTestCase;

class FOSUserTest extends WebTestCase
{
    private $_object;

    public function setUp()
    {
        $container = $this->getMockContainer();
        $this->_object = new \Hackzilla\Bundle\FOSUserBridgeBundle\User\FOSUser($container);
    }

    public function tearDown()
    {
        unset($this->_object);
    }

    public function testObjectCreated()
    {
        $this->assertTrue(\is_object($this->_object));
    }

    private function getMockContainer()
    {
        $container = $this->getMock('Symfony\Component\DependencyInjection\Container');
        $container->expects($this->exactly(2))
                    ->method('get')
                    ->will($this->returnCallback(array($this, 'getServiceMock')));

        return $container;
    }

    public function getServiceMock($serviceName)
    {
        if ($serviceName == 'security.context') {
            $service = $this->getMockSecurity();
        } else if ($serviceName == 'user.manager') {
            $service = $this->getMockUserManager();
        } else {
            $service = false;
        }

        return $service;
    }
    
    private function getMockSecurity()
    {
        $security = $this->getMock('stdClass');

        return $security;
    }

    private function getMockUserManager()
    {
        $userManager = $this->getMock('stdClass');

        return $userManager;
    }
}

