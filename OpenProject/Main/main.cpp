#include <SFML/Graphics.hpp>
#include "GameManager.hpp"

int main()
{
	GameManager & manager = GameManager::getCurrent();

	manager.init();
	manager.run();

	manager.destroy();
	return (EXIT_SUCCESS);
}
