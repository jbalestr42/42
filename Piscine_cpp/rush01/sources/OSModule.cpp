#include "OSModule.hpp"
#include <sys/utsname.h>
#include <algorithm>

OSModule::OSModule(void) :
	IMonitorModule()
{}

OSModule::OSModule(IInfosSetter * pp_infos) :
	IMonitorModule(pp_infos),
	m_osxName(""),
	m_osxVersion(""),
	m_osxBuild(""),
	m_kernelVersion("")
{}

OSModule::OSModule(OSModule const & p_osModule) :
	IMonitorModule()
{
	*this = p_osModule;
}

OSModule::~OSModule(void)
{}

OSModule &			OSModule::operator=(OSModule const & p_osModule)
{
	static_cast<void>(p_osModule);
	return (*this);
}

void				OSModule::getOsxInfos(void)
{
	std::string		result;

	result = IMonitorModule::sysCall("sw_vers");
	// split result
	std::string		infos[3];
	int				first = 0;
	int				end = 0;

	result.erase(std::remove(result.begin(), result.end(), '\t'), result.end());
	for (int i = 0; i < 3; i++)
	{
		first = result.find(":", end + 1, 1);
		end = result.find("\n", end + 1, 1);
		infos[i] = result.substr(first + 1, end - first - 1);
	}
	m_osxName = infos[0];
	m_osxVersion = infos[1];
	m_osxBuild = infos[2];
}

void				OSModule::getKernelInfos(void)
{
	m_kernelVersion = IMonitorModule::sysCall("system_profiler SPSoftwareDataType | grep 'Kernel Version' | cut -d':' -f2 | tr -d '\n'");
}

void		OSModule::process(void)
{
	this->getOsxInfos();
	this->getKernelInfos();
}

void		OSModule::refresh(void)
{
	IMonitorModule::setInfo(OSX_NAME, m_osxName);
	IMonitorModule::setInfo(OSX_VERSION, m_osxVersion);
	IMonitorModule::setInfo(OSX_BUILD, m_osxBuild);
	IMonitorModule::setInfo(KERNEL_VERSION, m_kernelVersion);
}
