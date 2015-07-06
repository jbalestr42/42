<?php

require_once('Vertex.class.php');

Class Matrix {
	const IDENTITY = 1;
	const SCALE = 2;
	const RX = 3;
	const RY = 4;
	const RZ = 5;
	const TRANSLATION = 6;
	const PROJECTION = 7;
	private $_matrix;
	public static $verbose = false;

	public function __construct(array $kwargs) {
		if (array_key_exists('preset', $kwargs))
		{
			if ($kwargs['preset'] == self::SCALE)
			{
				if (array_key_exists('scale', $kwargs))
					$this->_init_scale($kwargs['scale']);
				else
					exit();
			}
			else if ($kwargs['preset'] == self::RX || $kwargs['preset'] == self::RY || $kwargs['preset'] == self::RZ)
			{
				if (array_key_exists('angle', $kwargs))
				{
					if ($kwargs['preset'] == self::RX)
						$this->_init_rx($kwargs['angle']);
					if ($kwargs['preset'] == self::RY)
						$this->_init_ry($kwargs['angle']);
					if ($kwargs['preset'] == self::RZ)
						$this->_init_rz($kwargs['angle']);
				}
				else
					exit();
			}
			else if ($kwargs['preset'] == self::TRANSLATION)
			{
				if (array_key_exists('vtc', $kwargs))
					$this->_init_translation($kwargs['vtc']);
				else
					exit();
			}
			else if ($kwargs['preset'] == self::PROJECTION)
			{
				if (array_key_exists('fov', $kwargs) && array_key_exists('ratio', $kwargs) && array_key_exists('near', $kwargs) && array_key_exists('far', $kwargs))
					$this->_init_projection($kwargs['fov'], $kwargs['ratio'], $kwargs['near'], $kwargs['far']);
				else
					exit();
			}
			else if ($kwargs['preset'] == self::IDENTITY)
				$this->_init_identity();
		}
		else
			exit();
	}

	public function __destruct() {
		if (self::$verbose)
			print("Matrix instance destructed\n");
	}

	public function __toString() {
		$ret = sprintf("M | vtcX | vtcY | vtcZ | vtxO\n");
		$ret .= sprintf("-----------------------------\n");
		$ret .= sprintf("x | %3.2f | %3.2f | %3.2f | %3.2f\n", $this->_matrix[0][0], $this->_matrix[0][1], $this->_matrix[0][2], $this->_matrix[0][3]);
		$ret .= sprintf("y | %3.2f | %3.2f | %3.2f | %3.2f\n", $this->_matrix[1][0], $this->_matrix[1][1], $this->_matrix[1][2], $this->_matrix[1][3]);
		$ret .= sprintf("z | %3.2f | %3.2f | %3.2f | %3.2f\n", $this->_matrix[2][0], $this->_matrix[2][1], $this->_matrix[2][2], $this->_matrix[2][3]);
		$ret .= sprintf("w | %3.2f | %3.2f | %3.2f | %3.2f", $this->_matrix[3][0], $this->_matrix[3][1], $this->_matrix[3][2], $this->_matrix[3][3]);
		return ($ret);
	}

	public static function doc() {
		if (file_exists("Matrix.doc.txt"))
		{
			$doc = file_get_contents("Matrix.doc.txt");
			return $doc;
		}
		return;
	}

	private function _init_identity() {
		$this->_matrix = array(
			array(1, 0, 0, 0),
			array(0, 1, 0, 0),
			array(0, 0, 1, 0),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix IDENTITY instance constructed\n");
	}

	private function _init_translation(Vector $translation) {
		$this->_matrix = array(
			array(1, 0, 0, $translation->getX()),
			array(0, 1, 0, $translation->getY()),
			array(0, 0, 1, $translation->getZ()),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix TRANSLATION preset instance constructed\n");
	}

	private function _init_scale($scale) {
		$this->_matrix = array(
			array($scale, 0, 0, 0),
			array(0, $scale, 0, 0),
			array(0, 0, $scale, 0),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix SCALE preset instance constructed\n");
	}

	private function _init_rx($angle) {
		$this->_matrix = array(
			array(1, 0, 0, 0),
			array(0, cos($angle), -sin($angle), 0),
			array(0, sin($angle), cos($angle), 0),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix Ox ROTATION preset instance constructed\n");
	}

	private function _init_ry($angle) {
		$this->_matrix = array(
			array(cos($angle), 0, sin($angle), 0),
			array(0, 1, 0, 0),
			array(-sin($angle), 0, cos($angle), 0),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix Oy ROTATION preset instance constructed\n");
	}

	private function _init_rz($angle) {
		$this->_matrix = array(
			array(cos($angle), -sin($angle), 0, 0),
			array(sin($angle), cos($angle), 0, 0),
			array(0, 0, 1, 0),
			array(0, 0, 0, 1));
		if (self::$verbose)
			print("Matrix Oz ROTATION preset instance constructed\n");
	}

	private function _degToRad($angle) {
		return (($angle * pi()) / 180);
	}

	private function _init_projection($fov, $ratio, $near, $far) {
		$this->_matrix = array(
			array((1 / tan($this->_degToRad($fov * 0.5))) / $ratio, 0, 0, 0),
			array(0, 1 / tan($this->_degToRad($fov * 0.5)), 0, 0),
			array(0, 0, -$far * (1 / ($far - $near)), -1 - ($far * $near) * (1 / ($far - $near))),
			array(0, 0, -1, 0));
		if (self::$verbose)
			print("Matrix PROJECTION preset instance constructed\n");
	}

	public function mult(Matrix $rhs) {
		$res = clone $this;
		$i = -1;
		while (++$i < 4)
		{
			$j = -1;
			while (++$j < 4)
			{
				$k = -1;
				$sum = 0;
				while (++$k < 4)
					$sum += $this->_matrix[$i][$k] * $rhs->_matrix[$k][$j];
				$res->_matrix[$i][$j] = $sum;
			}
		}
		return ($res);
	}

	public function transformVertex(Vertex $vtx) {
		return new Vertex(array(
			'x' => ($this->_matrix[0][0] * $vtx->getX() + $this->_matrix[0][1] * $vtx->getY() + $this->_matrix[0][2] * $vtx->getZ() + $this->_matrix[0][3] * $vtx->getW()),
			'y' => ($this->_matrix[1][0] * $vtx->getX() + $this->_matrix[1][1] * $vtx->getY() + $this->_matrix[1][2] * $vtx->getZ() + $this->_matrix[1][3] * $vtx->getW()),
			'z' => ($this->_matrix[2][0] * $vtx->getX() + $this->_matrix[2][1] * $vtx->getY() + $this->_matrix[2][2] * $vtx->getZ() + $this->_matrix[2][3] * $vtx->getW()),
			'w' => ($this->_matrix[3][0] * $vtx->getX() + $this->_matrix[3][1] * $vtx->getY() + $this->_matrix[3][2] * $vtx->getZ() + $this->_matrix[3][3] * $vtx->getW()),
			'color' => $vtx->getColor()));
	}
}

?>
