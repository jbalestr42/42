#include "ScavTrap.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ENERGY_COST 25

ScavTrap::ScavTrap(void) :
	m_Name(""),
	m_nHitPoints(100),
	m_nMaxHitPoints(100),
	m_nEnergyPoints(50),
	m_nMaxEnergyPoints(50),
	m_nLevel(1),
	m_nMeleeAttackDamage(20),
	m_nRangedAttackDamage(15),
	m_nArmorDamageReduction(3)
{
	std::cout << "Constructor: A new ScavTrap(" << this->m_Name << ") is born !" << std::endl;
}

ScavTrap::ScavTrap(std::string p_Name) :
	m_Name(p_Name),
	m_nHitPoints(100),
	m_nMaxHitPoints(100),
	m_nEnergyPoints(50),
	m_nMaxEnergyPoints(50),
	m_nLevel(1),
	m_nMeleeAttackDamage(20),
	m_nRangedAttackDamage(15),
	m_nArmorDamageReduction(3)
{
	std::cout << "Constructor: A new ScavTrap(" << this->m_Name << ") is born !" << std::endl;
	srand(time(0));
}

ScavTrap::ScavTrap(ScavTrap const & p_ScavTrap)
{
	std::cout << "Constructor copy: A new ScavTrap(" << this->m_Name << ") is born !" << std::endl;
	*this = p_ScavTrap;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor: A ScavTrap is dead..." << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & p_ScavTrap)
{
	std::cout << "Assignation" << std::endl;
	this->m_Name = p_ScavTrap.m_Name;
	this->m_nHitPoints = p_ScavTrap.m_nHitPoints;
	this->m_nMaxHitPoints = p_ScavTrap.m_nMaxHitPoints;
	this->m_nEnergyPoints = p_ScavTrap.m_nEnergyPoints;
	this->m_nMaxEnergyPoints = p_ScavTrap.m_nMaxEnergyPoints;
	this->m_nLevel = p_ScavTrap.m_nLevel;
	this->m_nMeleeAttackDamage = p_ScavTrap.m_nMeleeAttackDamage;
	this->m_nRangedAttackDamage = p_ScavTrap.m_nRangedAttackDamage;
	this->m_nArmorDamageReduction = p_ScavTrap.m_nArmorDamageReduction;
	return (*this);
}

void ScavTrap::rangedAttack(std::string const & p_Target)
{
	std::cout << "SC4V-TP (" << this->m_Name << ") attacks " << p_Target << " at range, causing " << this->m_nRangedAttackDamage << " points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & p_Target)
{
	std::cout << "SC4V-TP (" << this->m_Name << ") attacks " << p_Target << " at melee, causing " << this->m_nMeleeAttackDamage << " points of damage !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int p_nAmount)
{
	std::cout << "SC4V-TP (" << this->m_Name << ") take " << p_nAmount << " point of damage !" << std::endl;
	this->addHitPoint(-p_nAmount + this->m_nArmorDamageReduction);
	std::cout << "Current hit points : " << this->m_nHitPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int p_nAmount)
{
	std::cout << "SC4V-TP (" << this->m_Name << ") recover " << p_nAmount << " hit point !" << std::endl;
	this->addHitPoint(p_nAmount);
	std::cout << "Current hit points : " << this->m_nHitPoints << std::endl;
}

void ScavTrap::addHitPoint(int p_nAmount)
{
	this->m_nHitPoints += p_nAmount;
	if (this->m_nHitPoints > this->m_nMaxHitPoints)
		this->m_nHitPoints = this->m_nMaxHitPoints;
	if (this->m_nHitPoints < 0)
		this->m_nHitPoints = 0;
}

void ScavTrap::challengeNewcomer(void)
{
	std::string challenges[] =
	{
		"Catch the SC4V-TP",
		"Find the energy",
		"Kill Dr Zed",
		"I Nuke you",
		"I Dare you! I double Dare you!!",
	};

	if (this->m_nEnergyPoints >= ENERGY_COST)
	{
		std::cout << "SC4V-TP (" << this->m_Name << ") challenge you with " << challenges[rand() % 4 + 1] << std::endl;
		this->m_nEnergyPoints -= ENERGY_COST;
	}
	else
		std::cout << "Not enough energy !" << std::endl;
}

