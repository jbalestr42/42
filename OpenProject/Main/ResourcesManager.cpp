#include "ResourcesManager.hpp"
#include "Octo/OctoLogger.hpp"
#include <string.h>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <assert.h>

ResourcesManager *ResourcesManager::msp_current = 0;

/* ---------------------------------------------------------------------- */
/*                              Base                                      */
/* ---------------------------------------------------------------------- */
ResourcesManager::ResourcesManager(void) :
	mpp_textures(NULL),
	mpp_fonts(NULL),
	mpp_fontsData(NULL),
	mpp_jsons(NULL)
{
	OctoLogger::log() << "Create Resources Manager";
}

ResourcesManager::~ResourcesManager(void)
{
	if (mpp_textures)
	{
		for (int i = 0; i < m_mainHeader.mn_nbFile[File::e_fileType_texture]; ++i)
		{
			delete mpp_textures[i];
			mpp_textures[i] = NULL;
		}
		delete [] mpp_textures;
		mpp_textures = NULL;
	}
	if (mpp_fonts)
	{
		for (int i = 0; i < m_mainHeader.mn_nbFile[File::e_fileType_font]; ++i)
		{
			delete mpp_fonts[i];
			delete mpp_fontsData[i];
			mpp_fontsData[i] = NULL;
		}
		delete [] mpp_fonts;
		delete [] mpp_fontsData;
		mpp_fontsData = NULL;
	}
	if (mpp_jsons)
	{
		delete [] mpp_jsons;
		mpp_jsons = NULL;
	}
	OctoLogger::log() << "Destoy Resources Manager";
}

ResourcesManager & ResourcesManager::getCurrent(void)
{
	if (!msp_current)
		msp_current = new ResourcesManager();
	return (*msp_current);
}

void ResourcesManager::destroy(void)
{
	if (msp_current)
		delete msp_current;
	msp_current = 0;
}

void ResourcesManager::readJson(std::string const & p_filename)
{
	int index = p_filename.find_last_of("/\\");
	std::string filename = p_filename.substr(index + 1);

	std::string done;
	std::ifstream ifs(p_filename);
	std::string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	std::istringstream iss(str);
	std::string line;
	while (std::getline(iss, line))
	{
		if (line.find("file") != std::string::npos)
		{
			int len = 0;
			for (int i = line.length(); i > 0; i--)
			{
				if (line[i] == '"' && line[i - 2] == ':')
				{
					std::string toReplace = line.substr(i + 1, len - 1);
					int n = toReplace.find_last_of("/\\");
					toReplace = toReplace.substr(n + 1);
					for (int j = 0; j < m_files[File::e_fileType_texture].size(); j++)
					{
						if (toReplace == m_files[File::e_fileType_texture][j].m_header.m_name)
						{
							std::stringstream ss;
							ss << j;
							done += line.replace(i + 1, len - 1, ss.str());
							break;
						}
					}
				}
				else if (line[i] == '"' || line[i] == ',')
					continue;
				else
					len++;
			}
		}
		else
			done += line;
	}
	ifs.close();

	File file(done.length(), filename);
	file.m_buffer.reserve(file.m_header.mn_size);
	std::copy(done.begin(), done.end(), back_inserter(file.m_buffer));
	m_files[File::e_fileType_json].push_back(file);
	m_mainHeader.mn_nbFile[File::e_fileType_json]++;
	m_mainHeader.mn_totalSize += file.m_header.mn_size;
}

void ResourcesManager::read(std::string const & p_filename, File::EFileType pe_fileType)
{
	int index = p_filename.find_last_of("/\\");
	std::string filename = p_filename.substr(index + 1);

	std::ifstream ifs;
	ifs.open(p_filename.c_str(), std::ios::binary);
	ifs.unsetf(std::ios::skipws);
	ifs.seekg(0, ifs.end);

	File file(ifs.tellg(), filename);
	ifs.seekg(0, ifs.beg);

	file.m_buffer.reserve(file.m_header.mn_size);
	file.m_buffer.insert(file.m_buffer.begin(), std::istream_iterator<unsigned char>(ifs), std::istream_iterator<unsigned char>());
	m_files[pe_fileType].push_back(file);
	m_mainHeader.mn_nbFile[pe_fileType]++;
	m_mainHeader.mn_totalSize += file.m_header.mn_size;
	ifs.close();
}

