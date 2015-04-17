#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "GameObject.hpp"

class Player : public GameObject
{
public:
	Player();
	virtual ~Player();

	void init(void);

	virtual void pollEvent(sf::Event events);
	virtual void update(float pf_deltatime);
	virtual void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const;
};


#endif
