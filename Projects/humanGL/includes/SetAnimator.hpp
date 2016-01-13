#ifndef SETANIMATOR_HPP
# define SETANIMATOR_HPP

# include "AAnimator.hpp"

template <Anim A>
class SetAnimator : public AAnimator<A>
{
	typedef typename AAnimator<A>::T T;

public:
	SetAnimator(void) = delete;

	SetAnimator(T const & value, float timerStart, float duration = 0.f) :
		AAnimator<A>(value, timerStart, duration),
		m_recompute(true)
	{}

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
		m_recompute = setAnimator.m_recompute;
		return (*this);
	}

	SetAnimator & operator=(SetAnimator && setAnimator)
	{
		AAnimator<A>::operator=(std::move(setAnimator));
		m_recompute = std::move(setAnimator.m_recompute);
		return (*this);
	}

	virtual void update(float animationTimer, float, Transformable & transformable)
	{
		if (animationTimer > AAnimator<A>::getTimerStart() && m_recompute)
		{
			m_recompute = false;
			animate(transformable);
		}
	}

	virtual IAnimatorBase * clone(void) const
	{
		return new SetAnimator(*this);
	}

	virtual void animate(Transformable & transformable);

	virtual void restart(void)
	{
		m_recompute = true;
	}

private:
	bool	m_recompute;

};

template<>
void SetAnimator<Anim::Origin>::animate(Transformable & transformable)
{
	transformable.setOrigin(getValue());
}

template<>
void SetAnimator<Anim::Translate>::animate(Transformable & transformable)
{
	transformable.setPosition(getValue());
}

template<>
void SetAnimator<Anim::Rotate>::animate(Transformable & transformable)
{
	transformable.setRotation(getValue());
}

template<>
void SetAnimator<Anim::RotateX>::animate(Transformable & transformable)
{
	transformable.setRotation(Vector3(getValue(), 0.f, 0.f));
}

template<>
void SetAnimator<Anim::RotateY>::animate(Transformable & transformable)
{
	transformable.setRotation(Vector3(0.f, getValue(), 0.f));
}

template<>
void SetAnimator<Anim::RotateZ>::animate(Transformable & transformable)
{
	transformable.setRotation(Vector3(0.f, 0.f, getValue()));
}

template<>
void SetAnimator<Anim::Scale>::animate(Transformable & transformable)
{
	transformable.setScale(getValue());
}

#endif
