#ifndef BULLET_HPP
# define BULLET_HPP

# include "GameEntity.hpp"

class Weapon;

class Bullet : public GameEntity
{
private:
	float			mf_speed;
	int				mn_damage;

	Bullet(void);
public:
	// canonical
	Bullet(GameManager * pp_gameManager, int pn_x, int pn_y, Weapon * pp_weapon);
	Bullet(Bullet const & p_bullet);
	virtual ~Bullet(void);

	// operators
	Bullet &	operator=(Bullet const & p_bullet);

	// GameEntity
	void		display(void);
	void		update(float pf_deltatime);
	void		collision(GameEntity & p_gameEntity);

	int			getDamage(void) const;
	float		getSpeed(void) const;

};

#endif /* !BULLET_HPP */

