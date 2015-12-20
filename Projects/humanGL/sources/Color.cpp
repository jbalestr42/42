#include "Color.hpp"

const Color Color::Black(0, 0, 0);
const Color Color::White(255, 255, 255);
const Color Color::Red(255, 0, 0);
const Color Color::Green(0, 255, 0);
const Color Color::Blue(0, 0, 255);
const Color Color::Yellow(255, 255, 0);
const Color Color::Magenta(255, 0, 255);
const Color Color::Cyan(0, 255, 255);
const Color Color::Transparent(0, 0, 0, 0);

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
