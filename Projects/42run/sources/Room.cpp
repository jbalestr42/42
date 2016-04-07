#include "Room.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "Shader.hpp"
#include "ResourceManager.hpp"

Room::Room(std::string const & meshName) :
	Transformable(),
	m_mesh(ResourceManager::getInstance().getMesh(meshName)),
	m_timer(0.f),
	m_isValidated(false),
	m_isFailed(false)
{
	rotateY(90.f);
}

Room::Room(Room const & room) :
	Transformable(room)
{
	*this = room;
}

Room::~Room(void) { }

Room & Room::operator=(Room const & room)
{
	Transformable::operator=(room);
	(void)room;
	return (*this);
}

void Room::update(float frametime)
{
	translate({0.f, 0.f, 1.f * frametime});
}

void Room::draw(Shader & shader)
{
	shader.setParameter("ModelMatrix", getMatrix());
	m_mesh->draw();
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
