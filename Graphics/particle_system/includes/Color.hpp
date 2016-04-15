#ifndef COLOR_HPP
# define COLOR_HPP

class Color
{
public:
	Color(void);
	Color(float red, float greeb, float blue, float alpha = 1.f);
	Color(Color const & color);
	~Color(void);

	Color & operator=(Color const & color);

	static const Color Black;
	static const Color White;
	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Yellow;
	static const Color Magenta;
	static const Color Cyan;
	static const Color Transparent;

	float	r;
	float	g;
	float	b;
	float	a;

};

#endif
