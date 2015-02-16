#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include <string>
# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion(void);
	RadScorpion(RadScorpion const & p_RadScorpion);
	virtual ~RadScorpion(void);

	RadScorpion &	operator=(RadScorpion const & p_RadScorpion);

	void takeDamage(int p_nDamage);

};

#endif /* !RADSCORPION_HPP */

