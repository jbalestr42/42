#ifndef AANIMATOR_HPP
# define AANIMATOR_HPP

# include "IAnimatorBase.hpp"
# include "Transformable.hpp"
# include <memory>
# include <type_traits>
# include <functional>
# include <cassert>

enum class Anim : std::int8_t
{
	RotateX = 0,
	RotateY = 1,
	RotateZ = 2,
	Origin = 3,
	Translate = 4,
	Scale = 5,
	Rotate = 6
};

template <Anim A>
class AAnimator : public IAnimatorBase
{
protected:
	typedef typename std::conditional<(int)A <= 2, float, Vector3>::type T;

public:
	AAnimator(void) = delete;

	AAnimator(T const & value, float timerStart, float duration) :
		m_value(value),
		m_timerStart(timerStart),
		m_timerEnd(timerStart + duration),
		m_duration(duration)
	{
		assert(timerStart >= 0.f);
		assert(duration >= 0.f);
	}

	AAnimator(AAnimator const & animator)
	{
		*this = animator;
	}

	AAnimator(AAnimator && animator)
	{
		*this = std::move(animator);
	}

	virtual ~AAnimator(void) = default;

	AAnimator & operator=(AAnimator const & animator)
	{
		m_value = animator.m_value;
		m_timerStart = animator.m_timerStart;
		m_timerEnd = animator.m_timerEnd;
		m_duration = animator.m_duration;
		return (*this);
	}

	AAnimator & operator=(AAnimator && animator)
	{
		m_value = std::move(animator.m_value);
		m_timerStart = std::move(animator.m_timerStart);
		m_timerEnd = std::move(animator.m_timerEnd);
		m_duration = std::move(animator.m_duration);
		return (*this);
	}

	virtual float getTimerStart(void) const
	{
		return (m_timerStart);
	}

	virtual float getTimerEnd(void) const
	{
		return (m_timerEnd);
	}

	virtual float getDuration(void) const
	{
		return (m_duration);
	}

	virtual void restart(void)
	{}

protected:
	T const & getValue(void) const
	{
		return (m_value);
	}

	void setValue(T const & value)
	{
		m_value = value;
	}

private:
	T		m_value;
	float	m_timerStart;
	float	m_timerEnd;
	float	m_duration;

};

#endif
