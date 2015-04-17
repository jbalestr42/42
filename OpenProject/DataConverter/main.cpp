#include <iostream>
#include "ResourcesManager.hpp"
#include "Octo/OctoLogger.hpp"

//TODO: Add argument to recreate all files from data
int main(int argc, char ** argv)
{
	OctoLogger::log("Init Data Converter");

	if (argc != 2)
	{
		std::cout << "Specify directory as parameter." << std::endl;
		return (1);
	}

	ResourcesManager &file = ResourcesManager::getCurrent();
	file.createResources(argv[1]);
	file.destroy();

	OctoLogger::destroy();
	return (0);
}
