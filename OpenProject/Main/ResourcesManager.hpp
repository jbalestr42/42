#ifndef DATAMANAGER_HPP
# define DATAMANAGER_HPP

# include <vector>
# include <iostream>
# include <ftw.h>
# include <fnmatch.h>
# include <map>
# include <SFML/Graphics.hpp>
# include "DefineResources.hpp"

class ResourcesManager
{
public:
	struct File
	{
		enum EFileType
		{
			e_fileType_texture,
			e_fileType_font,
			e_fileType_json,

			e_fileType_nb
		};

		struct Header
		{
			int		mn_size;
			int		mn_nameSize;
			char	m_name[256];
		};

		Header						m_header;
		std::vector<unsigned char>	m_buffer;

		File(void);
		File(int pn_size, std::string p_name);
		~File(void);
		friend std::ostream & operator<<(std::ostream & p_ostream, File const & p_file);

	};

	struct MainHeader
	{
		int		mn_nbFile[File::e_fileType_nb];
		int		mn_totalSize;

		MainHeader(void);
		~MainHeader(void);

	};

private:
	MainHeader							m_mainHeader;
	std::map<int, std::vector<File>>	m_files;
	sf::Texture **						mpp_textures;
	sf::Font **							mpp_fonts;
	char **								mpp_fontsData;
	std::string *						mpp_jsons;
	static ResourcesManager *			msp_current;

	ResourcesManager(void);
	void parseJson(void);

public:
	virtual ~ResourcesManager(void);

	static ResourcesManager & getCurrent(void);
	void destroy(void);
	void read(std::string const & p_filename, File::EFileType pe_fileType);
	void readJson(std::string const & p_filename);
	void createResources(std::string const & p_path);
	void createFiles(std::string const & p_filename);
	void createMemoryFile(std::string const & p_filename);

	sf::Texture & getTexture(int pn_index) const;
	sf::Font & getFont(int pn_index) const;
	std::string & getJson(int pn_index) const;

};

#endif
