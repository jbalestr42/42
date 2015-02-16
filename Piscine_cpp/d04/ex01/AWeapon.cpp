#include "AWeapon.hpp"

AWeapon::AWeapon(void) { /* unused */ }

AWeapon::AWeapon(std::string const & p_sName, int p_nApCost, int p_nDamage) :
	m_sName(p_sName),
	m_nApCost(p_nApCost),
	m_nDamage(p_nDamage)
{

}

AWeapon::AWeapon(AWeapon const & p_AWeapon)
{
	*this = p_AWeapon;
}

AWeapon::~AWeapon(void)
{

}

AWeapon & AWeapon::operator=(AWeapon const & p_AWeapon)
{
	this->m_sName = p_AWeapon.getName();
	this->m_nApCost = p_AWeapon.getApCost();
	this->m_nDamage = p_AWeapon.getDamage();
	return (*this);
}

std::string const & AWeapon::getName(void) const
{
	return (this->m_sName);
}

int AWeapon::getApCost(void) const
{
	return (this->m_nApCost);
}

int AWeapon::getDamage(void) const
{
	return (this->m_nDamage);
}

