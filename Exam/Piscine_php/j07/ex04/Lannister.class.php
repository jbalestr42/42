<?php

abstract Class Lannister {

	public function sleepWith($l) {
		if (get_parent_class(get_class($l)) == "Lannister")
			print("Not even if I'm drunk !\n");
		else
			print("Let's do this.\n");
	}
}

?>
