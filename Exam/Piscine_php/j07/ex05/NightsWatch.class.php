<?php

Class NightsWatch implements IFighter{

	private $_all;

	public function __construct() {
		$this->_all = array();
	}

	public function recruit($p) {
		if (isset(class_implements($p)['IFighter']))
			$this->_all[] = $p;
	}

	public function fight() {
		foreach ($this->_all as $p) {
				$p->fight();
		}
	}
}

?>
