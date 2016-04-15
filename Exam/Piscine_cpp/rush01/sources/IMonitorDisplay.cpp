#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay(void) :
	mp_infos(0)
{}

IMonitorDisplay::IMonitorDisplay(IInfosGetter * pp_infos) :
	mp_infos(pp_infos)
{}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const & p_iMonitorDisplay) :
	mp_infos(0)
{
	*this = p_iMonitorDisplay;
}

IMonitorDisplay const &	IMonitorDisplay::operator=(IMonitorDisplay const & p_iMonitorDisplay)
{
	static_cast<void>(p_iMonitorDisplay);
	return (*this);
}

IMonitorDisplay::~IMonitorDisplay(void) {}

