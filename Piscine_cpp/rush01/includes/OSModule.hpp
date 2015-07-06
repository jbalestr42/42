#ifndef OSMODULE_HPP
# define OSMODULE_HPP

# include "IMonitorModule.hpp"

class OSModule : public IMonitorModule
{
private:
	std::string		m_osxName;
	std::string		m_osxVersion;
	std::string		m_osxBuild;
	std::string		m_kernelVersion;

	OSModule(void);
	OSModule(OSModule const & p_osModule);
	OSModule &		operator=(OSModule const & p_osModule);
	void			getOsxInfos(void);
	void			getKernelInfos(void);
public:
	OSModule(IInfosSetter * pp_infos);
	virtual ~OSModule(void);
	void			process(void);
	void			refresh(void);
};

#endif /* !OSMODULE_HPP */
