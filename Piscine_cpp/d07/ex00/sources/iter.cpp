#include <iostream>
#include <iomanip>

class Type
{
public:
	double		d;

	Type(void) : d(0) {}
	Type(double p_d) : d(p_d) { }
	~Type(void) {}

	Type &operator=(Type const & p_type)
	{
		d = p_type.d;
		return (*this);
	}

	bool operator>(Type const & p_type) const
	{
		return (d > p_type.d ? true : false);
	}
};

std::ostream & operator<<(std::ostream & o, Type const & p_type)
{
	o << p_type.d;
	return o;
}

template<typename T>
T const & min(T const & x, T const & y)
{
	return (x > y ? y : x);
}

template<typename T>
T const & max(T const & x, T const & y)
{
	return (x > y ? x : y);
}

template<typename T>
void swap(T & x, T & y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

int main(void)
{
	std::cout << setiosflags(std::ios::fixed);
	std::cout.precision(2);
	int a = 12, b = 13;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "max(" << a << ", " << b << ") = " << ::max(a, b) << std::endl;
	std::cout << "min(" << a << ", " << b << ") = " << ::min(a, b) << std::endl;
	std::cout << "swap(" << a << ", " << b << ")" << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;

	float c = 13.2f, d = 13.1f;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "max(" << c << ", " << d << ") = " << max<float>(c, d) << std::endl;
	std::cout << "min(" << c << ", " << d << ") = " << min<float>(c, d) << std::endl;
	swap<float>(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;

	Type e(43.2), f(43.6);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "max(" << e << ", " << f << ") = " << max<Type>(e, f) << std::endl;
	std::cout << "min(" << e << ", " << f << ") = " << min<Type>(e, f) << std::endl;
	swap<Type>(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl << std::endl;

	std::string g = "g", h = "h";
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "max(" << g << ", " << h << ") = " << ::max(g, h) << std::endl;
	std::cout << "min(" << g << ", " << h << ") = " << ::min(g, h) << std::endl;
	::swap(g, h);
	std::cout << "g = " << g << ", h = " << h << std::endl << std::endl;
	return (0);
}
