<?php

abstract class Weapon {

	protected $_load;
	protected $_range;

	public function __construct($load, array $range) {
		$this->_load = $load;
		$this->_range = $range;
	}

	public static function doc() {
		$path = __CLASS__ . ".doc.txt";
		return (file_get_contents($path));
	}

	public function __toString() {
		return get_class($this);
	}

	public function getLoad()	{ return $this->_load; }
	public function getRange()	{ return $this->_range; }

	public abstract function shoot(array $dir);
	public abstract function areaEffect();
}

?>
