#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "GameEntity.hpp"

class Weapon;

class Enemy : public GameEntity
{
private:
	Weapon *		mp_weapon;

	Enemy(void);
	Enemy(Enemy const & p_enemy);

public:
	// canonical
	Enemy(GameManager * pp_gameManager, int pn_x, int pn_y);
	virtual ~Enemy(void);

	// operators
	Enemy &	operator=(Enemy const & p_enemy);

	// GameEntity
	void		display(void);
	void		update(float pf_deltatime);
	void		collision(GameEntity & p_gameEntity);
	void		attack(void);

};

#endif /* !ENEMY_HPP */

