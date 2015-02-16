#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include "IMonitorModule.hpp"

class RAMModule : public IMonitorModule
{
private:
	std::string		m_curRam;
	std::string		m_maxRam;

	RAMModule(void);
	RAMModule(RAMModule const & p_rammodule);
	RAMModule & operator=(RAMModule const & p_rammodule);

public:
	RAMModule(IInfosSetter * pp_infos);
	virtual ~RAMModule(void);

	void process(void);
	void refresh(void);

};

#endif /* !RAMMODULE_HPP */
