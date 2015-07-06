#ifndef FRAMERATE_HPP
# define FRAMERATE_HPP

# include <SFML/Graphics.hpp>
# include "Graph.hpp"

class FrameRate : public sf::Drawable
{
private:
	Graph *		m_graph;
	float		mf_timer;
	int			mn_nbFrame;
	sf::Text	m_text;
	char		mp_buffer[256];

public:
	FrameRate(void);
	virtual ~FrameRate(void);

	void update(float pf_deltatime);
	void draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const;

};

#endif
