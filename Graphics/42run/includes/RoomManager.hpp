#ifndef ROOMMANAGER_HPP
# define ROOMMANAGER_HPP

# include "Room.hpp"
# include <list>
# include <random>

class RoomManager
{
public:
	RoomManager(void);
	virtual ~RoomManager(void);

	float getSpeedFactor(void) const;

	void update(Player & player, float frametime);
	void draw(Shader & shader);

private:
	static const std::size_t			MaxRoom = 10;
	std::list<std::unique_ptr<Room>>	m_rooms;
	std::mt19937						m_engine;
	std::uniform_int_distribution<std::mt19937::result_type>	m_roomEnumDistribution;
	float								m_speedFactor;

	RoomManager(RoomManager const & roomManager);
	RoomManager & operator=(RoomManager const & roomManager);

	void generateRoom(void);

};

#endif
