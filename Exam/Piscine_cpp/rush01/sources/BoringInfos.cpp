#include "BoringInfos.hpp"

BoringInfos::BoringInfos(void) :
	IInfosSetter(),
	IInfosGetter()
{
	m_infos[EMPTY] = "Not found.";
}
BoringInfos::BoringInfos(BoringInfos const & p_boringInfos) :
	IInfosSetter(),
	IInfosGetter()
{
	*this = p_boringInfos;
}
BoringInfos const &	BoringInfos::operator=(BoringInfos const & p_boringInfos)
{
	static_cast<void>(p_boringInfos);
	return (*this);
}

BoringInfos::~BoringInfos(void) {}


void				BoringInfos::setInfo(std::string const & p_infoName, std::string const & p_value)
{
	m_infos[p_infoName] = p_value;
}
std::string const &	BoringInfos::getInfo(std::string const & p_infoName)
{
	if (m_infos[p_infoName].empty())
		return (m_infos[EMPTY]);
	return m_infos[p_infoName];
}