int callbackImages(char const *p_path, struct stat const *p_stat, int p_typeFlag)
{
	const char *filters[] =
	{
		"*.jpg", "*.jpeg", "*.png", "*.gif"
	}; 
	(void)p_stat;
	// if it's a file
	if (p_typeFlag == FTW_F)
	{
		// for each filter
		for (unsigned i = 0; i < sizeof(filters) / sizeof(filters[0]); i++)
		{
			// if the filename matches the filter
			if (fnmatch(filters[i], p_path, FNM_CASEFOLD) == 0)
			{
				// do something
				OctoLogger::log("Found image: %s", p_path);
				ResourcesManager::getCurrent().read(p_path, ResourcesManager::File::e_fileType_texture);
				break;
			}
		}
	}
	// tell ftw to continue
	return 0;
}

int callbackFonts(char const *p_path, struct stat const *p_stat, int p_typeFlag)
{
	const char *filters[] =
	{
		"*.ttf"
	};

	(void)p_stat;
	// if it's a file
	if (p_typeFlag == FTW_F)
	{
		// for each filter
		for (unsigned i = 0; i < sizeof(filters) / sizeof(filters[0]); i++)
		{
			// if the filename matches the filter
			if (fnmatch(filters[i], p_path, FNM_CASEFOLD) == 0)
			{
				// do something
				OctoLogger::log("Found font: %s", p_path);
				ResourcesManager::getCurrent().read(p_path, ResourcesManager::File::e_fileType_font);
				break;
			}
		}
	}
	// tell ftw to continue
	return 0;
}

int callbackJsons(char const *p_path, struct stat const *p_stat, int p_typeFlag)
{
	const char *filters[] =
	{
		"*.json"
	};

	(void)p_stat;
	// if it's a file
	if (p_typeFlag == FTW_F)
	{
		// for each filter
		for (unsigned i = 0; i < sizeof(filters) / sizeof(filters[0]); i++)
		{
			// if the filename matches the filter
			if (fnmatch(filters[i], p_path, FNM_CASEFOLD) == 0)
			{
				// do something
				OctoLogger::log("Found json: %s", p_path);
				ResourcesManager::getCurrent().readJson(p_path);
				break;
			}
		}
	}
	// tell ftw to continue
	return 0;
}

void ResourcesManager::parseJson(void)
{
	for (int i = 0; i < m_mainHeader.mn_nbFile[File::e_fileType_json]; i++)
	{
		std::string s(m_files[File::e_fileType_json][i].m_buffer.begin(), m_files[File::e_fileType_json][i].m_buffer.end());
		std::string::size_type start_pos = 0;
		while (std::string::npos != (start_pos = s.find("spawner_", start_pos)))
		{
			// do something with start_pos or store it in a container
			int k = 0;
			while (s[start_pos + k] != '\"')
				k++;
			std::string toReplace = s.substr(start_pos, k);
			toReplace = toReplace.substr(toReplace.find("_") + 1);
			toReplace += ".json";
			for (int j = 0; j < m_mainHeader.mn_nbFile[File::e_fileType_json]; j++)
			{
				std::string fileName = m_files[File::e_fileType_json][j].m_header.m_name;
				if (fileName == toReplace)
				{
					std::stringstream ss;
					ss << j;
					toReplace = ss.str();
				}
			}
			std::string ss = s.replace(start_pos, k, toReplace);
			++start_pos;
		}
		m_files[File::e_fileType_json][i].m_buffer.clear();
		m_files[File::e_fileType_json][i].m_buffer.reserve(s.length());
		std::copy(s.begin(), s.end(), back_inserter(m_files[File::e_fileType_json][i].m_buffer));
	}
}

