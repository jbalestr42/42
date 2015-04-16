#ifndef STATICOBJECT_HPP
# define STATICOBJECT_HPP

# include <SFML/Graphics.hpp>
# include "GameObject/GameObject.hpp"

# define PI			3.14159265
# define RADIAN		PI / 180.0f
# define SQ(x)		(x * x)
# define TILE_SIZE	16.0f
# define TRANSITION_TIME 0.4f
# define STEP_TRANSITION TILE_SIZE / TRANSITION_TIME

class StaticObject : public GameObject
{
protected:
	enum ETreeState
	{
		e_treeState_sleep,
		e_treeState_grow,

		e_treeState_nb
	};

	ETreeState						me_currentState;
	sf::Vector2f					m_origin;
	float							mf_nextY;
	sf::Vector2f					m_size;
	sf::Color						m_color;
	float							mf_cos[36000];
	float							mf_transitionTimer;

	void  rotateVec(sf::Vector2f *p_point, float pf_angle, sf::Vector2f p_axis = sf::Vector2f(0.0f, 0.0f));
	float randomRange(int pn_min, int pn_max);
	float randomRangeTile(int pn_min, int pn_max);

public:
	StaticObject(void);
	virtual ~StaticObject(void);

	virtual void init(void);

	virtual void update(float pf_deltatime) = 0;
	virtual void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const = 0;

	void setOriginX(void);
	void setOriginY(int const pn_y);
	sf::Vector2f getOrigin(void) const;
};

#endif
