#include "ClockModule.hpp"
#include <time.h>

ClockModule::ClockModule(void) :
	IMonitorModule()
{}

ClockModule::ClockModule(IInfosSetter * pp_infos) :
	IMonitorModule(pp_infos),
	m_time(""),
	m_date("")
{}

ClockModule::ClockModule(ClockModule const & p_clockModule) :
	IMonitorModule()
{
	*this = p_clockModule;
}

ClockModule::~ClockModule(void)
{}

ClockModule & ClockModule::operator=(ClockModule const & p_clockModule)
{
	static_cast<void>(p_clockModule);
	return (*this);
}

void ClockModule::process(void)
{
	char pTime[24];
	long CurrentTime = time(NULL);
	tm Tm;
	localtime_r(&CurrentTime, &Tm);
	strftime(pTime, sizeof(pTime), "%d/%m/%Y", &Tm);
	m_time = pTime;

	char pDate[24];
	long CurrentDate = time(NULL);
	localtime_r(&CurrentDate, &Tm);
	strftime(pDate, sizeof(pDate), "%H:%M:%S", &Tm);
	m_date = pDate;
}

void ClockModule::refresh(void)
{
	IMonitorModule::setInfo(TIME, m_time);
	IMonitorModule::setInfo(DATE, m_date);
}
