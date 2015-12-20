#ifndef ANIMATOR_HPP
# define ANIMATOR_HPP

# include "IAnimatorBase.hpp"
# include "Math.hpp"
# include <cassert>
# include <memory>
# include <type_traits>

class Matrix;
enum class Anim : std::int8_t
{
	Translate = 0,
	Scale = 1,
	Rotate = 2,
	RotateX = 3,
	RotateY = 4,
	RotateZ = 5
};

template <Anim A>
class Animator : public IAnimatorBase
{
	typedef typename std::conditional<(int)A <= 2, Vector3, float>::type T;
public:
	Animator(void) :
		Animator(T(), T(), 0.f, 0.f)
	{}

	Animator(T const & value, float timerStart, float duration) :
		m_start(T()),
		m_end(T()),
		m_value(value),
		m_computedValue(T()),
		m_timerStart(timerStart),
		m_timerEnd(timerStart + duration),
		m_duration(duration),
		m_needToCompute(false),
		m_useLerp(false),
		m_computeOnce(duration < 0.f ? true : false)
	{
		assert(timerStart >= 0.f);
	}

	Animator(T const & start, T const & end, float timerStart, float timerEnd) :
		m_start(start),
		m_end(end),
		m_value(T()),
		m_computedValue(T()),
		m_timerStart(timerStart),
		m_timerEnd(timerEnd),
		m_duration(timerEnd - timerStart),
		m_needToCompute(false),
		m_useLerp(true)
	{
		assert(timerEnd >= 0.f);
		assert(timerStart >= 0.f);
		assert(timerEnd >= timerStart);
	}

	Animator(Animator<A> const & aAnimator)
	{
		*this = aAnimator;
	}

	virtual ~Animator(void) = default;

	Animator & operator=(Animator<A> const & aAnimator)
	{
		m_start = aAnimator.m_start;
		m_end = aAnimator.m_end;
		m_value = aAnimator.m_value;
		m_timerStart = aAnimator.m_timerStart;
		m_timerEnd = aAnimator.m_timerEnd;
		m_duration = aAnimator.m_duration;
		m_needToCompute = aAnimator.m_needToCompute;
		return (*this);
	}

	void update(float animationTimer, float frameTime)
	{
		// check si on garde la position final, si on recommence, ou si on remet à zéro
		if (m_computeOnce)
		{
			m_computedValue = m_value;
			m_needToCompute = true;
			m_computeOnce = false;
		}
		else if (animationTimer > m_timerStart && animationTimer <= m_timerEnd)
		{
			if (m_useLerp)
			{
				float t = (animationTimer - m_timerStart) / m_duration;
				m_computedValue = lerp(m_start, m_end, (t > 1.f ? 1.f : t));
			}
			else
			{
				m_computedValue = m_value * frameTime;
			}
			m_needToCompute = true;
		}
		else
			m_needToCompute = false;
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

	virtual Matrix const & getMatrix(void)
	{
		return m_matrix;
	}

	virtual IAnimatorBase * clone(void) const
	{
		return new Animator(*this);
	}

private:
	T		m_start;
	T		m_end;
	T		m_value;
	T		m_computedValue;
	float	m_timerStart;
	float	m_timerEnd;
	float	m_duration;
	bool	m_needToCompute;
	bool	m_useLerp;
	bool	m_computeOnce;
	Matrix	m_matrix;

};

template<>
Matrix const & Animator<Anim::Translate>::getMatrix(void)
{
	if (m_needToCompute)
		m_matrix.translate(m_computedValue);
	return m_matrix;
}

template<>
Matrix const & Animator<Anim::Scale>::getMatrix(void)
{
	if (m_needToCompute)
		m_matrix.scale(m_computedValue);
	return m_matrix;
}

template<>
Matrix const & Animator<Anim::Rotate>::getMatrix(void)
{
	if (m_needToCompute)
		m_matrix.rotate(m_computedValue);
	return m_matrix;
}

template<>
Matrix const & Animator<Anim::RotateX>::getMatrix(void)
{
	if (m_needToCompute)
		m_matrix.rotateX(m_computedValue);
	return m_matrix;
}

template<>
Matrix const & Animator<Anim::RotateY>::getMatrix(void)
{
	if (m_needToCompute)
		m_matrix.rotateY(m_computedValue);
	return m_matrix;
}

template<>
Matrix const & Animator<Anim::RotateZ>::getMatrix(void)
{
	if (m_needToCompute)
		m_matrix.rotateZ(m_computedValue);
	return m_matrix;
}

#endif
