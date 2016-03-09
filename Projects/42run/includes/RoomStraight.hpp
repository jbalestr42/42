#ifndef ROOMSTRAIGHT_HPP
# define ROOMSTRAIGHT_HPP

# include "Room.hpp"

class RoomStraight : public Room
{
public:
	RoomStraight(void);
	virtual ~RoomStraight(void) = default;

	virtual void checkPlayer(Player const & player, float frametime);

private:

};

#endif
