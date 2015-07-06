#ifndef GRAPH_HPP
# define GRAPH_HPP

# include <SFML/Graphics.hpp>
# include <vector>

class Graph : public sf::Drawable
{
	private:
		std::vector<float>		m_values;
		sf::VertexArray			m_vvalues;
		sf::VertexArray			m_axes;
		unsigned int			mn_nbValue;
		unsigned int			mn_index;
		unsigned int			mn_currentNbValue;
		float				mf_spaceBetweenValues;
		float				mf_max;
		float				mn_width;
		float				mn_height;
		float				mf_total;
		float				mf_x;
		float				mf_y;
		sf::Text			m_textMax;
		sf::Text			m_textAvg;

		Graph(void);
		void setVertexPosition(int pn_index);

	public:
		Graph(unsigned int p_nbValue, float p_width, float p_height);
		virtual ~Graph(void);
		void addValue(float pf_value);
		void setPosition(float pf_x, float pf_y);
		void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const;

};

#endif /* !GRAPH_HPP */
