#include "Room.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"

Room::Room(std::string const & meshName, std::string const & textureName) :
	Model(meshName, textureName),
	m_timer(0.f),
	m_isValidated(false),
	m_isFailed(false)
{
	rotateY(90.f);
}

Room::Room(Room const & room) :
	Model(room)
{
	*this = room;
}

Room::~Room(void) { }

Room & Room::operator=(Room const & room)
{
	Room::operator=(room);
	(void)room;
	return (*this);
}

void Room::update(float frametime)
{
	translate({0.f, 0.f, 1.f * frametime});
}

void Room::addTimer(float frametime)
{
	m_timer += frametime;
}

float Room::getTimer(void) const
{
	return m_timer;
}

bool Room::isValidated(void) const
{
	return m_isValidated;
}

void Room::setIsValidated(bool isValidated)
{
	m_isValidated = isValidated;
}

void Room::setIsFailed(bool failed)
{
	m_isFailed = failed;
}

bool Room::isFailed(void) const
{
	return m_isFailed;
}

void Room::checkPlayer(Player const & player, float )
{
	if (getPosition().z > player.getPosition().z + 1.f)
		setIsValidated(true);
}
