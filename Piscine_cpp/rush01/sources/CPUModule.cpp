#include "CPUModule.hpp"
#include <algorithm>
#include <unistd.h>
#include <pwd.h>

CPUModule::CPUModule(void) :
	IMonitorModule()
{}

CPUModule::CPUModule(IInfosSetter * pp_infos) :
	IMonitorModule(pp_infos)
{}

CPUModule::CPUModule(CPUModule const & p_cpumodule) :
	IMonitorModule()
{
	*this = p_cpumodule;
}

CPUModule::~CPUModule(void)
{}

CPUModule & CPUModule::operator=(CPUModule const & p_cpumodule)
{
	static_cast<void>(p_cpumodule);
	return (*this);
}

void CPUModule::process(void)
{
	m_cpuName = IMonitorModule::sysCall("sysctl -n machdep.cpu.brand_string");
	m_cpuName.erase(std::remove(m_cpuName.begin(), m_cpuName.end(), '\n'), m_cpuName.end());


	m_cpuNbProcessor = IMonitorModule::sysCall("hostinfo | grep 'Default processor set' | awk -F',' '{print $3}' | awk -F ' ' '{print $1}'");
	m_cpuNbProcessor.erase(std::remove(m_cpuNbProcessor.begin(), m_cpuNbProcessor.end(), '\n'), m_cpuNbProcessor.end());
	m_cpuCurTasks = IMonitorModule::sysCall("hostinfo | grep 'Default processor set' | awk -F',' '{print $1}' | awk -F ' ' '{print $4}'");
	m_cpuCurTasks.erase(std::remove(m_cpuCurTasks.begin(), m_cpuCurTasks.end(), '\n'), m_cpuCurTasks.end());
	m_cpuCurThread = IMonitorModule::sysCall("hostinfo | grep 'Default processor set' | awk -F',' '{print $2}' | awk -F ' ' '{print $1}'");
	m_cpuCurThread.erase(std::remove(m_cpuCurThread.begin(), m_cpuCurThread.end(), '\n'), m_cpuCurThread.end());

	m_cpuUsage = IMonitorModule::sysCall("top -l 1 -n 0 | grep 'CPU usage' | awk -F' ' '{print $3}'");
	m_cpuUsage.erase(std::remove(m_cpuUsage.begin(), m_cpuUsage.end(), '\n'), m_cpuUsage.end());
	m_cpuLoadAverage = IMonitorModule::sysCall("hostinfo | grep 'Load average' | awk -F' ' '{print $3}'");
	m_cpuLoadAverage.erase(std::remove(m_cpuLoadAverage.begin(), m_cpuLoadAverage.end(), ','), m_cpuLoadAverage.end());
	m_cpuLoadAverage.erase(std::remove(m_cpuLoadAverage.begin(), m_cpuLoadAverage.end(), '\n'), m_cpuLoadAverage.end());
	m_cpuMatchFactor = IMonitorModule::sysCall("hostinfo | grep 'Load average' | awk -F' ' '{print $6}'");
	m_cpuMatchFactor.erase(std::remove(m_cpuMatchFactor.begin(), m_cpuMatchFactor.end(), '\n'), m_cpuMatchFactor.end());

}

void CPUModule::refresh(void)
{
	IMonitorModule::setInfo(CPU_NAME, m_cpuName);
	IMonitorModule::setInfo(CPU_NBPROCESSOR, m_cpuNbProcessor);
	IMonitorModule::setInfo(CPU_CURTASKS, m_cpuCurTasks);
	IMonitorModule::setInfo(CPU_CURTHREAD, m_cpuCurThread);
	IMonitorModule::setInfo(CPU_NBPROCESSOR, m_cpuNbProcessor);
	IMonitorModule::setInfo(CPU_USAGE, m_cpuUsage);
	IMonitorModule::setInfo(CPU_LOADAVERAGE, m_cpuLoadAverage);
	IMonitorModule::setInfo(CPU_MATCHFACTOR, m_cpuMatchFactor);
}
