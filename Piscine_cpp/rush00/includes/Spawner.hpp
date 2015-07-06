#ifndef SPAWNER_HPP
# define SPAWNER_HPP

class GameManager;

class Spawner
{
private:
	GameManager *		mp_gameManager;
	int					mn_maxScreenX;
	int					mn_maxScreenY;

	Spawner(void);
	Spawner(Spawner const & p_spawner);
	Spawner &	operator=(Spawner const & p_spawner);
public:
	Spawner(GameManager * pp_gameManager);
	virtual ~Spawner(void);

	void			update(float pf_deltatime);
};

#endif /* !SPAWNER_HPP */

