#include "Graph.hpp"

Graph::Graph(void) { /* unused */ }

Graph::Graph(unsigned int p_nbValue, float p_maxValue, float p_width, float p_height) :
	m_nbValue(p_nbValue),
	m_maxValue(p_maxValue),
	m_width(p_width),
	m_height(p_height)
{}

Graph::Graph(Graph const & p_graph)
{
	*this = p_graph;
}

Graph::~Graph(void)
{

}

Graph & Graph::operator=(Graph const & p_graph)
{
	static_cast<void>(p_graph);
	return (*this);
}

void Graph::addValue(float pf_value)
{
	if (m_values.size() > m_nbValue)
		m_values.erase(m_values.begin());
	m_values.push_back(pf_value * m_height / m_maxValue);
}

void Graph::setMaxValue(float pf_maxValue)
{
	m_maxValue = pf_maxValue;
}

void Graph::setPosition(float pf_x, float pf_y)
{
	mf_x = pf_x;
	mf_y = pf_y;
}

void Graph::draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const
{
	static_cast<void>(p_states);
	sf::Vertex line[2];
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(m_width, m_height));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setFillColor(sf::Color(30, 30, 30, 255));
	rectangle.setOutlineThickness(2.f);
	rectangle.setPosition(sf::Vector2f(mf_x, mf_y));
	p_target.draw(rectangle);

	line[0].color = sf::Color(178, 243, 99);
	line[1].color = sf::Color(178, 243, 99);
	float fStep = m_width / m_nbValue;
	for (unsigned int i = 1; i < m_nbValue / 2; i++)
	{
		line[0].position = sf::Vector2f(mf_x + (i * fStep * 2), mf_y);
		line[1].position = sf::Vector2f(mf_x + (i * fStep * 2), mf_y + m_height);
		p_target.draw(line, 2, sf::Lines);
	}
	for (unsigned int i = 1; i < 5; i++)
	{
		line[0].position = sf::Vector2f(mf_x, mf_y + (i * m_height / 5));
		line[1].position = sf::Vector2f(mf_x + m_width, mf_y + (i * m_height / 5));
		p_target.draw(line, 2, sf::Lines);
	}

	line[0].color = sf::Color::White;
	line[1].color = sf::Color::White;
	for (unsigned int i = 0; i < m_values.size() - 1; i++)
	{
		line[0].position = sf::Vector2f(mf_x + (i * fStep), mf_y + m_height - m_values[i]);
		line[1].position = sf::Vector2f(mf_x + ((i + 1) * fStep), mf_y + m_height - m_values[i + 1]);
		p_target.draw(line, 2, sf::Lines);
	}
}
