<?php

Class House {

	public function introduce() {
		print("House ".static::getHouseName());
		print(" of ".static::getHouseSeat());
		print(" : \"".static::getHouseMotto()."\"\n");
	}
}

?>
