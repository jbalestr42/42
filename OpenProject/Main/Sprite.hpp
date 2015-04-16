#ifndef SPRITE_HPP
# define SPRITE_HPP

# include <SFML/Graphics.hpp>

class Sprite : public sf::Sprite
{
public:
	Sprite(void);
	virtual ~Sprite(void);

	virtual void update(float pf_deltatime);

};

#endif
