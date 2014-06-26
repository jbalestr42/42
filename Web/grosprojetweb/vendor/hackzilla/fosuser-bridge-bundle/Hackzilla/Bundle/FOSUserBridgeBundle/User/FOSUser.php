<?php

namespace Hackzilla\Bundle\FOSUserBridgeBundle\User;

class FOSUser implements \Hackzilla\Interfaces\User\UserInterface
{
    private $securityContext;
    private $userManager;

    function __construct($container)
    {
        $this->securityContext = $container->get('security.context');
        $this->userManager = $container->get('fos_user.user_manager');
    }

    public function getCurrentUser()
    {
        $user = $this->securityContext->getToken()->getUser();

        return $user;
    }

    public function getUserById($userId)
    {
        $user = $this->userManager->findUserBy(array(
            'id' => $userId,
        ));

        return $user;
    }

    public function hasRole($user, $role)
    {
        return $user->hasRole($role);
    }
}
