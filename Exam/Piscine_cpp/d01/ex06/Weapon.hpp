#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
private:
	std::string m_Type;

public:
	Weapon(void);
	Weapon(std::string p_Type);
	~Weapon(void);

	std::string const &getType(void) const;
	void setType(std::string p_Type);

};

#endif /* !WEAPON_HPP */
