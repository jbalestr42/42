<?php

require_once('Vertex.class.php');

Class Vector {

	private $_x;
	private $_y;
	private $_z;
	private $_w;
	public static $verbose = false;

	public function __construct(array $kwargs) {
		if (array_key_exists('x', $kwargs) && array_key_exists('y', $kwargs) && array_key_exists('z', $kwargs))
		{
			$this->_x = $kwargs['x'];
			$this->_y = $kwargs['y'];
			$this->_z = $kwargs['z'];
		}
		else
		{
			$dest = $kwargs['dest'];
			if (array_key_exists('orig', $kwargs))
				$orig = $kwargs['orig'];
			else
				$orig = new Vertex(array('x' => 0, 'y' => 0, 'z' => 0, 'w' => 1));
			$this->_x = $dest->getX() - $orig->getX();
			$this->_y = $dest->getY() - $orig->getY();
			$this->_z = $dest->getZ() - $orig->getZ();
		}
		$this->_w = 0.0;
		if (self::$verbose)
			printf("Vector( x:%3.2f, y:%3.2f, z:%3.2f, w:%3.2f ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
	}

	public function __destruct() {
		if (self::$verbose)
			printf("Vector( x:%3.2f, y:%3.2f, z:%3.2f, w:%3.2f ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
	}

	public function __toString() {
		return sprintf("Vector( x:%3.2f, y:%3.2f, z:%3.2f, w:%3.2f )", $this->_x, $this->_y, $this->_z, $this->_w);
	}

	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }

	public static function doc() {
		if (file_exists("Vector.doc.txt"))
		{
			$doc = file_get_contents("Vector.doc.txt");
			return $doc;
		}
		return;
	}

	public function magnitude() {
		return (sqrt($this->_x * $this->_x + $this->_y * $this->_y + $this->_z * $this->_z));
	}

	public function normalize() {
		$l = $this->magnitude();
		if ($l)
			return new Vector(array('x' => $this->_x / $l,  'y' => $this->_y / $l,  'z' => $this->_z / $l));
	}

	public function add(Vector $rhs) {
		return new Vector(array('x' => $this->_x + $rhs->getX(),  'y' => $this->_y + $rhs->getY(),  'z' => $this->_z + $rhs->getZ()));
	}

	public function sub(Vector $rhs) {
		return new Vector(array('x' => $this->_x - $rhs->getX(), 'y' => $this->_y - $rhs->getY(), 'z' => $this->_z - $rhs->getZ()));
	}

	public function opposite() {
		return new Vector(array('x' => -$this->_x, 'y' => -$this->_y, 'z' => -$this->_z));
	}

	public function scalarProduct($k) {
		return new Vector(array('x' => $this->_x * $k,  'y' => $this->_y * $k,  'z' => $this->_z * $k));
	}

	public function dotProduct(Vector $rhs) {
		return ($this->_x * $rhs->getX() + $this->_y * $rhs->getY() + $this->_z * $rhs->getZ());
	}

	public function crossProduct(Vector $rhs) {
		return new Vector(array('x' => ($this->_y * $rhs->getZ() - $this->_z * $rhs->getY()),
								'y' => ($this->_z * $rhs->getX() - $this->_x * $rhs->getZ()),
								'z' => ($this->_x * $rhs->getY() - $this->_y * $rhs->getX())));
	}

	private function _length() {
		return ($this->_x * $this->_x + $this->_y * $this->_y + $this->_z * $this->_z);
	}

	public function cos(Vector $rhs) {
		return (($this->_x * $rhs->getX() + $this->_y * $rhs->getY() + $this->_z * $rhs->getZ()) / sqrt($this->_length() * $rhs->_length()));
	}
}

?>
