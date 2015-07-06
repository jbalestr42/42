#include "IInfosGetter.hpp"

IInfosGetter::IInfosGetter(IInfosGetter const & p_iInfosGetter)
{
	*this = p_iInfosGetter;
}
IInfosGetter const &	IInfosGetter::operator=(IInfosGetter const & p_iInfosGetter)
{
	static_cast<void>(p_iInfosGetter);
	return (*this);
}

IInfosGetter::IInfosGetter(void) {}
IInfosGetter::~IInfosGetter(void) {}

