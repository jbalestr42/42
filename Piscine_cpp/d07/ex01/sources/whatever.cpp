#include <iostream>

template<typename T>
void print(T & t)
{
	std::cout << t << std::endl;
}

// template argument deduced
template<>
void print(int & i)
{
	std::cout << "int " << i << std::endl;
}

// template argument explicitly specified
template<>
void print<char>(char & i)
{
	std::cout << "char " << i << std::endl;
}

template<typename T>
void iter(T * t, int p_length, void (*f)(T &))
{
	for (int i = 0; i < p_length; i++)
	{
		f(t[i]);
	}
}

int main(void)
{
	int iarray[5] = { 1, 6, 45, 12, 32 };
	iter(iarray, 5, print);

	std::cout << std::endl;

	std::string sarray[5] = { "Pe", "Ju", "Bra", "Fran", "Gui" };
	iter(sarray, 5, print);

	std::cout << std::endl;

	char carray[5] = { 'f', 'y', 'g', 'n', 'j' };
	iter(carray, 5, print);
	return (0);
}