void ResourcesManager::createResources(std::string const & p_path)
{
	char const *pDefines[File::e_fileType_nb] =
	{
		"TEXTURE",
		"FONT",
		"JSON",
	};
	ftw(p_path.c_str(), callbackImages, 16); // 16 = depth
	ftw(p_path.c_str(), callbackFonts, 16);
	ftw(p_path.c_str(), callbackJsons, 16);
	parseJson();

	std::ofstream ofs;
	ofs.open("data", std::ios::binary);
	if (ofs.is_open())
	{
		std::ofstream ofsInclude;
		OctoLogger::log("Generating data...");
		ofsInclude.open("DefineResources.hpp");
		ofs.write(reinterpret_cast<char *>(&m_mainHeader), sizeof(MainHeader));
		for (int j = 0; j < File::e_fileType_nb; j++)
		{
			int nbFile = 0;
			for (int i = 0; i < m_mainHeader.mn_nbFile[j]; i++)
			{
				ofs.write(reinterpret_cast<char *>(&m_files[j][i].m_header), sizeof(File::Header));
				ofs.write((char *)&m_files[j][i].m_buffer[0], m_files[j][i].m_header.mn_size);

				// Parse name
				std::string str = m_files[j][i].m_header.m_name;
				str = str.substr(0, str.find("."));											// Withdraw extension
				std::transform(str.begin(), str.end(),str.begin(), ::toupper);				// To upper
				std::replace(str.begin(), str.end(), '-', '_');								// Replace char '-' by '_'
				std::replace(str.begin(), str.end(), ' ', '_');								// Replace char ' ' by '_'
				ofsInclude << "#define " << pDefines[j] << "_" << str << " " << nbFile++ << std::endl;
			}
			ofsInclude << std::endl;
		}
		ofs.close();
		ofsInclude.close();
	}
	else
		std::cout << "Fail to open file." << std::endl;
}

void ResourcesManager::createFiles(std::string const & p_filename)
{
	/*M`
	std::ifstream ifs;
	ifs.open(p_filename.c_str(), std::ios::binary);
	if (ifs.is_open())M`
	{
		ifs.read(reinterpret_cast<char *>(&m_mainHeader), sizeof(MainHeader));
		std::cout << "CrM`eating " << m_mainHeader.mn_nbTexture << " file(s)." << std::endl;
		for (int i = 0; i < m_mainHeader.mn_nbTexture; i++)
		{
			File file;M`
			ifs.read(reinterpret_cast<char *>(&file.m_header), sizeof(File::Header));
			char *pBuffer = new char[file.m_header.mn_size];
			ifs.read(pBuffM`er, file.m_header.mn_size);
			std::cout << file;

			std::ofstreaM`m ofs;
			ofs.open(file.m_header.m_name, std::ios::binary | std::ios::trunc);
			ofs.write(pBuffer, file.m_header.mn_size);
			ofs.close(M`);
			delete [] pBuffer;
		}
		ifs.close();M`
	}
	else
		std::cout << "Fail to open data file." << std::M`endl;
*/}

