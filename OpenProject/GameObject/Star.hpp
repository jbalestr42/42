#ifndef STAR_HPP
# define STAR_HPP

# include "StaticObject.hpp"
# include <vector>


# define MIN_X 60
# define MAX_X 140
# define MIN_Y 60
# define MAX_Y 170
# define MIN_A 0
# define MAX_A 90

class Star : public StaticObject
{
private:
	sf::ConvexShape					m_starFront;
	sf::ConvexShape					m_starBack;
	sf::CircleShape					m_light;
	sf::Vector2f					m_sizeHeart;
	sf::Vector2f					m_sizeRay;
	float							mf_timer;
	float							mf_mouvement;

	sf::Texture texture;
	sf::Sprite sprite;

public:
	Star(void);
	virtual ~Star(void);

	void init(void);

	void randomStar(sf::ConvexShape * p_star);
	void randomLight(void);

	virtual void pollEvent(sf::Event events);
	virtual void update(float pf_deltatime);
	virtual void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const;
};

#endif
