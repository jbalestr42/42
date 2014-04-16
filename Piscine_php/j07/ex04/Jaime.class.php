<?php

Class Jaime extends Lannister {

	public function sleepWith($l) {
		if (get_parent_class(get_class($l)) == "Lannister")
		{
			if (get_class($l) == "Cersei")
				print("With pleasure, but only in a tower in Winterfell, then.\n");
			else
				print("Not even if I'm drunk !\n");
		}
		else
			print("Let's do this.\n");
	}
}

?>
