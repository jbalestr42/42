<?php

Class UnholyFactory {

	private $_classes;
	public function __construct() {
		$this->_classes = array();
	}

	public function absorb($f) {
		$bool = 0;
		if (get_parent_class($f) == "Fighter")
		{
			foreach ($this->_classes as $k => $v)
			{
				if ($v == get_class($f))
				{
					$bool = 1;
					break;
				}
			}
			if ($bool)
				print("(Factory already absorbed a fighter of type ".$f->class.")\n");
			else
			{
				$this->_classes[$f->class] = get_class($f);
				print("(Factory absorbed a fighter of type ".$f->class.")\n");
			}
		}
		else
			print("(Factory can't absorb this, it's not a fighter)\n");
	}

	public function fabricate($f) {
		if (array_key_exists($f, $this->_classes))
		{
			$tmp = new $this->_classes[$f];
			$this->_classes[] = $tmp;
			print("(Factory fabricates a fighter of type $f)\n");
			return ($tmp);
		}
		print("(Factory hasn't absorbed any fighter of type $f)\n");
		return (null);
	}
}

?>
