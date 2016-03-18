#include "RoomStraight.hpp"
#include "Keyboard.hpp"
#include <GLFW/glfw3.h>

RoomStraight::RoomStraight(void) :
	Room("resources/corridor.obj")
{ }

void RoomStraight::checkPlayer(Player const & player, float frametime)
{
	Room::checkPlayer(player, frametime);
}
