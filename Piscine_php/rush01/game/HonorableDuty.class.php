<?php

include_once('Ship.class.php');

final class HonorableDuty extends Ship {

	public function __construct(array $pos, $dir) {
		parent::__construct("Honorable Duty", 5, 10, 15, 0, array("width" => 4, "height" => 1), $pos, "http://placehold.it/57x14", array(null, null), $dir, 100, Ship::IMPERIUM);
	}

	public function shoot($target) {
		return True;
	}
}

?>
