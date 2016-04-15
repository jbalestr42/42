#ifndef BORINGINFOS_HPP
# define BORINGINFOS_HPP

# include <string>
# include <map>
# include "IInfosSetter.hpp"
# include "IInfosGetter.hpp"
# include "Define.hpp"

class BoringInfos : public IInfosSetter, public IInfosGetter
{
private:
	std::map<std::string, std::string>		m_infos;

	BoringInfos(BoringInfos const & p_boringInfos);
	BoringInfos const &	operator=(BoringInfos const & p_boringInfos);
public:
	BoringInfos(void);
	virtual ~BoringInfos(void);
	void				setInfo(std::string const & p_infoName, std::string const & p_value);
	std::string const &	getInfo(std::string const & p_infoName);
};

#endif
