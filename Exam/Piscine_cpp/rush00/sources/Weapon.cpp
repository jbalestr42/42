#include "Weapon.hpp"
#include "GameManager.hpp"
#include "GameEntity.hpp"

Weapon::Weapon(void) :
	mn_damage(0),
	mf_firerate(0.f),
	mf_timer(0.f),
	m_name("empty"),
	mp_owner(NULL)
{ /* unused */ }

Weapon::Weapon(int pn_damage, float pf_firerate, std::string p_name, GameEntity * pp_owner) :
	mn_damage(pn_damage),
	mf_firerate(pf_firerate),
	mf_timer(0.f),
	m_name(p_name),
	mp_owner(pp_owner)
{
}

Weapon::Weapon(Weapon const & p_weapon) :
	mf_firerate(0.f)
{
	*this = p_weapon;
}

Weapon::~Weapon(void)
{

}

Weapon & Weapon::operator=(Weapon const & p_weapon)
{
	mn_damage = p_weapon.mn_damage;
	m_name = p_weapon.m_name;
	return (*this);
}

std::string const & Weapon::getName(void) const
{
	return (m_name);
}

void Weapon::update(float pf_deltatime)
{
	mf_timer += pf_deltatime;
}

int Weapon::getDamage(void) const
{
	return (mn_damage);
}

GameEntity * Weapon::getOwner(void) const
{
	return (mp_owner);
}
