#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
	:m_nFixedPointValue(0),
	m_nFractionalBit(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & p_Fixed)
	:m_nFractionalBit(8)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = p_Fixed;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

}

Fixed & Fixed::operator=(Fixed const & p_Fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->m_nFixedPointValue = p_Fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->m_nFixedPointValue);
}

void Fixed::setRawBits(int const p_nRaw)
{
	this->m_nFixedPointValue = p_nRaw;
}
