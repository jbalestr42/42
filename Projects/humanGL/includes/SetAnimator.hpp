#ifndef SETANIMATOR_HPP
# define SETANIMATOR_HPP

# include "AAnimator.hpp"
# include <cassert>

template <Anim A>
class SetAnimator : public AAnimator<A>
{
	typedef typename AAnimator<A>::T T;

public:
	SetAnimator(void) = delete;

	SetAnimator(T const & value, float timerStart) :
		AAnimator<A>(value),
		m_timerStart(timerStart),
		m_animate(false),
		m_recompute(true)
	{
		assert(timerStart >= 0.f);
	}

	SetAnimator(SetAnimator const & setAnimator) :
		AAnimator<A>(setAnimator)
	{
		*this = setAnimator;
	}

	SetAnimator(SetAnimator && setAnimator) :
		AAnimator<A>(std::move(setAnimator))
	{
		*this = std::move(setAnimator);
	}

	virtual ~SetAnimator(void) = default;

	SetAnimator & operator=(SetAnimator const & setAnimator)
	{
		AAnimator<A>::operator=(setAnimator);
		m_timerStart = setAnimator.m_timerStart;
		m_animate = setAnimator.m_animate;
		m_recompute = setAnimator.m_recompute;
		return (*this);
	}

	SetAnimator & operator=(SetAnimator && setAnimator)
	{
		AAnimator<A>::operator=(std::move(setAnimator));
		m_timerStart = std::move(setAnimator.m_timerStart);
		m_animate = std::move(setAnimator.m_animate);
		m_recompute = std::move(setAnimator.m_recompute);
		return (*this);
	}

	virtual void update(float animationTimer, float)
	{
		m_animate = false;
		if (animationTimer > m_timerStart && m_recompute)
		{
			m_recompute = false;
			m_animate = true;
		}
	}

	virtual IAnimatorBase * clone(void) const
	{
		return new SetAnimator(*this);
	}

	virtual void animate(Transformable & transformable);

	virtual float getTimerEnd(void) const
	{
		return (m_timerStart);
	}

	virtual void restart(void)
	{
		m_recompute = true;
	}

private:
	float	m_timerStart;
	bool	m_animate;
	bool	m_recompute;

};

template<>
void SetAnimator<Anim::Origin>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.setOrigin(getValue());
}

template<>
void SetAnimator<Anim::Translate>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.setPosition(getValue());
}

template<>
void SetAnimator<Anim::Rotate>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.setRotation(getValue());
}

template<>
void SetAnimator<Anim::RotateX>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.setRotation(Vector3(getValue(), 0.f, 0.f));
}

template<>
void SetAnimator<Anim::RotateY>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.setRotation(Vector3(0.f, getValue(), 0.f));
}

template<>
void SetAnimator<Anim::RotateZ>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.setRotation(Vector3(0.f, 0.f, getValue()));
}

template<>
void SetAnimator<Anim::Scale>::animate(Transformable & transformable)
{
	if (m_animate)
		transformable.setScale(getValue());
}

#endif
