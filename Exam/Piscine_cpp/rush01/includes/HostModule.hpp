#ifndef HOSTMODULE_HPP
# define HOSTMODULE_HPP

# include "IMonitorModule.hpp"

class HostModule : public IMonitorModule
{
private:
	std::string		m_hostName;
	std::string		m_userName;

	HostModule(void);
	HostModule(HostModule const & p_hostmodule);
	HostModule & operator=(HostModule const & p_hostmodule);

public:
	HostModule(IInfosSetter * pp_infos);
	virtual ~HostModule(void);

	void process(void);
	void refresh(void);

};

#endif /* !HOSTMODULE_HPP */
