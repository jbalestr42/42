#include <iostream>
#include "Fixed.hpp"

int main( void )
{

	Fixed const a( 23.396256512f );
	Fixed const b( 10.4242f );
	Fixed const n( 0 );
	Fixed const c( a + b );
	Fixed const d( a - b );
	Fixed const e( b - a );
	Fixed const f( a * b );
	Fixed const g( a / b );

	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << b << " - " << a << " = " << b - a << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;
	std::cout << b << " / " << a << " = " << b / a << std::endl;

	std::cout << n << " + " << a << " = " << n + a << std::endl;
	std::cout << n << " - " << a << " = " << n - a << std::endl;
	std::cout << n << " / " << a << " = " << n / a << std::endl;
	std::cout << a << " / " << n << " = " << a / n << std::endl;
	std::cout << n << " * " << a << " = " << n * a << std::endl;

	std::cout << std::boolalpha;
	std::cout << a << " == " << a << " -> " << (a == a) << std::endl;
	std::cout << a << " == " << b << " -> " << (a == b) << std::endl;
	std::cout << a << " != " << a << " -> " << (a != a) << std::endl;
	std::cout << a << " != " << b << " -> " << (a != b) << std::endl;
	std::cout << a << " < " << b << " -> " << (a < b) << std::endl;
	std::cout << a << " <= " << b << " -> " << (a <= b) << std::endl;
	std::cout << a << " <= " << a << " -> " << (a <= a) << std::endl;
	std::cout << a << " > " << b << " -> " << (a > b) << std::endl;
	std::cout << a << " >= " << b << " -> " << (a >= b) << std::endl;
	std::cout << a << " >= " << a << " -> " << (a >= a) << std::endl << std::endl;

	Fixed h;
	Fixed const i( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << h << std::endl;
	std::cout << ++h << std::endl;
	std::cout << h << std::endl;
	std::cout << h++ << std::endl;
	std::cout << h << std::endl;
	std::cout << i << std::endl << std::endl;

	std::cout << h << std::endl;
	std::cout << h++ << std::endl;
	std::cout << h++ << std::endl;
	std::cout << h++ << std::endl;
	std::cout << h++ << std::endl;
	std::cout << h << std::endl;
	h = 0;
	std::cout << h-- << std::endl;
	std::cout << h-- << std::endl;
	std::cout << h-- << std::endl;
	std::cout << h-- << std::endl;
	std::cout << h << std::endl;
	std::cout << "min(" << a << ", " << b << ") = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(" << a << ", " << b << ") = " << Fixed::max(a, b) << std::endl;

	return 0;
}