void ResourcesManager::createMemoryFile(std::string const & p_filename)
{
	std::ifstream ifs;
	ifs.open(p_filename.c_str(), std::ios::binary);
	if (ifs.is_open())
	{
		ifs.read(reinterpret_cast<char *>(&m_mainHeader), sizeof(MainHeader));
		mpp_textures = new sf::Texture*[m_mainHeader.mn_nbFile[File::e_fileType_texture]];
		mpp_fonts = new sf::Font*[m_mainHeader.mn_nbFile[File::e_fileType_font]];
		mpp_fontsData = new char*[m_mainHeader.mn_nbFile[File::e_fileType_font]];
		mpp_jsons = new std::string[m_mainHeader.mn_nbFile[File::e_fileType_json]];
		for (int j = 0; j < File::e_fileType_nb; j++)
		{
			OctoLogger::log("Loading %d file(s).", m_mainHeader.mn_nbFile[j]);
			OctoLogger::log().desactivateTime();
			for (int i = 0; i < m_mainHeader.mn_nbFile[j]; i++)
			{
				File file;
				ifs.read(reinterpret_cast<char *>(&file.m_header), sizeof(File::Header));
				OctoLogger::log() << file;

				switch (j)
				{
					case File::e_fileType_texture:
					{
						char *pBuffer = new char[file.m_header.mn_size];
						ifs.read(pBuffer, file.m_header.mn_size);
						sf::Texture *pTexture = new sf::Texture();
						if (!pTexture->loadFromMemory(pBuffer, file.m_header.mn_size))
							OctoLogger::log("Failed to create texture : %d", file.m_header.m_name);
						else
							mpp_textures[i] = pTexture;
						delete [] pBuffer;
						break;
					}
					case File::e_fileType_font:
					{
						mpp_fontsData[i] = new char[file.m_header.mn_size];
						ifs.read(mpp_fontsData[i], file.m_header.mn_size);
						sf::Font *pFont = new sf::Font;
						if (!pFont->loadFromMemory(mpp_fontsData[i], file.m_header.mn_size))
							OctoLogger::log("Failed to create font : %d", file.m_header.m_name);
						else
							mpp_fonts[i] = pFont;
						break;
					}
					case File::e_fileType_json:
					{
						char *pBuffer = new char[file.m_header.mn_size];
						ifs.read(pBuffer, file.m_header.mn_size);
						mpp_jsons[i].assign(pBuffer, file.m_header.mn_size);
						delete [] pBuffer;
						break;
					}
				}
			}
			OctoLogger::log().activateTime();
		}
		ifs.close();
	}
	else
		OctoLogger::log("Fail to open data file: " + p_filename);
}

sf::Texture & ResourcesManager::getTexture(int pn_index) const
{
	assert(pn_index >= 0 || pn_index < m_mainHeader.mn_nbFile[File::e_fileType_texture]);
	return (*mpp_textures[pn_index]);
}

sf::Font & ResourcesManager::getFont(int pn_index) const
{
	assert(pn_index >= 0 || pn_index < m_mainHeader.mn_nbFile[File::e_fileType_font]);
	return (*mpp_fonts[pn_index]);
}

std::string & ResourcesManager::getJson(int pn_index) const
{
	assert(pn_index >= 0 || pn_index < m_mainHeader.mn_nbFile[File::e_fileType_json]);
	return (mpp_jsons[pn_index]);
}

/* ---------------------------------------------------------------------- */
/*                              Main Header                               */
/* ---------------------------------------------------------------------- */
ResourcesManager::MainHeader::MainHeader(void) :
	mn_totalSize(0)
{
	for (int i = 0; i < File::e_fileType_nb; i++)
		mn_nbFile[i] = 0;
}

ResourcesManager::MainHeader::~MainHeader(void) {}

/* ---------------------------------------------------------------------- */
/*                                File                                    */
/* ---------------------------------------------------------------------- */
ResourcesManager::File::File(void)
{
	m_header.mn_size = 0;
	m_header.mn_nameSize = 0;
	memset(m_header.m_name, 0, 256);
}

ResourcesManager::File::File(int pn_size, std::string p_name)
{
	m_header.mn_size = pn_size;
	m_header.mn_nameSize = p_name.size();
	memset(m_header.m_name, 0, 256);
	memcpy(m_header.m_name, p_name.c_str(), p_name.size());
}

ResourcesManager::File::~File(void) {}

std::ostream & operator<<(std::ostream & p_ostream, ResourcesManager::File const & p_file)
{
	p_ostream << "==== " << p_file.m_header.m_name << " (" << p_file.m_header.mn_nameSize << ") " << p_file.m_header.mn_size << " bits.";
	return (p_ostream);
}
