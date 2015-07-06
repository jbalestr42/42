#ifndef GRAPH_HPP
# define GRAPH_HPP

# include <SFML/Graphics.hpp>
# include <vector>

class Graph : public sf::Drawable
{
private:
	std::vector<float>	m_values;
	unsigned int		m_nbValue;
	float				m_maxValue;
	float				m_width;
	float				m_height;
	float				mf_x;
	float				mf_y;

	Graph(void);
	Graph(Graph const & p_graph);
	Graph &	operator=(Graph const & p_graph);

public:
	Graph(unsigned int p_nbValue, float p_maxValue, float p_width, float p_height);
	virtual ~Graph(void);

	void addValue(float pf_value);
	void setMaxValue(float pf_maxValue);
	void setPosition(float pf_x, float pf_y);
	void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const;

};

#endif /* !GRAPH_HPP */

