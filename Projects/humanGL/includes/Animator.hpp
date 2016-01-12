#ifndef ANIMATOR_HPP
# define ANIMATOR_HPP

# include "IAnimatorBase.hpp"
# include "Math.hpp"
# include "Transformable.hpp"
# include <cassert>
# include <memory>
# include <type_traits>

enum class Anim : std::int8_t
{
	RotateX = 0,
	RotateY = 1,
	RotateZ = 2,
	Origin = 3,
	Translate = 4,
	Scale = 5,
	Rotate = 6,
	SetScale = 7
};

template <Anim A>
class Animator : public IAnimatorBase
{
protected:
	typedef typename std::conditional<(int)A <= 2, float, Vector3>::type T;
	enum class AnimStyle : std::int8_t
	{
		ComputeOnce,
		Additive,
		Lerp
	};

public:
	Animator(void) :
		Animator(T(), T(), 0.f, 0.f)
	{}

	// Set the desire value at a fixed time until the end of the animation
	Animator(T const & value, float timerStart) :
		m_value(value),
		m_computedValue(value),
		m_timerStart(timerStart),
		m_timerEnd(0.f),
		m_duration(0.f),
		m_needToCompute(false),
		m_computeOnce(true),
		m_animStyle(AnimStyle::ComputeOnce)
	{
		assert(timerStart >= 0.f);
	}

	// Set a value to be added at the current value from start to start + duration
	Animator(T const & value, float timerStart, float duration) :
		m_value(value),
		m_computedValue(T()),
		m_timerStart(timerStart),
		m_timerEnd(timerStart + duration),
		m_duration(duration),
		m_needToCompute(false),
		m_computeOnce(false),
		m_animStyle(AnimStyle::Additive)
	{
		assert(timerStart >= 0.f);
	}

	Animator(Animator<A> const & animator)
	{
		*this = animator;
	}

	virtual ~Animator(void) = default;

	Animator & operator=(Animator<A> const & animator)
	{
		m_value = animator.m_value;
		m_computedValue = animator.m_computedValue;
		m_timerStart = animator.m_timerStart;
		m_timerEnd = animator.m_timerEnd;
		m_duration = animator.m_duration;
		m_needToCompute = animator.m_needToCompute;
		m_computeOnce = animator.m_computeOnce;
		m_animStyle = animator.m_animStyle;
		return (*this);
	}

	void update(float animationTimer, float frameTime)
	{
		m_needToCompute = false;
		switch (m_animStyle)
		{
			case AnimStyle::ComputeOnce:
				if (m_computeOnce)
				{
					m_computedValue = m_value;
					m_needToCompute = true;
					m_computeOnce = false;
				}
				break;
			case AnimStyle::Additive:
				if (animationTimer > m_timerStart && animationTimer <= m_timerEnd)
				{
					m_computedValue = m_value * frameTime;
					m_needToCompute = true;
				}
				break;
			default:
				break;
		}
	}

	float getTimerStart(void) const
	{
		return (m_timerStart);
	}

	float getTimerEnd(void) const
	{
		return (m_timerEnd);
	}

	float getDuration(void) const
	{
		return (m_duration);
	}

	virtual IAnimatorBase * clone(void) const
	{
		return new Animator(*this);
	}

	virtual void animate(Transformable & transformable)
	{
		(void)transformable;
	}

private:
	T			m_value;
	T			m_computedValue;
	float		m_timerStart;
	float		m_timerEnd;
	float		m_duration;
	bool		m_needToCompute;
	bool		m_computeOnce;
	AnimStyle	m_animStyle;

};

template<>
void Animator<Anim::Origin>::animate(Transformable & transformable)
{
	if (m_needToCompute)
		transformable.setOrigin(m_computedValue);
}

template<>
void Animator<Anim::Translate>::animate(Transformable & transformable)
{
	if (m_needToCompute)
		transformable.translate(m_computedValue);
}

template<>
void Animator<Anim::Rotate>::animate(Transformable & transformable)
{
	if (m_needToCompute)
		transformable.rotate(m_computedValue);
}

template<>
void Animator<Anim::RotateX>::animate(Transformable & transformable)
{
	if (m_needToCompute)
		transformable.rotateX(m_computedValue);
}

template<>
void Animator<Anim::RotateY>::animate(Transformable & transformable)
{
	if (m_needToCompute)
		transformable.rotateY(m_computedValue);
}

template<>
void Animator<Anim::RotateZ>::animate(Transformable & transformable)
{
	if (m_needToCompute)
		transformable.rotateZ(m_computedValue);
}

template<>
void Animator<Anim::Scale>::animate(Transformable & transformable)
{
	if (m_needToCompute)
		transformable.scale(m_computedValue);
}

template<>
void Animator<Anim::SetScale>::animate(Transformable & transformable)
{
	if (m_needToCompute)
		transformable.setScale(m_computedValue);
}

template <Anim A>
class SetAnimator : public Animator<A>
{
	typedef typename Animator<A>::T T;

public:
	SetAnimator(T const & value, float timerStart) :
		Animator<A>(value, timerStart)
	{
		assert(timerStart >= 0.f);
	}

	~SetAnimator(void) = default;
	virtual void animate(Transformable & transformable)
	{
		(void)transformable;
	}
};

#endif
