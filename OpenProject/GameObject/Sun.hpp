#ifndef SUN_HPP
# define SUN_HPP

# include "StaticObject.hpp"
# include <vector>


# define MIN_X 60
# define MAX_X 140
# define MIN_Y 60
# define MAX_Y 170
# define MIN_A 0
# define MAX_A 90

class Sun : public StaticObject
{
private:
	sf::ConvexShape					m_sunFront;
	sf::ConvexShape					m_sunBack;
	sf::Vector2f					m_sizeHeart;
	sf::Vector2f					m_sizeRay;
	float							mf_timer;
	float							mf_mouvement;

public:
	Sun(void);
	virtual ~Sun(void);

	void init(void);

	void randomSun(sf::ConvexShape * p_sun);

	virtual void pollEvent(sf::Event events);
	virtual void update(float pf_deltatime);
	virtual void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const;
};

#endif
