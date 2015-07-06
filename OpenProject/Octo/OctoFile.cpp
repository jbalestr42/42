#include "OctoFile.hpp"

#ifdef __linux
	#include <string.h> 
#endif

/* ---------------------------------------------------------------------- */
/*                                Base                                    */
/* ---------------------------------------------------------------------- */
OctoFile::OctoFile(void) :
	mb_isOpen(false)
{
	memset(mp_fileName, 0, MAX_SIZE_FILENAME);
}

OctoFile::~OctoFile(void) { }

/* ---------------------------------------------------------------------- */
/*                              Methods                                   */
/* ---------------------------------------------------------------------- */
bool OctoFile::open(char * ppc_fileName, std::ios_base::openmode p_openMode)
{
	strcpy(mp_fileName, ppc_fileName);
	mb_isOpen = false;
	m_stream.open(mp_fileName, p_openMode);
	if (m_stream.is_open())
		mb_isOpen = true;
	return mb_isOpen;
}

void OctoFile::read(void * pp_dst, int pn_size)
{
	if (mb_isOpen)
		m_stream.read(reinterpret_cast<char *>(pp_dst), pn_size);
}

void OctoFile::write(void * pp_src, int pn_size)
{
	if (mb_isOpen)
		m_stream.write(reinterpret_cast<char *>(pp_src), pn_size);
}

void OctoFile::write(std::string const & p_string)
{
	if (mb_isOpen)
		m_stream.write(p_string.c_str(), p_string.length());
}

void OctoFile::close(void)
{
	if (mb_isOpen)
		m_stream.close();
	mb_isOpen = false;
}

bool OctoFile::isOpen(void) const
{
	return mb_isOpen;
}
