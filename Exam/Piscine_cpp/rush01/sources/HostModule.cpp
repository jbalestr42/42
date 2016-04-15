#include "HostModule.hpp"
#include <unistd.h>
#include <pwd.h>

HostModule::HostModule(void) :
	IMonitorModule()
{}

HostModule::HostModule(IInfosSetter * pp_infos) :
	IMonitorModule(pp_infos),
	m_hostName(""),
	m_userName("")
{}

HostModule::HostModule(HostModule const & p_hostmodule) :
	IMonitorModule()
{
	*this = p_hostmodule;
}

HostModule::~HostModule(void)
{}

HostModule & HostModule::operator=(HostModule const & p_hostmodule)
{
	static_cast<void>(p_hostmodule);
	return (*this);
}

void HostModule::process(void)
{
	struct passwd *pwd;
	pwd = getpwuid(getuid());
	m_userName = pwd->pw_name;

	char hostname[1024];
	gethostname(hostname, 1024);
	m_hostName = hostname;
}

void HostModule::refresh(void)
{
	IMonitorModule::setInfo(HOST_NAME, m_hostName);
	IMonitorModule::setInfo(USER_NAME, m_userName);
}
