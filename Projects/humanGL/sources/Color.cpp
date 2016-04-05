#include "Color.hpp"

const Color Color::Black(0, 0, 0);
const Color Color::White(1.f, 1.f, 1.f);
const Color Color::Red(1.f, 0, 0);
const Color Color::Green(0, 1.f, 0);
const Color Color::Blue(0, 0, 1.f);
const Color Color::Yellow(1.f, 1.f, 0);
const Color Color::Magenta(1.f, 0, 1.f);
const Color Color::Cyan(0, 1.f, 1.f);

Color::Color(void) :
	Color(0.f, 0.f, 0.f, 1.f)
{}

Color::Color(float red, float green, float blue, float alpha) :
	r(red),
	g(green),
	b(blue),
	a(alpha)
{}

Color::Color(Color const & color)
{
	*this = color;
}

Color::~Color(void) { }

Color & Color::operator=(Color const & color)
{
	r = color.r;
	g = color.g;
	b = color.b;
	a = color.a;
	return (*this);
}
