<?php

namespace philemon\UserBundle;

use Symfony\Component\HttpKernel\Bundle\Bundle;

class philemonUserBundle extends Bundle
{
	public function getParent()
	{
		return 'FOSUserBundle';
	}
}
