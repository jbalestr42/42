#include "File.hpp"
#include "Exceptions.hpp"

File::File(std::string const & filename)
{
	m_file.open(filename);
	if (!m_file.is_open())
		throw WrongFileException(filename);
}

File::File(File const & file)
{
	*this = file;
}

File::~File(void)
{
	m_file.close();
}

File & File::operator=(File const &)
{
	return (*this);
}

bool File::readLine(std::string & line)
{
	return static_cast<bool>(std::getline(m_file, line));
}
