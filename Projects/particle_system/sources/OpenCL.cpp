#include "OpenCL.hpp"

OpenCL::OpenCL(void) { }

OpenCL::OpenCL(OpenCL const & openCL)
{
	*this = openCL;
}

OpenCL::~OpenCL(void) { }

OpenCL & OpenCL::operator=(OpenCL const & openCL)
{
	(void)openCL;
	return (*this);
}
