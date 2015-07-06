#include "FragTrap.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ENERGY_COST 25

FragTrap::FragTrap(void) :
	m_Name(""),
	m_nHitPoints(100),
	m_nMaxHitPoints(100),
	m_nEnergyPoints(100),
	m_nMaxEnergyPoints(100),
	m_nLevel(1),
	m_nMeleeAttackDamage(30),
	m_nRangedAttackDamage(20),
	m_nArmorDamageReduction(5)
{
	std::cout << "Constructor: A new FragTrap(" << this->m_Name << ") is born !" << std::endl;
}

FragTrap::FragTrap(std::string p_Name) :
	m_Name(p_Name),
	m_nHitPoints(100),
	m_nMaxHitPoints(100),
	m_nEnergyPoints(100),
	m_nMaxEnergyPoints(100),
	m_nLevel(1),
	m_nMeleeAttackDamage(30),
	m_nRangedAttackDamage(20),
	m_nArmorDamageReduction(5)
{
	std::cout << "Constructor: A new FragTrap(" << this->m_Name << ") is born !" << std::endl;
	srand(time(0));
}

FragTrap::FragTrap(FragTrap const & p_FragTrap)
{
	std::cout << "Constructor copy: A new FragTrap(" << this->m_Name << ") is born !" << std::endl;
	*this = p_FragTrap;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor: A FragTrap is dead..." << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & p_FragTrap)
{
	std::cout << "Assignation" << std::endl;
	this->m_Name = p_FragTrap.m_Name;
	this->m_nHitPoints = p_FragTrap.m_nHitPoints;
	this->m_nMaxHitPoints = p_FragTrap.m_nMaxHitPoints;
	this->m_nEnergyPoints = p_FragTrap.m_nEnergyPoints;
	this->m_nMaxEnergyPoints = p_FragTrap.m_nMaxEnergyPoints;
	this->m_nLevel = p_FragTrap.m_nLevel;
	this->m_nMeleeAttackDamage = p_FragTrap.m_nMeleeAttackDamage;
	this->m_nRangedAttackDamage = p_FragTrap.m_nRangedAttackDamage;
	this->m_nArmorDamageReduction = p_FragTrap.m_nArmorDamageReduction;
	return (*this);
}

void FragTrap::rangedAttack(std::string const & p_Target)
{
	std::cout << "FR4G-TP (" << this->m_Name << ") attacks " << p_Target << " at range, causing " << this->m_nRangedAttackDamage << " points of damage !" << std::endl;
}

void FragTrap::meleeAttack(std::string const & p_Target)
{
	std::cout << "FR4G-TP (" << this->m_Name << ") attacks " << p_Target << " at melee, causing " << this->m_nMeleeAttackDamage << " points of damage !" << std::endl;
}

void FragTrap::takeDamage(unsigned int p_nAmount)
{
	std::cout << "FR4G-TP (" << this->m_Name << ") take " << p_nAmount << " point of damage !" << std::endl;
	this->addHitPoint(-p_nAmount + this->m_nArmorDamageReduction);
	std::cout << "Current hit points : " << this->m_nHitPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int p_nAmount)
{
	std::cout << "FR4G-TP (" << this->m_Name << ") recover " << p_nAmount << " hit point !" << std::endl;
	this->addHitPoint(p_nAmount);
	std::cout << "Current hit points : " << this->m_nHitPoints << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & p_Target)
{
	std::string attacks[] =
	{
		"Second Wind",
		"Hyperion Punch",
		"Rainbow Coolant",
		"Cryogenic Exhaust Manifold",
		"Killbot",
	};

	if (this->m_nEnergyPoints >= ENERGY_COST)
	{
		std::cout << "FR4G-TP (" << this->m_Name << ") attacks " << p_Target << " with " << attacks[rand() % 4 + 1] << std::endl;
		this->m_nEnergyPoints -= ENERGY_COST;
	}
	else
		std::cout << "Not enough energy !" << std::endl;
}

void FragTrap::addHitPoint(int p_nAmount)
{
	this->m_nHitPoints += p_nAmount;
	if (this->m_nHitPoints > this->m_nMaxHitPoints)
		this->m_nHitPoints = this->m_nMaxHitPoints;
	if (this->m_nHitPoints < 0)
		this->m_nHitPoints = 0;
}

