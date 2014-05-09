<?php

class FT_Form_validation extends CI_Form_validation
{
	function __construct($config = array())
	{
		parent::__construct($config);
	}

	function error_array()
	{
		if (count($this->_error_array) === 0)
			return array();
		else
			return $this->_error_array;
	}
}

?>
