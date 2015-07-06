#ifndef TREE_HPP
# define TREE_HPP

# include "StaticObject.hpp"
# include <vector>

# define DEPTH		8

# define MIN_X 20
# define MAX_X 140
# define MIN_Y 20
# define MAX_Y 170
# define MIN_A 20
# define MAX_A 70

class Tree : public StaticObject
{
private:
	int								mn_maxRectangle;
	int								mn_countRec;
	int								mn_countTri;

	float							mf_timer;
	float							mf_mouvement;
	bool							mb_growSide;
	bool							mb_isTriangle;

	std::vector<sf::RectangleShape>	m_rectangle;
	std::vector<sf::ConvexShape>	m_triangle;
	std::vector<float>				m_refAngle;

public:
	Tree(void);
	virtual ~Tree(void);

	void init(void);

	void pythagorasTree(sf::Vector2f p_center, sf::Vector2f p_size, float pf_angle = 0.0f, const int pn_depth = 1);
	void randomTree(void);

	virtual void pollEvent(sf::Event events);
	virtual void update(float pf_deltatime);
	virtual void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const;
};

#endif
