<?php

include_once('Ship.class.php');

final class Player {

	private $_fleet;
	private $_money;
	private $_current;
	private $_login;

	public function __construct($login, $money = 500) {
		$this->_fleet = array();
		$this->_money = $money;
		$this->_current = 0;
		$this->_login = $login;
	}

	public function getFleet() { return $this->_fleet; }
	public function getMoney() { return $this->_money; }
	public function getLogin() { return $this->_login; }

	public function addShip(Ship $s) {
		if ($this->_current + $s->getCost() < $this->_money)
		{
			$this->_fleet[] = $s;
			$this->_current += $s->getCost();
			return True;
		}
		return False;
	}
}

?>
