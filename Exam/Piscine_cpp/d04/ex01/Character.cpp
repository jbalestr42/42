#include "Character.hpp"

#include <iostream>

Character::Character(void) { /* unused */ }

Character::Character(std::string const & p_sName) :
	m_sName(p_sName),
	m_nAp(40),
	m_nMaxAp(40),
	m_pWeapon(0)
{
}

Character::Character(Character const & p_Character)
{
	*this = p_Character;
}

Character::~Character(void)
{

}

Character & Character::operator=(Character const & p_Character)
{
	this->m_sName = p_Character.getName();
	this->m_nAp = p_Character.getAp();
	this->m_nMaxAp = p_Character.getMaxAp();
	this->m_pWeapon = p_Character.getWeapon();
	return (*this);
}

std::string const & Character::getName(void) const
{
	return (this->m_sName);
}

int Character::getAp(void) const
{
	return (this->m_nAp);
}

int Character::getMaxAp(void) const
{
	return (this->m_nMaxAp);
}

AWeapon *Character::getWeapon(void) const
{
	return (this->m_pWeapon);
}

void Character::recoverAp(void)
{
	this->m_nAp += 10;
	if (this->m_nAp > this->m_nMaxAp)
		this->m_nAp = this->m_nMaxAp;
	std::cout << "Recovering 10 AP" << std::endl;
	std::cout << "Current AP: " << this->m_nAp << std::endl;
}

void Character::equip(AWeapon *p_pAWeapon)
{
	this->m_pWeapon = p_pAWeapon;
	std::cout << "Equip a new weapon (" << p_pAWeapon->getName() << ")" << std::endl;
}

void Character::attack(Enemy *p_pEnemy)
{
	if (!this->m_pWeapon)
	{
		std::cout << "No weapon equipped" << std::endl;
		return;
	}

	if (this->m_nAp > this->m_pWeapon->getApCost())
	{
		this->m_nAp -= this->m_pWeapon->getApCost();
		std::cout << this->m_sName << " attacks " << p_pEnemy->getType() << " with a " << this->m_pWeapon->getName() << std::endl;
		this->m_pWeapon->attack();
		p_pEnemy->takeDamage(this->m_pWeapon->getDamage());
		if (p_pEnemy->getHp() <= 0)
			delete p_pEnemy;
	}
}

std::ostream & operator<<(std::ostream & p_ostream, Character const & p_character)
{
	p_ostream << p_character.getName() << " has " << p_character.getAp() << " AP and ";
	if (p_character.getWeapon())
		p_ostream << "wields a " << p_character.getWeapon()->getName() << std::endl;
	else
		p_ostream << "is unarmed" << std::endl;
	return (p_ostream);
}

