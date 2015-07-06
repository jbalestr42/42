#include "SFMLDisplay.hpp"
#include "Define.hpp"
#include <sstream>
#include <iomanip>

// TODO initialisation
SFMLDisplay::SFMLDisplay(void) :
	IMonitorDisplay()
{}

SFMLDisplay::SFMLDisplay(IInfosGetter * pp_infos) :
	IMonitorDisplay(pp_infos),
	m_cpuGraph(0),
	m_threadGraph(0),
	m_taskGraph(0),
	m_ramGraph(0),
	m_cpuUsage(0),
	m_cpuTask(0),
	m_cpuThread(0),
	m_cpuLoadAvg(0),
	m_cpuMatchFactor(0),
	m_ramUsage(0),
	m_time(0)
{}

SFMLDisplay::SFMLDisplay(SFMLDisplay const & p_sfmlDisplay) :
	IMonitorDisplay()
{
	*this = p_sfmlDisplay;
}

SFMLDisplay const &	SFMLDisplay::operator=(SFMLDisplay const & p_sfmlDisplay)
{
	static_cast<void>(p_sfmlDisplay);
	return (*this);
}

SFMLDisplay::~SFMLDisplay(void)
{
	for (std::list<sf::Text *>::iterator it = m_texts.begin(); it != m_texts.end(); it++)
		delete (*it);
	if (m_cpuGraph)
		delete m_cpuGraph;
	if (m_ramGraph)
		delete m_ramGraph;
	if (m_threadGraph)
		delete m_threadGraph;
	if (m_taskGraph)
		delete m_taskGraph;
	if (m_cpuUsage)
		delete m_cpuUsage;
	if (m_cpuTask)
		delete m_cpuTask;
	if (m_cpuThread)
		delete m_cpuThread;
	if (m_cpuLoadAvg)
		delete m_cpuLoadAvg;
	if (m_cpuMatchFactor)
		delete m_cpuMatchFactor;
	if (m_ramUsage)
		delete m_ramUsage;
	if (m_time)
		delete m_time;
}

void SFMLDisplay::init(void)
{
	m_cpuGraph = new Graph(20, 100.f, 200.f, 100.f);
	m_cpuGraph->setPosition(40.f, 20.f);

	m_threadGraph = new Graph(20, 1500.f, 200.f, 100.f);
	m_threadGraph->setPosition(280.f, 20.f);

	m_taskGraph = new Graph(20, 500.f, 200.f, 100.f);
	m_taskGraph->setPosition(520.f, 20.f);

	std::string str = "Boring monitoring - " + mp_infos->getInfo(USER_NAME) + "@" + mp_infos->getInfo(HOST_NAME);
	m_window.create(sf::VideoMode(800, 600), str.c_str());

	if (!m_font.loadFromFile("font/arial.ttf"))
		return;

	// OS Info
	sf::Text *osxName = getNewText(12, 610.f, 520.f);
	osxName->setString("Product Name :    " + mp_infos->getInfo(OSX_NAME));
	m_texts.push_back(osxName);

	sf::Text *osxVersion = getNewText(12, 610.f, 540.f);
	osxVersion->setString("Product Version : " + mp_infos->getInfo(OSX_VERSION));
	m_texts.push_back(osxVersion);

	sf::Text *osxBuild = getNewText(12, 610.f, 560.f);
	osxBuild->setString("Build Version :      " + mp_infos->getInfo(OSX_BUILD));
	m_texts.push_back(osxBuild);

	sf::Text *kernel = getNewText(12, 610.f, 580.f);
	kernel->setString("Kernel Version :    " + mp_infos->getInfo(KERNEL_VERSION));
	m_texts.push_back(kernel);

	// CPU
	sf::Text *cpuMax = getNewText(12, 5.f, 20.f);
	cpuMax->setString("100%");
	m_texts.push_back(cpuMax);

	sf::Text *cpuTaskMax = getNewText(12, 497.f, 20.f);
	cpuTaskMax->setString("500");
	m_texts.push_back(cpuTaskMax);

	sf::Text *cpuThreadMax = getNewText(12, 248.f, 20.f);
	cpuThreadMax->setString("1500");
	m_texts.push_back(cpuThreadMax);

	sf::Text *cpuName = getNewText(12, 40.f, 160.f);
	cpuName->setString(mp_infos->getInfo(CPU_NAME) + " (x" + mp_infos->getInfo(CPU_NBPROCESSOR) + ")");
	m_texts.push_back(cpuName);

	m_cpuTask = getNewText(12, 520.f, 125.f);
	m_cpuThread = getNewText(12, 280.f, 125.f);
	m_cpuUsage = getNewText(12, 40.f, 125.f);
	m_cpuLoadAvg = getNewText(12, 40.f, 180.f);
	m_cpuMatchFactor = getNewText(12, 40.f, 200.f);

	// RAM
	sf::Text *ramMax = getNewText(12, 4.f, 240.f);
	float fRam = atof(mp_infos->getInfo(MAX_RAM).c_str()) / 1000000.f;
	std::stringstream ss;
	ss << std::setprecision(2) << fRam << "GB";
	ramMax->setString(ss.str().c_str());
	m_texts.push_back(ramMax);

	m_ramGraph = new Graph(40, fRam, 700.f, 250.f);
	m_ramGraph->setPosition(40.f, 240.f);
	m_ramUsage = getNewText(12, 40.f, 500.f);

	// Time
	m_time = getNewText(12, 8.f, 580.f);

	m_texture = new sf::Texture();
	m_texture->loadFromFile("gary.png");
	m_sprite = new sf::Sprite();
	m_sprite->setTexture(*m_texture);
	m_sprite->setPosition(0.f, 500.f);
	m_sprite->setScale(0.3f, 0.3f);
}

