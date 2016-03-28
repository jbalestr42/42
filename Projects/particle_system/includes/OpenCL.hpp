#ifndef OPENCL_HPP
# define OPENCL_HPP

class OpenCL
{
public:
	OpenCL(void);
	OpenCL(OpenCL const & openCL);
	virtual ~OpenCL(void);

	OpenCL & operator=(OpenCL const & openCL);

private:

};

#endif
