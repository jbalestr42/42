#include "Weapon.hpp"

Weapon::Weapon(void)
{

}

Weapon::Weapon(std::string p_Type)
	:m_Type(p_Type)
{
}

Weapon::~Weapon(void)
{
}

std::string const &Weapon::getType(void) const
{
	return this->m_Type;
}

void Weapon::setType(std::string p_Type)
{
	this->m_Type = p_Type;
}
