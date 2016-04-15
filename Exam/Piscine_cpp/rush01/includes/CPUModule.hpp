#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include "IMonitorModule.hpp"
# include <string>

class CPUModule : public IMonitorModule
{
private:
	std::string		m_cpuName;
	std::string		m_cpuNbProcessor;
	std::string		m_cpuCurTasks;
	std::string		m_cpuCurThread;
	std::string		m_cpuUsage;
	std::string		m_cpuLoadAverage;
	std::string		m_cpuMatchFactor;


	CPUModule(void);
	CPUModule(CPUModule const & p_cpumodule);
	CPUModule & operator=(CPUModule const & p_cpumodule);

public:
	CPUModule(IInfosSetter * pp_infos);
	virtual ~CPUModule(void);

	void process(void);
	void refresh(void);

};

#endif /* !CPUMODULE_HPP */
