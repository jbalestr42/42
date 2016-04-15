#ifndef MODEL_HPP
# define MODEL_HPP

# define MAX_HEIGHT	70
# include <string>

class GameEntity;

class Model
{
private:
	std::string		mp_shape[MAX_HEIGHT];
	int				mn_nbFrame;
	int				mn_currentFrame;
	int				mn_sizeFrame;
	float			mf_timer;
	GameEntity *	mp_owner;

	Model(void);
	Model(Model const & p_model);
	Model &	operator=(Model const & p_model);

public:
	virtual ~Model(void);
	Model(std::string pp_shape[MAX_HEIGHT], GameEntity * pp_owner);
	Model(std::string pp_shape[MAX_HEIGHT], int pn_nbFrame, int pn_sizeFrame, GameEntity * pp_owner);

	void			update(float pf_deltatime);
	void			display(int pn_x, int pn_y);
	bool			collision(GameEntity const & p_gameEntity);

};

#endif /* !MODEL_HPP */

