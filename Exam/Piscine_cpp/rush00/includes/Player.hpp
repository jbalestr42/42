#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "GameEntity.hpp"
# include "Weapon.hpp"

# define MAX_HP 100

class Player : public GameEntity
{
private:
	Weapon *		mp_weapon;
	float			mf_speedX;
	float			mf_speedY;

	Player(void);
public:
	// canonical
	Player(GameManager * pp_gameManager, int pn_x, int pn_y);
	Player(Player const & p_player);
	virtual ~Player(void);

	// operators
	Player &	operator=(Player const & p_player);

	// GameEntity
	void		update(float pf_deltatime);
	void		collision(GameEntity & p_gameEntity);
	void		getInput(int pn_input);

	// Player
	void		attack(void);
	void		setPos(int pn_x, int pn_y);
	void		resetSpeed(void);
	void		takeDamage(int pn_value);
	void		restoreHp(int pn_value);

	void		hud(void);
};

#endif /* !PLAYER_HPP */

