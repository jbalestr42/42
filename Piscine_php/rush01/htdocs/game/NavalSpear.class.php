<?php

require_once("Weapon.class.php");

class NavalSpear extends Weapon {

	// add treat for special behaviour

	public function __construct() {
		parent::__construct(0, array("short" => 30, "middle" => 60, "long" => 90));
	}

	public function shoot(array $target) {
	}

	public function areaEffect() {

	}
}

?>
