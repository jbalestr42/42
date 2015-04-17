#include "OctoLogger.hpp"
#include <time.h>
#include <assert.h>

OctoLogger * OctoLogger::msp_current = NULL;
OctoFile OctoLogger::m_file;

OctoLogger::OctoLogger(void) :
	mb_activateTime(true)
{
	m_file.open("log", OUT);

	assert(m_file.isOpen());

	m_file.write("================================================\n");
	m_file.write(" Event log - " + currentDate() + "\n");
	m_file.write("================================================\n\n");
}

OctoLogger::~OctoLogger(void)
{
	m_file.write("\n================================================\n");
	m_file.write(" Event log - " + currentTime() + "\n");
	m_file.write("================================================\n");
	m_file.close();
}

void OctoLogger::destroy(void)
{
	if (msp_current)
		delete msp_current;
	msp_current = NULL;
}

void OctoLogger::log(std::string const & p_string)
{
	log() << p_string;
}

void OctoLogger::log(char const * ppc_format, ...)
{
	char dest[1024];
	va_list va;
	va_start(va, ppc_format);
	vsprintf(dest, ppc_format, va);
	va_end(va);
	log() << dest;
}

void OctoLogger::logCmd(char const * ppc_format, ...)
{
	char dest[1024];
	va_list va;
	va_start(va, ppc_format);
	vsprintf(dest, ppc_format, va);
	va_end(va);
	std::cout << dest << std::endl;
}

OctoLogger & OctoLogger::log(void)
{
	if (!msp_current)
		msp_current = new OctoLogger();
	return *msp_current;
}

void OctoLogger::activateTime(void)
{
	mb_activateTime = true;
}

void OctoLogger::desactivateTime(void)
{
	mb_activateTime = false;
}

void OctoLogger::write(std::string const & p_message)
{
	assert(m_file.isOpen());

	if (mb_activateTime)
		m_file.write("[" + currentTime() + "] " + p_message + "\n");
	else
		m_file.write(p_message + "\n");
}

std::string OctoLogger::currentDate(void) const
{
	char pTime[24];
	time_t currentTime = time(NULL);
	tm Tm;
	localtime_r(&currentTime, &Tm);
	strftime(pTime, sizeof(pTime), "%d/%m/%Y", &Tm);

	return pTime;
}

std::string OctoLogger::currentTime(void) const
{
	char pTime[24];
	time_t currentTime = time(NULL);
	tm Tm;
	localtime_r(&currentTime, &Tm);
	strftime(pTime, sizeof(pTime), "%H:%M:%S", &Tm);

	return pTime;
}
