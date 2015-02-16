#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class GameManager;
class GameEntity;

class Weapon
{
protected:
	int				mn_damage;
	float const		mf_firerate; // Time between two shoot
	float			mf_timer;
	std::string		m_name;
	GameEntity *	mp_owner;

	Weapon(void);
	Weapon(Weapon const & p_weapon);
	Weapon &	operator=(Weapon const & p_weapon);

public:
	Weapon(int pn_damage, float pf_firerate, std::string p_name, GameEntity * pp_owner);
	virtual ~Weapon(void);

	std::string const & getName(void) const;

	void update(float pf_deltatime);
	virtual void attack(GameManager & p_gameManager) = 0;

	int			getDamage(void) const;
	GameEntity * getOwner(void) const;

};

#endif /* !WEAPON_HPP */
