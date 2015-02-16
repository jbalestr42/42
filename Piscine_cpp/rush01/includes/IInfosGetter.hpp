#ifndef IINFOSGETTER_HPP
# define IINFOSGETTER_HPP

# include <string>

class IInfosGetter
{
private:
	IInfosGetter(IInfosGetter const & p_iInfosGetter);
	IInfosGetter const &	operator=(IInfosGetter const & p_iInfosGetter);
public:
	IInfosGetter(void);
	virtual ~IInfosGetter(void);
	virtual std::string const &	getInfo(std::string const & p_infoName) = 0;
};

#endif
