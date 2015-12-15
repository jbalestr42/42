#include "File.hpp"

File::File(void) {}

File::File(std::string const & filename)
{
	m_file.open(filename);
}

File::File(File const & file)
{
	*this = file;
}

File::~File(void)
{
	m_file.close();
}

File & File::operator=(File const & file)
{
	(void)file;
	return (*this);
}

bool File::readLine(std::string & line)
{
	return getline(m_file,line);
}
