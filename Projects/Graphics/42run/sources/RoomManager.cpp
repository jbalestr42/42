#include "RoomManager.hpp"
#include "Factory.hpp"

RoomManager::RoomManager(void) :
	m_roomEnumDistribution(0, 1),
	m_speedFactor(1.f)
{
	m_engine.seed(std::random_device()());
	m_rooms.emplace_back(Factory::getInstance().createRoom(RoomType::Straight));
	for (std::size_t i = 0u; i < MaxRoom; i++)
		generateRoom();
}

RoomManager::RoomManager(RoomManager const & roomManager)
{
	*this = roomManager;
}

RoomManager::~RoomManager(void) { }

RoomManager & RoomManager::operator=(RoomManager const & roomManager)
{
	(void)roomManager;
	return (*this);
}

float RoomManager::getSpeedFactor(void) const
{
	return m_speedFactor;
}

void RoomManager::update(Player & player, float frametime)
{
	m_speedFactor *= 1.00001f;
	player.setSpeedFactor(m_speedFactor);
	(*std::next(m_rooms.begin()))->checkPlayer(player, frametime);
	for (auto & room : m_rooms)
		room->update(frametime * m_speedFactor);
	if ((*std::next(m_rooms.begin()))->isFailed())
		std::cout << "FAIL" << std::endl;
	if ((*std::next(m_rooms.begin()))->isValidated())
		generateRoom();
}

void RoomManager::draw(Shader & shader)
{
	for (auto & room : m_rooms)
		room->draw(shader);
}

void RoomManager::generateRoom(void)
{
	int i = m_roomEnumDistribution(m_engine);
	std::cout << i << std::endl;
	Room * room = Factory::getInstance().createRoom(static_cast<RoomType>(i));
	if (m_rooms.size() > MaxRoom)
		m_rooms.pop_front();
	room->translate(m_rooms.back()->getPosition() - Vector3(0.f, 0.f, 2.f));
	m_rooms.emplace_back(room);
}
