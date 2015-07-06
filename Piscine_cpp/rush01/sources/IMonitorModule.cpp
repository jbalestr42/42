#include "IMonitorModule.hpp"
#include <stdio.h>

IMonitorModule::IMonitorModule(void) :
	mp_infos(0)
{}

IMonitorModule::IMonitorModule(IInfosSetter * pp_infos) :
	mp_infos(pp_infos)
{}

IMonitorModule::IMonitorModule(IMonitorModule const & p_imonitordisplay) :
	mp_infos(0)
{
	*this = p_imonitordisplay;
}

IMonitorModule::~IMonitorModule(void)
{}

IMonitorModule & IMonitorModule::operator=(IMonitorModule const & p_imonitordisplay)
{
	static_cast<void>(p_imonitordisplay);
	return (*this);
}

void IMonitorModule::setInfo(std::string const & p_infoName, std::string const & p_info)
{
	if (mp_infos)
		mp_infos->setInfo(p_infoName, p_info);
}

std::string			IMonitorModule::sysCall(std::string p_sysCall)
{
	FILE			*in;
	char			buff[512];
	std::string		result = "";

	if (!(in = popen(p_sysCall.c_str(), "r")))
		return (result);

	while (fgets(buff, sizeof(buff), in) != NULL)
		result += buff;
	pclose(in);
	return (result);
}

