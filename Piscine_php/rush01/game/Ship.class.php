<?php

abstract class Ship {

	const NORTH = 1;
	const SOUTH = 2;
	const EAST = 3;
	const WEST = 4;
	const IMPERIUM = "Imperium";
	const ORKS = "Orks";
	const NECRON = "Necron";

	static private $_count = 0;

	protected $_pos;
	protected $_dir;
	protected $_size;
	protected $_pv;
	protected $_pp;
	protected $_speed;
	protected $_shield;
	protected $_weapons;
	protected $_name;
	protected $_sprite;
	protected $_cost;
	protected $_faction;
	protected $_width;
	protected $_height;

	public function __construct($name, $pv, $pp, $speed, $shield, array $size, array $pos, $sprite, array $weapons, $dir, $cost, $faction) {
		$this->_name = $name;
		$this->_pv = $pv;
		$this->_pp = $pp;
		$this->_speed = $speed;
		$this->_shield = $shield;
		$this->_size = array("width" => $size['width'] * 14, "height" => $size['height'] * 14);
		$this->_pos = array("x" => $pos['x'] * 14, "y" => $pos['y'] * 14);
		$this->_sprite = $sprite;
		$this->_weapons = $weapons;
		$this->_dir = $dir;
		$this->_cost = $cost;
		$this->_faction = $faction;
		$this->_width = $size['width'] * 14;
		$this->_height = $size['height'] * 14;
		self::$_count += 1;
	}

	public function __destruct() {
		self::$_count -= 1;
	}

	public function __get($name) {
		echo "Requested attribute does not exist or is not available : $name";
	}

	public function __set($att, $val) {
		echo "Requested attribute does not exist or is not available : $att / $val";
	}

	public function __call($name, $args) {
		echo "Requested attribute does not exist or is not available : $name";
	}

	public static function __callStatic($name, $args) {
		echo "Requested attribute does not exist or is not available : $name";
	}

	public function __toString() {
		$mirror = new ReflectionClass;
		return (implode("\n", $mirror->getProperties()));
	}

	public static function doc() {
		$path = __CLASS__ . ".doc.txt";
		return (file_get_contents($path));
	}

	public function getName()			{ return ($this->_name); }
	public function getPos()			{ return ($this->_pos); }
	public function getDir()			{ return ($this->_dir); }
	public function getSize()			{ return ($this->_size); }
	public function getPv()				{ return ($this->_pv); }
	public function getPp()				{ return ($this->_pp); }
	public function getSpeed()			{ return ($this->_speed); }
	public function getShield()			{ return ($this->_shield); }
	public function getSprite()			{ return ($this->_sprite); }
	public function getWeapons()		{ return ($this->_weapons); }
	public function getCost()			{ return ($this->_cost); }
	public function getFaction()		{ return ($this->_faction); }
	public function getCount()			{ return (self::$_count); }

	public function setPos($val)		{ $this->_pos = $val; }
	public function setDir($val)		{ $this->_dir = $val; }
	public function setPv($val)			{ $this->_pv = $val; }
	public function setPp($val)			{ $this->_pp = $val; }
	public function setSpeed($val)		{ $this->_speed = $val; }
	public function setSprite($val)		{ $this->_sprite = $val; }

	public abstract function shoot($target);
	public function turn($dir) {
		if ($dir == "top")
			$this->_dir = self::NORTH;
		if ($dir == "bot")
			$this->_dir = self::SOUTH;
		if ($dir == "right")
			$this->_dir = self::EAST;
		if ($dir == "left")
			$this->_dir = self::WEST;
		if ($this->_dir == self::SOUTH || $this->_dir == self::NORTH)
		{
			$this->_sprite = "http://placehold.it/".($this->_size['height'])."x".$this->_size['width'];
			$w = $this->_width;
			$h = $this->_height;
			$this->_size['width'] = $h;
			$this->_size['height'] = $w;
		}
		else if ($this->_dir == self::EAST || $this->_dir == self::WEST)
		{
			$this->_sprite = "http://placehold.it/".($this->_size['width'])."x".$this->_size['height'];
			$w = $this->_width;
			$h = $this->_height;
			$this->_size['width'] = $w;
			$this->_size['height'] = $h;
		}
	}
}
