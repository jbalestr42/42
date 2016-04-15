#ifndef FACTORY_HPP
# define FACTORY_HPP

# include <memory>
# include "Room.hpp"

class Factory
{
public:
	~Factory(void) = default;

	static Factory & getInstance(void);
	Room * createRoom(RoomType type) const;

private:
	typedef std::function<Room *(void)>	CreateRoom;

	static std::unique_ptr<Factory>	m_instance;
	CreateRoom						m_createRooms[5];

	Factory(void);
	Factory(Factory const & factory);
	Factory & operator=(Factory const & factory);

	Room * createStraight(void) const;
	Room * createStraightLeft(void) const;

};

#endif
