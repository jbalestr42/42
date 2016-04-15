#include "RAMModule.hpp"
#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>

RAMModule::RAMModule(void) :
	IMonitorModule()
{}

RAMModule::RAMModule(IInfosSetter * pp_infos) :
	IMonitorModule(pp_infos),
	m_curRam(""),
	m_maxRam("")
{}

RAMModule::RAMModule(RAMModule const & p_rammodule) :
	IMonitorModule()
{
	*this = p_rammodule;
}

RAMModule::~RAMModule(void)
{}

RAMModule & RAMModule::operator=(RAMModule const & p_rammodule)
{
	static_cast<void>(p_rammodule);
	return (*this);
}

void RAMModule::process(void)
{
	std::string			result;
	int					index;
	std::stringstream 	ssTotal;
	std::stringstream 	ssTotal2;

	result = IMonitorModule::sysCall("ps -caxm -orss,comm | awk -F' ' '{print $1}'");
	index = result.find("\n", 0, 1);
	result = result.substr(index + 1, result.length() - index - 1);

	std::stringstream ss(result);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	int total = 0;
	for(std::vector<std::string>::iterator it = vstrings.begin(); it != vstrings.end(); it++)
		total += atoi((*it).c_str());
	ssTotal << total;
	m_curRam = ssTotal.str();

	m_maxRam = IMonitorModule::sysCall("sysctl -a | grep 'hw.memsize =' | cut -d' ' -f3");
	char * p_end;
	long				maxRamInt = strtol(m_maxRam.c_str(), &p_end, 10) / 1024;
	ssTotal2 << maxRamInt;
	m_maxRam = ssTotal2.str();
}

void RAMModule::refresh(void)
{
	IMonitorModule::setInfo(CURRENT_RAM, m_curRam);
	IMonitorModule::setInfo(MAX_RAM, m_maxRam);
}
