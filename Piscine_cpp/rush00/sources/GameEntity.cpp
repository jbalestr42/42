#include "GameEntity.hpp"

int				GameEntity::msn_nbGameEntity = 0;

GameEntity::GameEntity(void) :
	mp_gameManager(0),
	mn_index(msn_nbGameEntity)
{
	msn_nbGameEntity++;
}

GameEntity::GameEntity(GameEntity const & p_gameEntity) :
	mn_index(msn_nbGameEntity)
{
	msn_nbGameEntity++;
	*this = p_gameEntity;
}

GameEntity::GameEntity(GameManager * pp_gameManager, int pn_x, int pn_y, int pn_hp, EType pe_type) :
	mp_gameManager(pp_gameManager),
	mn_index(msn_nbGameEntity),
	mf_x(pn_x),
	mf_y(pn_y),
	mn_maxHp(pn_hp),
	mn_hp(pn_hp),
	me_type(pe_type),
	mp_model(0)
{
	msn_nbGameEntity++;
}

GameEntity::~GameEntity(void)
{
	if (mp_model)
		delete mp_model;
}

GameEntity &	GameEntity::operator=(GameEntity const & p_gameEntity)
{
	mp_gameManager = p_gameEntity.mp_gameManager;
	mf_x = p_gameEntity.mf_x;
	mf_y = p_gameEntity.mf_y;
	me_type = p_gameEntity.me_type;
	return (*this);
}

void			GameEntity::display(void)
{
	mp_model->display((int)mf_x, (int)mf_y);
}

void			GameEntity::update(float pf_deltatime)
{
	if (mp_model)
		mp_model->update(pf_deltatime);
}

bool			GameEntity::isDead(void) const
{
	if (mn_hp <= 0)
		return (true);
	return (false);
}

float			GameEntity::getX(void) const
{
	return mf_x;
}

float			GameEntity::getY(void) const
{
	return mf_y;
}

GameEntity::EType			GameEntity::getType(void) const
{
	return me_type;
}

Model *			GameEntity::getModel(void) const
{
	return mp_model;
}

void			GameEntity::setHp(int pn_value)
{
	this->mn_hp = pn_value;
}

