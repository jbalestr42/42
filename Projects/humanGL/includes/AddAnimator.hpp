#ifndef ADDANIMATOR_HPP
# define ADDANIMATOR_HPP

# include "AAnimator.hpp"

template<Anim A>
class AddAnimator : public AAnimator<A>
{
	typedef typename AAnimator<A>::T T;

public:
	AddAnimator(void) = delete;

	AddAnimator(T const & value, float timerStart, float duration) :
		AAnimator<A>(value, timerStart, duration),
		m_startValue(value)
	{}

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
		m_startValue = addAnimator.m_startValue;
		return (*this);
	}

	AddAnimator & operator=(AddAnimator && addAnimator)
	{
		AAnimator<A>::operator=(std::move(addAnimator));
		m_startValue = std::move(addAnimator.m_startValue);
		return (*this);
	}

	virtual void update(float animationTimer, float frameTime, Transformable & transformable)
	{
		if (animationTimer > AAnimator<A>::getTimerStart() && animationTimer <= AAnimator<A>::getTimerEnd())
		{
			AAnimator<A>::setValue(m_startValue * frameTime);
			animate(transformable);
		}
	}

	virtual IAnimatorBase * clone(void) const
	{
		return new AddAnimator(*this);
	}

	virtual void animate(Transformable & transformable);

private:
	T	m_startValue;

};

template<>
void AddAnimator<Anim::Origin>::animate(Transformable & transformable)
{
	transformable.setOrigin(transformable.getOrigin() + getValue());
}

template<>
void AddAnimator<Anim::Translate>::animate(Transformable & transformable)
{
	transformable.translate(getValue());
}

template<>
void AddAnimator<Anim::Rotate>::animate(Transformable & transformable)
{
	transformable.rotate(getValue());
}

template<>
void AddAnimator<Anim::RotateX>::animate(Transformable & transformable)
{
	transformable.rotateX(getValue());
}

template<>
void AddAnimator<Anim::RotateY>::animate(Transformable & transformable)
{
	transformable.rotateY(getValue());
}

template<>
void AddAnimator<Anim::RotateZ>::animate(Transformable & transformable)
{
	transformable.rotateZ(getValue());
}

template<>
void AddAnimator<Anim::Scale>::animate(Transformable & transformable)
{
	transformable.scale(getValue());
}


#endif
