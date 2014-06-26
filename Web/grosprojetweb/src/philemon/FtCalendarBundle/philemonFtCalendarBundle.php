<?php

namespace philemon\FtCalendarBundle;

use Symfony\Component\HttpKernel\Bundle\Bundle;

class philemonFtCalendarBundle extends Bundle
{
	public function getParent()
	{
		return 'BladeTesterCalendarBundle';
	}
}
