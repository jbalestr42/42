#include "BoringInfos.hpp"
#include <iostream>
#include <list>
#include "Define.hpp"
#include "HostModule.hpp"
#include "OSModule.hpp"
#include "ClockModule.hpp"
#include "RAMModule.hpp"
#include "CPUModule.hpp"
#include "SFMLDisplay.hpp"
#include "NcursesDisplay.hpp"

int					main(void)
{
	BoringInfos					b;
	std::list<IMonitorModule *>	m;
	IMonitorDisplay *			d;

	std::cout << "Hello !" << std::endl;
	std::cout << "Graphic mode : 1 (Good choice)" << std::endl;
	std::cout << "Classic mode : 2 (Bad choice)" << std::endl;
	std::cout << "Exit         : 3 (Good choice too)" << std::endl;

	while (1)
	{
		int nChoice;
		std::cin >> nChoice;
		if (nChoice == 1)
		{
			d = new SFMLDisplay(&b);
			break;
		}
		else if (nChoice == 2)
		{
			d = new NcursesDisplay(&b);
			break;
		}
		else if (nChoice == 3)
			return (1);
		std::cout << "Try again, choose a number between 1 (included) and 3 (also included)" << std::endl;
	}

	m.push_back(new HostModule(&b));
	m.push_back(new OSModule(&b));
	m.push_back(new ClockModule(&b));
	m.push_back(new RAMModule(&b));
	m.push_back(new CPUModule(&b));

	// Update once, then we can use infos d->init()
	std::list<IMonitorModule *>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		(*it)->process();
		(*it)->refresh();
	}

	d->init();
	bool bExit = false;
	float fTimer = 1.f;
	sf::Clock clock;
	while (!bExit)
	{
		fTimer += clock.restart().asSeconds();
		if (fTimer >= 0.5f) // Refresh data each second
		{
			fTimer = 0.f;
			std::list<IMonitorModule *>::iterator it;
			for (it = m.begin(); it != m.end(); it++)
			{
				(*it)->process();
				(*it)->refresh();
			}
			d->process();
		}
		bExit = d->display();
	}
	for (it = m.begin(); it != m.end(); it++)
		delete *it;
	delete d;
	return (0);
}
