#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy
{
private:
	int				m_nHp;
	std::string		m_sType;

protected:
	Enemy(void);

public:
	Enemy(int p_nHp, std::string const & p_sType);
	Enemy(Enemy const & p_Enemy);
	virtual ~Enemy(void);

	Enemy &	operator=(Enemy const & p_Enemy);

	std::string const & getType(void) const;
	int getHp(void) const;

	virtual void takeDamage(int p_nDamage);

};

#endif /* !ENEMY_HPP */

