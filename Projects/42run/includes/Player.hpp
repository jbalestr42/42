#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Transformable.hpp"
# include "Mesh.hpp"
# include "AnimatedTexture.hpp"
# include <memory>

class Player : public Transformable
{
public:
	enum State
	{
		Walk,
		Jump,
		Fall
	};

	Player(void);
	Player(Player const & player);
	virtual ~Player(void);

	Player & operator=(Player const & player);

	void setSpeedFactor(float speedFactor);

	void update(float frametime);
	void draw(Shader & shader);

private:
	std::unique_ptr<Mesh>				m_mesh;
	std::unique_ptr<AnimatedTexture>	m_texture;
	float								m_speed;
	float								m_speedMax;
	float								m_jumpTimerMax;
	float								m_jumpFactor;
	State								m_state;

};

#endif
