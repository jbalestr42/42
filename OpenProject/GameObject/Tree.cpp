#include "Tree.hpp"
#include "DefineResources.hpp"
#include "Octo/OctoLogger.hpp"
#include "cmath"

Tree::Tree() :
	StaticObject(),
	mn_maxRectangle(0),
	mn_countRec(0),
	mn_countTri(0),
	mf_timer(0.0f),
	mb_growSide(false),
	mb_isTriangle(false)
{
}

Tree::~Tree()
{
	m_rectangle.clear();
	m_triangle.clear();
	m_refAngle.clear();
}

void Tree::pythagorasTree(sf::Vector2f p_center, sf::Vector2f p_size, float pf_angle, const int pn_depth)
{
	if (pn_depth == 1)
		mn_countRec = mn_countTri = 0;

	float tmpRectangleAngle = pf_angle;
	float refAngle;
	if (mb_growSide)
		refAngle = m_refAngle[mn_countRec] * mf_mouvement;
	else
		refAngle = 90.0f - m_refAngle[mn_countRec] * mf_mouvement;

	// Draw root rectangle
	sf::RectangleShape tmpRectangle;
	sf::Color tmpColor(m_color);
	float colorChange = pn_depth * 10;
	tmpColor = sf::Color(m_color.r + colorChange, m_color.g + colorChange, m_color.b + colorChange);
	tmpRectangle.setFillColor(tmpColor);
	tmpRectangle.setSize(sf::Vector2f(p_size.x, p_size.y));
	tmpRectangle.setPosition(p_center);
	tmpRectangle.setOrigin(p_size.x / 2.0f, p_size.y / 2.0f);
	tmpRectangle.setRotation(tmpRectangleAngle);
	m_rectangle[mn_countRec] = tmpRectangle;
	mn_countRec++;

	if (pn_depth >= DEPTH)
		return;

	// Compute left branch
	sf::Vector2f leftUpRoot(-p_size.x / 2.0f, -p_size.y / 2.0f);
	rotateVec(&leftUpRoot, tmpRectangleAngle);
	tmpRectangleAngle = pf_angle - refAngle;

	//float leftSizeX = cos(refAngle * RADIAN) * p_size.x;
	float leftSizeX = mf_cos[static_cast<int>(refAngle * 100.0f)] * p_size.x;
	float leftSizeY = leftSizeX * p_size.y / p_size.x;
	leftSizeY *= mf_mouvement;
	sf::Vector2f leftSize(leftSizeX, leftSizeY);
	sf::Vector2f leftCenter(leftSize.x / 2.0f, -leftSize.y / 2.0f);
	rotateVec(&leftCenter, tmpRectangleAngle);
	leftCenter += p_center + leftUpRoot;
	pythagorasTree(leftCenter, leftSize, tmpRectangleAngle, pn_depth + 1);

	// Compute right branch
	tmpRectangleAngle = pf_angle;
	sf::Vector2f rightUpRoot(p_size.x / 2.0f, -p_size.y / 2.0f);
	rotateVec(&rightUpRoot, tmpRectangleAngle);
	tmpRectangleAngle = pf_angle + 90.0f - refAngle;

	//float rightSizeX = cos((90.0f - refAngle) * RADIAN) * p_size.x;
	float rightSizeX = mf_cos[static_cast<int>((90.0f - refAngle) * 100.0f)] * p_size.x;
	float rightSizeY = (rightSizeX * p_size.y / p_size.x);
	rightSizeY *= mf_mouvement;
	sf::Vector2f rightSize(rightSizeX, rightSizeY);
	sf::Vector2f rightCenter(-rightSize.x / 2.0f, -rightSize.y / 2.0f);
	rotateVec(&rightCenter, tmpRectangleAngle);
	rightCenter += p_center + rightUpRoot;
	pythagorasTree(rightCenter, rightSize, tmpRectangleAngle, pn_depth + 1);

	//fill empty space with triangle
	if (pn_depth >= 4 && mb_isTriangle)
		return;
	sf::ConvexShape tmpRectangleTriangle;
	tmpRectangleTriangle.setPointCount(3);
	tmpRectangleTriangle.setPoint(0, rightUpRoot + p_center);
	tmpRectangleTriangle.setPoint(1, leftUpRoot + p_center);
	sf::Vector2f upTriangle(-rightSize.x, 0.0f);
	rotateVec(&upTriangle, tmpRectangleAngle);
	tmpRectangleTriangle.setPoint(2, upTriangle + p_center + rightUpRoot);
	colorChange += 5;
	tmpColor = sf::Color(m_color.r + colorChange, m_color.g + colorChange, m_color.b + colorChange);
	tmpRectangleTriangle.setFillColor(tmpColor);
	m_triangle[mn_countTri++] = tmpRectangleTriangle;
}

void Tree::randomTree(void)
{
	m_rectangle.clear();
	m_triangle.clear();
	m_refAngle.clear();
	m_rectangle.resize(mn_maxRectangle);
	m_triangle.resize(mn_maxRectangle / 2);
	m_refAngle.resize(mn_maxRectangle);
	me_currentState = e_treeState_grow;
	mb_growSide = static_cast<bool>(rand() % 2);
	mb_isTriangle = static_cast<bool>(rand() % 2);
	m_color = sf::Color(randomRange(20, 200), randomRange(20, 200), randomRange(20, 200));
	m_size = sf::Vector2f(randomRangeTile(MIN_X, MAX_X), randomRange(MIN_Y, MAX_Y));
	setOriginX();

	for (int i = 0; i < mn_maxRectangle; i++)
			m_refAngle[i] = randomRange(MIN_A, MAX_A);
	mf_mouvement = 0.01f;
	pythagorasTree(m_origin, m_size);
}

void Tree::init(void)
{
	StaticObject::init();

	mn_maxRectangle = pow(2, DEPTH) - 1;

	m_rectangle.resize(mn_maxRectangle);
	m_triangle.resize(mn_maxRectangle / 2);
	m_refAngle.resize(mn_maxRectangle);

	randomTree();
}

void Tree::pollEvent(sf::Event events)
{
}

void Tree::update(float pf_deltatime)
{
	StaticObject::update(pf_deltatime);

	mf_timer += pf_deltatime;
	if (mf_timer > 4.0f)
		mf_timer = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		randomTree();
	if (me_currentState == e_treeState_grow)
	{
		mf_mouvement += pf_deltatime / 4;
		if (mf_mouvement >= 1.0f)
		{
			mf_timer = 0.0f;
			me_currentState = e_treeState_sleep;
		}
	}
	else if (me_currentState == e_treeState_sleep)
	{
		if (mf_timer > 2.0f)
			mf_mouvement += pf_deltatime / (20 + (mf_timer - 2.0f) * 10);
		else
			mf_mouvement -= pf_deltatime / (20 + mf_timer * 10);
	}
	float delta = (m_size.y - m_size.y * mf_mouvement) / 2;
	pythagorasTree(sf::Vector2f(m_origin.x, m_origin.y + delta), sf::Vector2f(m_size.x, m_size.y * mf_mouvement));
}

void Tree::draw(sf::RenderTarget& p_target, sf::RenderStates p_states) const
{
	StaticObject::draw(p_target, p_states);

	for (int i = 0; i < m_rectangle.size(); i++)
	{
		p_target.draw(m_rectangle[i]);
		if (i % 2 && i / 2 < m_triangle.size())
			p_target.draw(m_triangle[i / 2]);
	}
}

