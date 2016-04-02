#include "Factory.hpp"
#include "RoomStraight.hpp"
#include "RoomStraightLeft.hpp"

std::unique_ptr<Factory> Factory::m_instance = nullptr;

Factory::Factory(void)
{
	m_createRooms[static_cast<int>(RoomType::Straight)] = std::bind(&Factory::createStraight, this);
	m_createRooms[static_cast<int>(RoomType::StraightLeft)] = std::bind(&Factory::createStraightLeft, this);
}

Factory::Factory(Factory const &) {}

Factory & Factory::operator=(Factory const &)
{
	return (*this);
}

Factory & Factory::getInstance(void)
{
	if (m_instance == nullptr)
		m_instance.reset(new Factory());
	return *m_instance;
}

Room * Factory::createRoom(RoomType type) const
{
	return m_createRooms[static_cast<int>(type)]();
}

Room * Factory::createStraight(void) const
{
	return new RoomStraight();
}

Room * Factory::createStraightLeft(void) const
{
	return new RoomStraightLeft();
}
