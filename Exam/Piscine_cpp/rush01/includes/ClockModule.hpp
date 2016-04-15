#ifndef CLOCKMODULE_HPP
# define CLOCKMODULE_HPP

# include "IMonitorModule.hpp"

class ClockModule : public IMonitorModule
{
private:
	std::string		m_time;
	std::string		m_date;

	ClockModule(void);
	ClockModule(ClockModule const & p_clockModule);
	ClockModule & operator=(ClockModule const & p_clockModule);

public:
	ClockModule(IInfosSetter * pp_infos);
	virtual ~ClockModule(void);

	void process(void);
	void refresh(void);

};

#endif /* !CLOCKMODULE_HPP */
