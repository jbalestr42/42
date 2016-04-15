#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include <string>
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant(void);
	SuperMutant(SuperMutant const & p_SuperMutant);
	virtual ~SuperMutant(void);

	SuperMutant &	operator=(SuperMutant const & p_SuperMutant);

	void takeDamage(int p_nDamage);

};

#endif /* !SUPERMUTANT_HPP */

