#ifndef IANIMATORBASE_HPP
# define IANIMATORBASE_HPP

class Transformable;

class IAnimatorBase
{
public:
	virtual IAnimatorBase * clone(void) const = 0;
	virtual float getTimerEnd(void) const = 0;

	virtual void restart(void) = 0;
	virtual void update(float animationTimer, float frameTime, Transformable & transformable) = 0;

};

#endif
