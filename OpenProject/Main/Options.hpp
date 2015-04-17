#ifndef OPTIONS_HPP
# define OPTIONS_HPP

# include <ostream>

# define DISPLAY_BOOL(b) (b ? "true" : "false")
# define CONFIG_VERSION 0x00000004

class Option
{
private:
	struct  SOptions
	{
		int			mn_configVersion; // Update each time we add an option

		int			mn_width;
		int			mn_height;
		unsigned int		mn_framerate;
		bool			mb_limitFramerate;
		bool			mb_verticalsync;
		bool			mb_audio;
		bool			mb_particules;
	};
	SOptions			m_options;

	Option(void);
	~Option(void);

	static Option *msp_current;

public:

	inline SOptions *getOptions(void) { return &m_options; }
	static Option *getCurrent(void);
	static void destroy(void);

	void load(void);
	void save(void);
	void setDefault(void);

	void display(std::ostream & p_ostream) const
	{
		p_ostream << "Options :\n";
		p_ostream << "==== Config version : " << "0x" << std::hex << m_options.mn_configVersion << std::dec << "\n";
		p_ostream << "==== Resolution : " << m_options.mn_width << "x" << m_options.mn_height << "\n";
		p_ostream << "==== Limit Framerate : " << DISPLAY_BOOL(m_options.mb_limitFramerate) << " (" << m_options.mn_framerate << ") \n";
		p_ostream << "==== Vertical Sync : " << DISPLAY_BOOL(m_options.mb_verticalsync) << "\n";
		p_ostream << "==== Audio : " << DISPLAY_BOOL(m_options.mb_audio) << "\n";
		p_ostream << "==== Particules : " << DISPLAY_BOOL(m_options.mb_particules);
	}

	friend std::ostream & operator<<(std::ostream &p_ostream, Option const& p_options)
	{
		p_options.display(p_ostream);
		return p_ostream;
	}

};

#endif
