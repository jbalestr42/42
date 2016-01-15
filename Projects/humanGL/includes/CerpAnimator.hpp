#ifndef CERPANIMATOR_HPP
# define CERPANIMATOR_HPP

# include "LerpAnimator.hpp"

template<Anim A>
class CerpAnimator : public LerpAnimator<A>
{
	typedef typename AAnimator<A>::T T;

public:
	CerpAnimator(T const & startValue, T const & endValue, float timerStart, float duration) :
		LerpAnimator<A>(startValue, endValue, timerStart, duration)
	{}

	virtual void update(float animationTimer, float, Transformable & transformable)
	{
		if (animationTimer > AAnimator<A>::getTimerStart() && animationTimer <= AAnimator<A>::getTimerEnd())
		{
			AAnimator<A>::setValue(cerp(LerpAnimator<A>::getStartValue(), LerpAnimator<A>::getEndValue(), (animationTimer - AAnimator<A>::getTimerStart()) / AAnimator<A>::getDuration()));
			LerpAnimator<A>::animate(transformable);
		}
	}

	virtual IAnimatorBase * clone(void) const
	{
		return new CerpAnimator(*this);
	}

};

#endif
