#ifndef FILE_HPP
# define FILE_HPP

# include <fstream>

class File
{
public:
	File(std::string const & filename);
	virtual ~File(void);

	bool readLine(std::string & line);

private:
	std::ifstream	m_file;

	File(void) = default;
	File(File const & file);
	File & operator=(const File & file);

};

#endif