sf::Text * SFMLDisplay::getNewText(unsigned int p_size, float pf_x, float pf_y)
{
	sf::Text *text = new sf::Text();

	text->setFont(m_font);
	text->setCharacterSize(p_size);
	text->setPosition(sf::Vector2f(pf_x, pf_y));
	return text;
}

void SFMLDisplay::process(void)
{
	std::stringstream ss;

	float fVal = atof(mp_infos->getInfo(CPU_USAGE).c_str());
	m_cpuGraph->addValue(fVal);
	ss << "CPU usage " << std::setprecision(2) << fVal << "%";
	m_cpuUsage->setString(ss.str().c_str());

	float fRamVal = atof(mp_infos->getInfo(CURRENT_RAM).c_str()) / 1000000.f;
	ss.str("");
	m_ramGraph->addValue(fRamVal);
	ss << "RAM usage " << std::setprecision(2) << fRamVal << "GB";
	m_ramUsage->setString(ss.str().c_str());

	int nTask = atoi(mp_infos->getInfo(CPU_CURTASKS).c_str());
	ss.str("");
	m_taskGraph->addValue(nTask);
	ss << "Tasks : " << nTask;
	m_cpuTask->setString(ss.str().c_str());

	int nThread = atoi(mp_infos->getInfo(CPU_CURTHREAD).c_str());
	ss.str("");
	m_threadGraph->addValue(nThread);
	ss << "Threads : " << nThread;
	m_cpuThread->setString(ss.str().c_str());

	float fLoad = atof(mp_infos->getInfo(CPU_LOADAVERAGE).c_str());
	ss.str("");
	ss << "Load Average : " << fLoad;
	m_cpuLoadAvg->setString(ss.str().c_str());

	float fMatch = atof(mp_infos->getInfo(CPU_MATCHFACTOR).c_str());
	ss.str("");
	ss << "Match factoe : " << fMatch;
	m_cpuMatchFactor->setString(ss.str().c_str());

	m_time->setString(mp_infos->getInfo(TIME) + " - " + mp_infos->getInfo(DATE));
}

bool SFMLDisplay::display(void)
{
	// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
	if (!m_window.isOpen())
		return true;
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		// évènement "fermeture demandée" : on ferme la fenêtre
		if (event.type == sf::Event::Closed)
			m_window.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			m_window.close();
	}

	m_sprite->move(1.5f, 0.f);

	m_window.clear(sf::Color::Black);
	m_window.draw(*m_cpuGraph);
	m_window.draw(*m_ramGraph);
	m_window.draw(*m_threadGraph);
	m_window.draw(*m_taskGraph);
	// Display texts
	for (std::list<sf::Text *>::iterator it = m_texts.begin(); it != m_texts.end(); it++)
		m_window.draw(**it);
	m_window.draw(*m_cpuUsage);
	m_window.draw(*m_cpuTask);
	m_window.draw(*m_cpuThread);
	m_window.draw(*m_cpuLoadAvg);
	m_window.draw(*m_cpuMatchFactor);
	m_window.draw(*m_ramUsage);
	m_window.draw(*m_time);
	m_window.draw(*m_sprite);
	m_window.display();
	return false;
}
