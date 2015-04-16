#ifndef OCTOFILE_HPP
# define OCTOFILE_HPP

# include <fstream>
# include <string>
# define MAX_SIZE_FILENAME 256
# define IN std::ios::in
# define OUT std::ios::out
# define BIN std::ios::binary

class OctoFile
{
private:
	std::fstream	m_stream;
	char			mp_fileName[MAX_SIZE_FILENAME];
	bool			mb_isOpen;

public:
	OctoFile(void);
	~OctoFile(void);

	virtual bool open(char * ppc_fileName, std::ios_base::openmode p_openMode);
	virtual void read(void * pp_dst, int pn_size);
	virtual void write(std::string const & p_string);
	virtual void write(void * pp_src, int pn_size);
	virtual void close(void);
	bool isOpen(void) const;
};

#endif
