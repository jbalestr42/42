#ifndef NCURSESDISPLAY_HPP
# define NCURSESDISPLAY_HPP

# include <string>
# include "IMonitorDisplay.hpp"
# include <SFML/Graphics.hpp>
# include "Graph.hpp"
#include "ncurses.h"

class NcursesDisplay : public IMonitorDisplay
{
private:
	bool					mb_exit;

	NcursesDisplay(void);
	NcursesDisplay(NcursesDisplay const & p_ncursesDisplay);
	NcursesDisplay const &	operator=(NcursesDisplay const & p_ncursesDisplay);

public:
	NcursesDisplay(IInfosGetter * pp_infos);
	virtual ~NcursesDisplay(void);
	void				init(void);
	void				process(void);
	bool				display(void);
	void				getInput(void);
};

#endif
