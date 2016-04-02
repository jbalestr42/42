#ifndef ROOMSTRAIGHTLEFT_HPP
# define ROOMSTRAIGHTLEFT_HPP

# include "Room.hpp"

class RoomStraightLeft : public Room
{
public:
	RoomStraightLeft(void);
	virtual ~RoomStraightLeft(void);

	void checkPlayer(Player const & player, float frametime);

private:

};

#endif
