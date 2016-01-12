#ifndef ADDANIMATOR_HPP
# define ADDANIMATOR_HPP

# include "AAnimator.hpp"
# include <cassert>

template<Anim A>
class AddAnimator : public AAnimator<A>
{
	typedef typename AAnimator<A>::T T;

public:
	AddAnimator(void) = delete;

	AddAnimator(T const & value, float timerStart, float duration) :
		AAnimator<A>(value),
		m_computedValue(T()),
		m_timerStart(timerStart),
		m_timerEnd(timerStart + duration),
		m_duration(duration),
		m_animate(false)
	{
		assert(timerStart >= 0.f);
	}

	AddAnimator(AddAnimator const & addAnimator) :
		AAnimator<A>(addAnimator)
	{
		*this = addAnimator;
	}

	AddAnimator(AddAnimator && addAnimator) :
		AAnimator<A>(std::move(addAnimator))
	{
		*this = std::move(addAnimator);
	}

	virtual ~AddAnimator(void) = default;

	AddAnimator & operator=(AddAnimator const & addAnimator)
	{
		AAnimator<A>::operator=(addAnimator);
		m_computedValue = addAnimator.m_computedValue;
		m_timerStart = addAnimator.m_timerStart;
		m_timerEnd = addAnimator.m_timerEnd;
		m_duration = addAnimator.m_duration;
		m_animate = addAnimator.m_animate;
		return (*this);
	}

	AddAnimator & operator=(AddAnimator && addAnimator)
	{
		AAnimator<A>::operator=(std::move(addAnimator));
		m_computedValue = std::move(addAnimator.m_computedValue);
		m_timerStart = std::move(addAnimator.m_timerStart);
		m_timerEnd = std::move(addAnimator.m_timerEnd);
		m_duration = std::move(addAnimator.m_duration);
		m_animate = std::move(addAnimator.m_animate);
		return (*this);
	}

	virtual void update(float animationTimer, float frameTime)
	{
		m_animate = false;
		if (animationTimer > m_timerStart && animationTimer <= m_timerEnd)
		{
			m_computedValue = AAnimator<A>::getValue() * frameTime;
			m_animate = true;
		}
	}

	virtual IAnimatorBase * clone(void) const
	{
		return new AddAnimator(*this);
	}

	virtual void animate(Transformable & transformable);

	virtual float getTimerEnd(void) const
	{
		return (m_timerEnd);
	}

	float getTimerStart(void) const
	{
		return (m_timerStart);
	}

	float getDuration(void) const
	{
		return (m_duration);
	}

private:
	T		m_computedValue;
	float	m_timerStart;
	float	m_timerEnd;
	float	m_duration;
	bool	m_animate;

};

template<>
void AddAnimator<Anim::Origin>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.setOrigin(transformable.getOrigin() + m_computedValue);
}

template<>
void AddAnimator<Anim::Translate>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.translate(m_computedValue);
}

template<>
void AddAnimator<Anim::Rotate>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.rotate(m_computedValue);
}

template<>
void AddAnimator<Anim::RotateX>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.rotateX(m_computedValue);
}

template<>
void AddAnimator<Anim::RotateY>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.rotateY(m_computedValue);
}

template<>
void AddAnimator<Anim::RotateZ>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.rotateZ(m_computedValue);
}

template<>
void AddAnimator<Anim::Scale>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.scale(m_computedValue);
}


#endif
