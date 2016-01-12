#ifndef AANIMATOR_HPP
# define AANIMATOR_HPP

# include "IAnimatorBase.hpp"
# include "Transformable.hpp"
# include <memory>
# include <type_traits>
# include <functional>

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

	AAnimator(T const & value) :
		m_value(value)
	{}

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
		return (*this);
	}

	AAnimator & operator=(AAnimator && animator)
	{
		m_value = std::move(animator.m_value);
		return (*this);
	}

	virtual void restart(void)
	{}

protected:
	T const & getValue(void) const
	{
		return m_value;
	}

	void setValue(T const & value)
	{
		m_value = value;
	}

private:
	T	m_value;

};

#endif
