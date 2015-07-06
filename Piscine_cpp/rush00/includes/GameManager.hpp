#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP

# include "GameEntity.hpp"
# include "Player.hpp"
# include "Bullet.hpp"
# include "Enemy.hpp"
# include "Spawner.hpp"
# include "Decor.hpp"
# include "Bonus.hpp"

# define KEY_ESCAPE	27
# define KEY_SPACE	32

# define MAX_BULLET	100
# define MAX_ENEMY	10
# define MAX_DECOR	1
# define MAX_BONUS	1

class GameManager
{
private:
	GameManager(GameManager const & p_gameManager);
	GameManager &	operator=(GameManager const & p_gameManager);

	Player *	mp_player;
	Spawner *	mp_spawner;
	int			mb_exit;
	Bullet *	mp_bullets[MAX_BULLET];
	int			mn_nbBullet;
	Enemy *		mp_enemies[MAX_ENEMY];
	int			mn_nbEnemy;
	Decor *		mp_decors[MAX_DECOR];
	int			mn_nbDecor;
	Bonus *		mp_bonus[MAX_BONUS];
	int			mn_nbBonus;
	float		mf_globalTime;
	int			mn_score;
	int			mn_lastScore;

public:
	GameManager(void);
	virtual ~GameManager(void);

	void			getInput(void);
	void			update(float pf_deltatime);
	void			display(void);
	void			runGame(void);
	void			reset(void);

	void			addBullet(Bullet * pp_bullet);
	void			addEnemy(Enemy * pp_enemy);
	void			addDecor(Decor * pp_decor);
	void			addBonus(Bonus * pp_bonus);
	int				getNbEnemy(void) const;
	int				getNbDecor(void) const;
	int				getNbBonus(void) const;
	float			getGlobalTime(void);
	int				getScore(void) const;
	int				getLastScore(void) const;
	void			addScore(int pn_score);
};

#endif /* !GAMEMANAGER_HPP */

