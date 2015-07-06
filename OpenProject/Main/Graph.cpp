#include "Graph.hpp"
#include <sstream>
#include "ResourcesManager.hpp"

Graph::Graph(void) { /* unused */ }

Graph::Graph(unsigned int p_nbValue, float p_width, float p_height) :
	mn_nbValue(p_nbValue),
	mn_index(0),
	mn_currentNbValue(0),
	mf_spaceBetweenValues(p_width / p_nbValue),
	mf_max(0.f),
	mn_width(p_width),
	mn_height(p_height),
	mf_total(0.f)
{
	m_values.reserve(mn_nbValue);
	m_vvalues.resize(mn_nbValue);

	m_axes.setPrimitiveType(sf::Lines);
	m_axes.resize(4);

	m_textMax.setFont(ResourcesManager::getCurrent().getFont(FONT_CHUNKFIVE_EX));
	m_textAvg.setFont(ResourcesManager::getCurrent().getFont(FONT_CHUNKFIVE_EX));
	m_textMax.setCharacterSize(17);
	m_textAvg.setCharacterSize(17);
	m_textMax.setString("NA");
	m_textAvg.setString("NA");
}

Graph::~Graph(void)
{
}

void Graph::addValue(float pf_value)
{
	mf_max = pf_value;
	mf_total += pf_value;
	if (mn_currentNbValue < mn_nbValue)
		mn_currentNbValue++;
	else
		mf_total -= m_values[0];
	m_values[mn_currentNbValue - 1] = pf_value;
	for (unsigned int i = 0; i < mn_currentNbValue - 1; i++)
	{
		m_values[i] = m_values[i + 1];
		setVertexPosition(i);
		if (m_values[i] > mf_max)
			mf_max = m_values[i];
	}
	setVertexPosition(mn_currentNbValue - 1);
	std::stringstream ss;
	ss << mf_max;
	m_textMax.setString(ss.str());
	ss.str("");
	ss << "Average : " << (mf_total / static_cast<float>(mn_currentNbValue));
	m_textAvg.setString(ss.str());
}

void Graph::setPosition(float pf_x, float pf_y)
{
	mf_x = pf_x;
	mf_y = pf_y;
	m_axes.clear();
	sf::Vertex v = sf::Vector2f(mf_x, mf_y);
	v.color = sf::Color::Red;
	m_axes.append(v);
	v.position.y += mn_height;
	m_axes.append(v);
	v.position = sf::Vector2f(mf_x, mf_y + mn_height);
	m_axes.append(v);
	v.position = sf::Vector2f(mf_x + mn_width, mf_y + mn_height);
	m_axes.append(v);
	m_textMax.setPosition(pf_x - 10.f, pf_y - 30.f);
	m_textAvg.setPosition(pf_x - 10.f, pf_y + mn_height + 10.f);
}

void Graph::setVertexPosition(int pn_index)
{
	m_vvalues[pn_index].position.x = mf_x + pn_index * mf_spaceBetweenValues;
	m_vvalues[pn_index].position.y = mf_y + mn_height - (m_values[pn_index] * mn_height / (mf_max + 20.f));
}

void Graph::draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const
{
	p_target.draw(m_axes);
	p_target.draw(&m_vvalues[0], mn_currentNbValue, sf::LinesStrip);
	p_target.draw(m_textMax);
	p_target.draw(m_textAvg);
}
