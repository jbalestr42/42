#include "span.hpp"
#include <iostream>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

int randNumber(void)
{
	return (rand() % 10000);
}

int main()
{
	srand(std::time(0));
	try
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		Span big(10000);
		big.initAll(randNumber);
		std::cout << big.shortestSpan() << std::endl;
		std::cout << big.longestSpan() << std::endl;

		Span sp2(1);
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
