<?php

require_once('Player.class.php');

final class Board {

	private $_players;
	private $_nbPlayer;

	public function __construct() {
		$this->_players = array();
		$this->_nbPlayer = 0;
	}

	public function getNbPlayer()	{ return $this->_nbPlayer; }
	public function getPlayer()		{ return $this->_players; }

	public function addPlayer($player) {
		if ($player instanceof Player)
		{
			$this->_nbPlayer++;
			$this->_players[] = $player;
		}
	}
}

?>
