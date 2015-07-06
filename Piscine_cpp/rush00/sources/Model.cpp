#include "Model.hpp"
#include "GameEntity.hpp"
#include <ncurses.h>

Model::Model(void) :
	mn_nbFrame(1),
	mn_currentFrame(0),
	mn_sizeFrame(MAX_HEIGHT),
	mf_timer(0.f),
	mp_owner(0)
{ /* unused */ }

Model::Model(std::string pp_shape[MAX_HEIGHT], GameEntity * pp_owner) :
	mn_nbFrame(1),
	mn_currentFrame(0),
	mn_sizeFrame(MAX_HEIGHT),
	mf_timer(0.f),
	mp_owner(pp_owner)
{
	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		mp_shape[i] = pp_shape[i];
	}
}

Model::Model(std::string pp_shape[MAX_HEIGHT], int pn_nbFrame, int pn_sizeFrame, GameEntity * pp_owner) :
	mn_nbFrame(pn_nbFrame),
	mn_currentFrame(0),
	mn_sizeFrame(pn_sizeFrame),
	mf_timer(0.f),
	mp_owner(pp_owner)
{
	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		mp_shape[i] = pp_shape[i];
	}
}

Model::Model(Model const & p_model)
{
	/* unused */
	*this = p_model;
}

Model::~Model(void)
{

}

Model & Model::operator=(Model const & p_model)
{
	/* unused */
	(void)p_model;
	return (*this);
}

void			Model::update(float pf_deltatime)
{
	mf_timer += pf_deltatime * 15.f;
	mn_currentFrame = (int)mf_timer;
	if (mn_currentFrame >= mn_nbFrame)
	{
		mf_timer = 0.f;
		mn_currentFrame = 0;
	}
}

void			Model::display(int pn_x, int pn_y)
{
	for (int i = 0; i < mn_sizeFrame; i++)
	{
		mvprintw(pn_x + i, pn_y, mp_shape[mn_currentFrame * mn_sizeFrame + i].c_str());
	}
}

bool			Model::collision(GameEntity const & p_gameEntity)
{
	if (mp_owner->isDead() || p_gameEntity.isDead())
		return (false);

	for (int i = 0; i < mn_sizeFrame; i++)
	{
		for (int j = 0; mp_shape[i][j]; j++)
		{
			if (mp_shape[i][j] != ' ')
			{
				for (int ii = 0; ii < p_gameEntity.getModel()->mn_sizeFrame; ii++)
				{
					for (int jj = 0; p_gameEntity.getModel()->mp_shape[ii][jj]; jj++)
					{
						if (p_gameEntity.getModel()->mp_shape[ii][jj] != ' ')
						{
							if ((int)mp_owner->getX() + i == (int)p_gameEntity.getX() + ii && (int)mp_owner->getY() + j == (int)p_gameEntity.getY() + jj)
								return (true);
						}
					}
				}
			}
		}
	}
	return (false);
}
