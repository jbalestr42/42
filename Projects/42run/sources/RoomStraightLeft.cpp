#include "RoomStraightLeft.hpp"

RoomStraightLeft::RoomStraightLeft(void) :
	Room("resources/chaise.obj")
{
	rotateY(-90.f);
}

RoomStraightLeft::~RoomStraightLeft(void) { }

void RoomStraightLeft::checkPlayer(Player const & player, float frametime) // TODO remove frametime
{
	// from -3 to -1 on z axis
	Room::checkPlayer(player, frametime);
	//std::cout << getPosition() << std::endl;
	if (getPosition().z > -2.5f && getPosition().z < -1.5f)
	{
		//std::cout << "inside" << std::endl;
		if (player.getPosition().x > 0.f)
		{
			//std::cout << "wrong side" << std::endl;
			setIsFailed(true);
		}
		else
			(void)player;//std::cout << "good side" << std::endl;
	}
	else
		(void)player;//std::cout << "outside" << std::endl;
}
