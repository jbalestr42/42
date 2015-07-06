#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
private:
	std::string m_Type;
	std::string m_Name;

public:
	Zombie(std::string p_Name);
	~Zombie(void);

	void annonce(void) const;
	void setType(std::string p_Type);

};

#endif /* !ZOMBIE_HPP */
