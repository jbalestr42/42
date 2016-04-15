#include "NcursesDisplay.hpp"
#include "Define.hpp"

NcursesDisplay::NcursesDisplay(void) :
	IMonitorDisplay(),
	mb_exit(false)
{
}

NcursesDisplay::NcursesDisplay(IInfosGetter * pp_infos) :
	IMonitorDisplay(pp_infos),
	mb_exit(false)
{
}

NcursesDisplay::NcursesDisplay(NcursesDisplay const & p_ncursesDisplay) :
	IMonitorDisplay(),
	mb_exit(false)
{
	*this = p_ncursesDisplay;
}

NcursesDisplay const &	NcursesDisplay::operator=(NcursesDisplay const & p_ncursesDisplay)
{
	static_cast<void>(p_ncursesDisplay);
	return (*this);
}

NcursesDisplay::~NcursesDisplay(void)
{
	endwin();			// End curses mode
}

void NcursesDisplay::init(void)
{
	initscr();
	noecho();
	nodelay(stdscr, 1);
	curs_set(false);
	keypad(stdscr, true);
}

void NcursesDisplay::process(void)
{ /*
	 float fVal = atof(mp_infos->getInfo(CURRENT_RAM).c_str());
	 m_ramGraph->addValue(fVal);
	 */
}

#include <sstream>

bool NcursesDisplay::display(void)
{
	int y, x;
	getmaxyx(stdscr, y, x);

	std::stringstream ss;
	ss << y << " " << x;
	if (!mb_exit)
	{
		this->getInput();
//		wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');
		mvprintw(1, 1, ss.str().c_str());
		//mvprintw(2, 2, mp_infos->getInfo(CPU_LOADAVERAGE).c_str());
		refresh();
		return (false);
	}
	return (true);
}

void NcursesDisplay::getInput(void)
{
	int nInput;

	if ((nInput = getch()) == ERR)
	{	}
	else
	{
		if (nInput == KEY_ESCAPE)
			mb_exit = true;
	}
}

