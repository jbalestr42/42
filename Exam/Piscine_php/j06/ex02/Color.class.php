<?php

Class Color {

	public $red;
	public $green;
	public $blue;
	public static $verbose = False;

	public function __construct(array $kwargs) {
		if (array_key_exists('rgb', $kwargs))
		{
			$this->red = intval(($kwargs['rgb'] >> 16) % 256);
			$this->green = intval(($kwargs['rgb'] >> 8) % 256);
			$this->blue = intval($kwargs['rgb'] % 256);
		}
		else
		{
			if (array_key_exists('red', $kwargs))
				$this->red = intval($kwargs['red']);
			else
				$this->red = 0;
			if (array_key_exists('green', $kwargs))
				$this->green = intval($kwargs['green']);
			else
				$this->red = 0;
			if (array_key_exists('blue', $kwargs))
				$this->blue = intval($kwargs['blue']);
			else
				$this->red = 0;
		}
		if (self::$verbose)
			printf("Color( red: %3.3s, green: %3.3s, blue: %3.3s ) constructed.\n", $this->red, $this->green, $this->blue);
		return;
	}

	public function __destruct() {
		if (self::$verbose)
			printf("Color( red: %3.3s, green: %3.3s, blue: %3.3s ) destructed.\n", $this->red, $this->green, $this->blue);
		return;
	}

	public function __toString() {
		return sprintf("Color( red: %3.3s, green: %3.3s, blue: %3.3s )", $this->red, $this->green, $this->blue);
	}

	public function add(Color $rhs) {
		$color = new Color(array(
			'red' => $this->red + $rhs->red,
			'green' => $this->green + $rhs->green,
			'blue' => $this->blue + $rhs->blue));
		return $color;
	}

	public function sub(Color $rhs) {
		$color = new Color(array(
			'red' => $this->red - $rhs->red,
			'green' => $this->green - $rhs->green,
			'blue' => $this->blue - $rhs->blue));
		return $color;
	}

	public function mult($f) {
		$color = new Color(array(
			'red' => $this->red * $f,
			'green' => $this->green * $f,
			'blue' => $this->blue * $f));
		return $color;
	}

	public static function doc() {
		if (file_exists("Color.doc.txt"))
		{
			$doc = file_get_contents("Color.doc.txt");
			return $doc;
		}
		return;
	}
}

?>
