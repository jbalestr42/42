<?php

namespace Hackzilla\Interfaces\User;

interface UserInterface
{
	public function getCurrentUser();
	public function getUserById($userId);
	public function hasRole($user, $role);
}
