#include "ClapTrap.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

ClapTrap::ClapTrap(void) :
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
	std::cout << "Constructor: A new ClapTrap(" << this->m_Name << ") is born !" << std::endl;
}

ClapTrap::ClapTrap(std::string p_Name, int p_nHitPoints, int p_nMaxHitPoints, int p_nEnergyPoints, int p_nMaxEnergyPoint, int p_nMeleeAttackDamage, int p_nRangedAttackDamage, int p_nArmorDamageReduction) :
	m_Name(p_Name),
	m_nHitPoints(p_nHitPoints),
	m_nMaxHitPoints(p_nMaxHitPoints),
	m_nEnergyPoints(p_nEnergyPoints),
	m_nMaxEnergyPoints(p_nMaxEnergyPoint),
	m_nLevel(1),
	m_nMeleeAttackDamage(p_nMeleeAttackDamage),
	m_nRangedAttackDamage(p_nRangedAttackDamage),
	m_nArmorDamageReduction(p_nArmorDamageReduction)
{
	std::cout << "Constructor: A new ClapTrap(" << this->m_Name << ") is born !" << std::endl;
	srand(time(0));
}

ClapTrap::ClapTrap(ClapTrap const & p_ClapTrap)
{
	std::cout << "Constructor copy: A new ClapTrap(" << this->m_Name << ") is born !" << std::endl;
	*this = p_ClapTrap;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor: A ClapTrap(" << this->m_Name << ") is dead..." << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & p_ClapTrap)
{
	this->m_Name = p_ClapTrap.m_Name;
	this->m_nHitPoints = p_ClapTrap.m_nHitPoints;
	this->m_nMaxHitPoints = p_ClapTrap.m_nMaxHitPoints;
	this->m_nEnergyPoints = p_ClapTrap.m_nEnergyPoints;
	this->m_nMaxEnergyPoints = p_ClapTrap.m_nMaxEnergyPoints;
	this->m_nLevel = p_ClapTrap.m_nLevel;
	this->m_nMeleeAttackDamage = p_ClapTrap.m_nMeleeAttackDamage;
	this->m_nRangedAttackDamage = p_ClapTrap.m_nRangedAttackDamage;
	this->m_nArmorDamageReduction = p_ClapTrap.m_nArmorDamageReduction;
	return (*this);
}

void ClapTrap::rangedAttack(std::string const & p_Target)
{
	std::cout << "CL4P-TP (" << this->m_Name << ") attacks " << p_Target << " at range, causing " << this->m_nRangedAttackDamage << " points of damage !" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & p_Target)
{
	std::cout << "CL4P-TP (" << this->m_Name << ") attacks " << p_Target << " at melee, causing " << this->m_nMeleeAttackDamage << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int p_nAmount)
{
	std::cout << "CL4P-TP (" << this->m_Name << ") take " << p_nAmount << " point of damage !" << std::endl;
	this->addHitPoint(-p_nAmount + this->m_nArmorDamageReduction);
	std::cout << "Current hit points : " << this->m_nHitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int p_nAmount)
{
	std::cout << "CL4P-TP (" << this->m_Name << ") recover " << p_nAmount << " hit point !" << std::endl;
	this->addHitPoint(p_nAmount);
	std::cout << "Current hit points : " << this->m_nHitPoints << std::endl;
}

void ClapTrap::addHitPoint(int p_nAmount)
{
	this->m_nHitPoints += p_nAmount;
	if (this->m_nHitPoints > this->m_nMaxHitPoints)
		this->m_nHitPoints = this->m_nMaxHitPoints;
	if (this->m_nHitPoints < 0)
		this->m_nHitPoints = 0;
}

