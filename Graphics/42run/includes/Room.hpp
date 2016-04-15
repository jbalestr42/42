#ifndef ROOM_HPP
# define ROOM_HPP

# include "Mesh.hpp"
# include "Vector3.hpp"
# include "Player.hpp"

enum class RoomType : std::uint8_t
{
	Straight,
	StraightLeft,
	StraightRight,
	Jump,
	TurnLeft,
	TurnRight
};

class Room : public Transformable
{
public:
	Room(std::string const & meshName);
	Room(Room const & room);
	virtual ~Room(void);

	Room & operator=(Room const & room);

	bool isValidated(void) const;
	bool isFailed(void) const;
	void update(float frametime);
	void draw(Shader & shader);

	virtual void checkPlayer(Player const & player, float frametime);

protected:
	void addTimer(float frametime);
	float getTimer(void) const;
	void setIsValidated(bool isValidated);
	void setIsFailed(bool failed);

private:
	std::shared_ptr<Mesh>	m_mesh;
	float					m_timer;
	bool					m_isValidated;
	bool					m_isFailed;

};

#endif
