#include "Options.hpp"
#include "Octo/OctoFile.hpp"
#include "Octo/OctoLogger.hpp"

Option * Option::msp_current = NULL;

Option::Option()
{
	setDefault();
}

Option::~Option()
{
}

Option *Option::getCurrent(void)
{
	if (msp_current == NULL)
		msp_current = new Option();

	return msp_current;
}

void Option::destroy(void)
{
	if (msp_current == NULL)
		return;

	msp_current->save();
	delete msp_current;
	msp_current = NULL;
}

void Option::save(void)
{
	OctoFile File;
	char pFilename[256] = "options.cfg";
	bool bOpen = File.open(pFilename, OUT | BIN);

	if (bOpen)
	{
		OctoLogger::log("Save Options");
		File.write(&m_options, sizeof(SOptions));
		File.close();
	}
	else
	{
		OctoLogger::log("Load Options : Can't open configuration file, default options used...");
	}
}

void Option::load(void)
{
	OctoFile File;
	char pFilename[256] = "options.cfg";
	bool bOpen = File.open(pFilename, IN | BIN);

	if (bOpen)
	{
		File.read(&m_options, sizeof(SOptions));
		File.close();

		if (m_options.mn_configVersion != CONFIG_VERSION)
		{
			OctoLogger::log("Load Options : Obsolete version of configuration file, default used...");
			setDefault();
			OctoLogger::log() << *this;
		}
		else
		{
			OctoLogger::log("Load Options");
			OctoLogger::log() << *this;
		}

	}
	else
		OctoLogger::log("Load Options : Can't open configuration file, default options used...");
}

void Option::setDefault(void)
{
	m_options.mn_configVersion = CONFIG_VERSION;

	m_options.mn_width = 1280;
	m_options.mn_height = 720;
	m_options.mn_framerate = 60;
	m_options.mb_limitFramerate = false;
	m_options.mb_verticalsync = false;
	m_options.mb_audio = true;
	m_options.mb_particules = true;
}
