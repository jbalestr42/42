#ifndef LERPANIMATOR_HPP
# define LERPANIMATOR_HPP

# include "AAnimator.hpp"
# include "Math.hpp"

template<Anim A>
class LerpAnimator : public AAnimator<A>
{
	typedef typename AAnimator<A>::T T;

public:
	LerpAnimator(void) = delete;

	LerpAnimator(T const & startValue, T const & endValue, float timerStart, float duration) :
		AAnimator<A>(T(), timerStart, duration),
		m_startValue(startValue),
		m_endValue(endValue)
	{}

	LerpAnimator(LerpAnimator const & addAnimator) :
		AAnimator<A>(addAnimator)
	{
		*this = addAnimator;
	}

	LerpAnimator(LerpAnimator && addAnimator) :
		AAnimator<A>(std::move(addAnimator))
	{
		*this = std::move(addAnimator);
	}

	virtual ~LerpAnimator(void) = default;

	LerpAnimator & operator=(LerpAnimator const & addAnimator)
	{
		AAnimator<A>::operator=(addAnimator);
		m_startValue = addAnimator.m_startValue;
		m_endValue = addAnimator.m_endValue;
		return (*this);
	}

	LerpAnimator & operator=(LerpAnimator && addAnimator)
	{
		AAnimator<A>::operator=(std::move(addAnimator));
		m_startValue = std::move(addAnimator.m_startValue);
		m_endValue = std::move(addAnimator.m_endValue);
		return (*this);
	}

	virtual void update(float animationTimer, float, Transformable & transformable)
	{
		if (animationTimer > AAnimator<A>::getTimerStart() && animationTimer <= AAnimator<A>::getTimerEnd())
		{
			AAnimator<A>::setValue(lerp(m_startValue, m_endValue, (animationTimer - AAnimator<A>::getTimerStart()) / AAnimator<A>::getDuration()));
			animate(transformable);
		}
	}

	virtual IAnimatorBase * clone(void) const
	{
		return new LerpAnimator(*this);
	}

	virtual void animate(Transformable & transformable);

protected:
	T const & getStartValue(void) const
	{
		return m_startValue;
	}

	T const & getEndValue(void) const
	{
		return m_endValue;
	}

private:
	T	m_startValue;
	T	m_endValue;

};

template<>
void LerpAnimator<Anim::Origin>::animate(Transformable & transformable)
{
	transformable.setOrigin(getValue());
}

template<>
void LerpAnimator<Anim::Translate>::animate(Transformable & transformable)
{
	transformable.setPosition(getValue());
}

template<>
void LerpAnimator<Anim::Rotate>::animate(Transformable & transformable)
{
	transformable.setRotation(getValue());
}

template<>
void LerpAnimator<Anim::RotateX>::animate(Transformable & transformable)
{
	transformable.setRotation(Vector3(getValue(), 0.f, 0.f));
}

template<>
void LerpAnimator<Anim::RotateY>::animate(Transformable & transformable)
{
	transformable.setRotation(Vector3(0.f, getValue(), 0.f));
}

template<>
void LerpAnimator<Anim::RotateZ>::animate(Transformable & transformable)
{
	transformable.setRotation(Vector3(0.f, 0.f, getValue()));
}

template<>
void LerpAnimator<Anim::Scale>::animate(Transformable & transformable)
{
	transformable.setScale(getValue());
}

#endif
