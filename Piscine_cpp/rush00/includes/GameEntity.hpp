#ifndef GAMEENTITY_HPP
# define GAMEENTITY_HPP

# include "Model.hpp"

class GameManager;

class GameEntity
{
public:
	enum EType
	{
		e_Type_Player,
		e_Type_Enemy,
		e_Type_Bullet,
		e_Type_Decor,
		e_Type_Bonus,
		e_Type_nb
	};

private:
	static int		msn_nbGameEntity;

protected:
	GameManager	*	mp_gameManager;

	int const		mn_index;
	float			mf_x;
	float			mf_y;
	int				mn_maxHp;
	int				mn_hp;
	EType			me_type;
	Model*			mp_model;

	GameEntity(void);
public:
	// canonical
	GameEntity(GameManager * pp_gameManager, int pn_x, int pn_y, int pn_hp, EType pe_type);
	GameEntity(GameEntity const & p_gameEntity);
	virtual ~GameEntity(void);

	GameEntity &	operator=(GameEntity const & p_gameEntity);

	//
	virtual void	display(void); // screen
	virtual void	update(float pf_deltatime);
	virtual void	collision(GameEntity & p_gameEntity) = 0;
	bool			isDead(void) const;

	float			getX(void) const;
	float			getY(void) const;
	EType			getType(void) const;
	Model *			getModel(void) const;

	void			setHp(int pn_value);

};

#endif /* !GAMEENTITY_HPP */

