#include "IInfosSetter.hpp"

IInfosSetter::IInfosSetter(IInfosSetter const & p_iInfosSetter)
{
	*this = p_iInfosSetter;
}
IInfosSetter const &	IInfosSetter::operator=(IInfosSetter const & p_iInfosSetter)
{
	static_cast<void>(p_iInfosSetter);
	return (*this);
}

IInfosSetter::IInfosSetter(void) {}
IInfosSetter::~IInfosSetter(void) {}

