<?php

abstract Class Fighter {

	public $class;
	public function __construct($class) {
		$this->class = $class;
	}

	abstract public function fight($target);
}

?>
