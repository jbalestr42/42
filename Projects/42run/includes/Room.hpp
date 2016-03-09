#ifndef ROOM_HPP
# define ROOM_HPP

# include "Model.hpp"
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

class Room : public Model
{
public:
	Room(std::string const & meshName, std::string const & textureName);
	Room(Room const & room);
	virtual ~Room(void);

	Room & operator=(Room const & room);

	bool isValidated(void) const;
	bool isFailed(void) const;
	void update(float frametime);

	virtual void checkPlayer(Player const & player, float frametime);

protected:
	void addTimer(float frametime);
	float getTimer(void) const;
	void setIsValidated(bool isValidated);
	void setIsFailed(bool failed);

private:
	float		m_timer;
	bool		m_isValidated;
	bool		m_isFailed;

};

#endif
