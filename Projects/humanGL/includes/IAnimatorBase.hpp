#ifndef IANIMATORBASE_HPP
# define IANIMATORBASE_HPP

class Matrix;

class IAnimatorBase
{
public:
	virtual IAnimatorBase * clone(void) const = 0;
	virtual Matrix const & getMatrix(void) = 0;
	virtual float getDuration(void) const = 0;
	virtual float getTimerStart(void) const = 0;
	virtual float getTimerEnd(void) const = 0;

	virtual void update(float animationTimer, float frameTime) = 0;

};

#endif
