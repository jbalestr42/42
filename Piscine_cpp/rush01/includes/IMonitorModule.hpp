#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <string>
# include "IInfosSetter.hpp"
# include "Define.hpp"

class IMonitorModule
{
private:
	IInfosSetter *	mp_infos;

protected:
	void setInfo(std::string const & p_infoName, std::string const & p_info);

	IMonitorModule(void);
	IMonitorModule(IInfosSetter * pp_infos);
	IMonitorModule(IMonitorModule const & p_imonitordisplay);
	IMonitorModule &	operator=(IMonitorModule const & p_imonitordisplay);
	std::string			sysCall(std::string p_sysCall);

public:
	virtual ~IMonitorModule(void);

	virtual void process(void) = 0;
	virtual void refresh(void) = 0;

};

#endif /* !IMONITORMODULE_HPP */
