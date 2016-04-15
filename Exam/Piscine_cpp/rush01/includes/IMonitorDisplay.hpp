#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include <string>
# include "Define.hpp"
# include "IInfosGetter.hpp"

class IMonitorDisplay
{
protected:
	IInfosGetter	*mp_infos;

	IMonitorDisplay(void);
	IMonitorDisplay(IInfosGetter * pp_infos);
	IMonitorDisplay(IMonitorDisplay const & p_iMonitorDisplay);
	IMonitorDisplay const &	operator=(IMonitorDisplay const & p_iMonitorDisplay);

public:
	virtual ~IMonitorDisplay(void);
	virtual void				init(void) = 0;
	virtual void				process(void) = 0;
	virtual bool				display(void) = 0;
};

#endif
