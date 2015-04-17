#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

# include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable
{
public:
	GameObject();
	virtual ~GameObject(void);

	virtual void init(void);

	virtual void update(float pf_deltatime) = 0;
	virtual void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const = 0;

};



#endif
