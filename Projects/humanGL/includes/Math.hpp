#ifndef MATH_HPP
# define MATH_HPP

# include <cmath>

static constexpr float const	Pi = 3.14159265358979323846f;
static constexpr float const	PiDiv2 = Pi / 2.f;
static constexpr float const	PiDiv4 = Pi / 4.f;
static constexpr float const	Pi2 = Pi * 2.f;
static constexpr float const	Pi4 = Pi * 4.f;
static constexpr float const	Deg2Rad = Pi / 180.f;
static constexpr float const	Rad2Deg = 180.f / Pi;

template<class T>
T lerp(T v1, T v2, float t)
{
	return (v1 * (1.f - t) + v2 * t);
}

template<class T>
T cerp(T v1, T v2, float t)
{
	return (lerp(v1, v2, 0.5f - (std::cos(t * Pi) / 2.f)));
}

#endif
