#ifndef BONUS_HPP
# define BONUS_HPP

# include "GameEntity.hpp"

class Bonus : public GameEntity
{
private:
	Bonus(void);
	Bonus(Bonus const & p_enemy);

public:
	// canonical
	Bonus(GameManager * pp_gameManager, int pn_x, int pn_y);
	virtual ~Bonus(void);

	// operators
	Bonus &	operator=(Bonus const & p_enemy);

	// GameEntity
	void		display(void);
	void		update(float pf_deltatime);
	void		collision(GameEntity & p_gameEntity);

};

#endif /* !BONUS_HPP */

