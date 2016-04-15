#ifndef SFMLDISPLAY_HPP
# define SFMLDISPLAY_HPP

# include <string>
# include <list>
# include "IMonitorDisplay.hpp"
# include <SFML/Graphics.hpp>
# include "Graph.hpp"

class SFMLDisplay : public IMonitorDisplay
{
private:
	sf::RenderWindow		m_window;
	Graph					*m_cpuGraph;
	Graph					*m_threadGraph;
	Graph					*m_taskGraph;
	Graph					*m_ramGraph;
	sf::Font				m_font;
	std::list<sf::Text *>	m_texts;
	// CPU information
	sf::Text *				m_cpuUsage;
	sf::Text *				m_cpuTask;
	sf::Text *				m_cpuThread;
	sf::Text *				m_cpuLoadAvg;
	sf::Text *				m_cpuMatchFactor;
	// RAM information
	sf::Text *				m_ramUsage;
	// Time/Date
	sf::Text *				m_time;
	sf::Texture				*m_texture;
	sf::Sprite				*m_sprite;


	sf::Text * getNewText(unsigned int p_size, float pf_x, float pf_y);

	SFMLDisplay(void);
	SFMLDisplay(SFMLDisplay const & p_sfmlDisplay);
	SFMLDisplay const &	operator=(SFMLDisplay const & p_sfmlDisplay);

public:
	SFMLDisplay(IInfosGetter * pp_infos);
	virtual ~SFMLDisplay(void);
	void				init(void);
	void				process(void);
	bool				display(void);
};

#endif
