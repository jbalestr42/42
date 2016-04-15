<?php

require_once('Color.class.php');

Class Vertex {

	private $_x;
	private $_y;
	private $_z;
	private $_w;
	private $_color;
	public static $verbose = false;

	public function __construct(array $kwargs) {
		$this->_x = $kwargs['x'];
		$this->_y = $kwargs['y'];
		$this->_z = $kwargs['z'];
		if (array_key_exists('w', $kwargs))
			$this->_w = $kwargs['w'];
		else
			$this->_w = 1.0;
		if (array_key_exists('color', $kwargs))
			$this->_color = clone $kwargs['color'];
		else
			$this->_color = new Color(array('rgb' => (255 << 16) + (255 << 8) + 255));
		if (self::$verbose)
			printf("Vertex( x: %3.2f, y: %3.2f, z:%3.2f, w:%3.2f, %s ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
	}

	public function __destruct() {
		if (self::$verbose)
			printf("Vertex( x: %3.2f, y: %3.2f, z:%3.2f, w:%3.2f, %s ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
	}

	public function __toString() {
		if (self::$verbose)
			return sprintf("Vertex( x: %3.2f, y: %3.2f, z:%3.2f, w:%3.2f, %s )", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
		else
			return sprintf("Vertex( x: %3.2f, y: %3.2f, z:%3.2f, w:%3.2f )", $this->_x, $this->_y, $this->_z, $this->_w);
	}

	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }
	public function getColor() { return $this->_color; }
	public function setX($x) { $this->_x = $x; }
	public function setY($y) { $this->_y = $y; }
	public function setZ($z) { $this->_z = $z; }
	public function setW($w) { $this->_w = $w; }
	public function setColor(Color $color) { $this->_color = $color; }

	public static function doc() {
		if (file_exists("Vertex.doc.txt"))
		{
			$doc = file_get_contents("Vertex.doc.txt");
			return $doc;
		}
		return;
	}
}

?>
