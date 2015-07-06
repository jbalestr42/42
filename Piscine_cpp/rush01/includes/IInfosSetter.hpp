#ifndef IINFOSSETTER_HPP
# define IINFOSSETTER_HPP

#include <string>

class IInfosSetter
{
private:
	IInfosSetter(IInfosSetter const & p_iInfosSetter);
	IInfosSetter const &	operator=(IInfosSetter const & p_iInfosSetter);
public:
	IInfosSetter(void);
	virtual ~IInfosSetter(void);
	virtual void				setInfo(std::string const & p_infoName, std::string const & p_value) = 0;
};

#endif
