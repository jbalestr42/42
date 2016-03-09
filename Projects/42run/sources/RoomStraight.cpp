#include "RoomStraight.hpp"
#include "Keyboard.hpp"
#include <GLFW/glfw3.h>

RoomStraight::RoomStraight(void) :
	Room("resources/corridor.obj", "resources/cat.bmp")
{ }

void RoomStraight::checkPlayer(Player const & player, float frametime)
{
	Room::checkPlayer(player, frametime);
}
