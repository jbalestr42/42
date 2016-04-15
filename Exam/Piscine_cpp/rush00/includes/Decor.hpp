#ifndef DECOR_HPP
# define DECOR_HPP

# include "GameEntity.hpp"

class Decor : public GameEntity
{
private:
	Decor(void);
	Decor(Decor const & p_enemy);

public:
	// canonical
	Decor(GameManager * pp_gameManager, int pn_x, int pn_y);
	virtual ~Decor(void);

	// operators
	Decor &	operator=(Decor const & p_enemy);

	// GameEntity
	void		display(void);
	void		update(float pf_deltatime);
	void		collision(GameEntity & p_gameEntity);

};

#endif /* !DECOR_HPP */

