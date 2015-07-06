#include "Enemy.hpp"

Enemy::Enemy(void) { /* unused */ }

Enemy::Enemy(int p_nHp, std::string const & p_sType) :
	m_nHp(p_nHp),
	m_sType(p_sType)
{

}

Enemy::Enemy(Enemy const & p_Enemy)
{
	*this = p_Enemy;
}

Enemy::~Enemy(void)
{

}

Enemy & Enemy::operator=(Enemy const & p_Enemy)
{
	this->m_nHp = p_Enemy.getHp();
	this->m_sType = p_Enemy.getType();
	return (*this);
}

std::string const & Enemy::getType(void) const
{
	return (this->m_sType);
}

int Enemy::getHp(void) const
{
	return (this->m_nHp);
}

void Enemy::takeDamage(int p_nDamage)
{
	if (p_nDamage <= 0)
		return;
	this->m_nHp -= p_nDamage;
	if (this->m_nHp < 0)
		this->m_nHp = 0;
}
