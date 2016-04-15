#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
	:m_nFixedPointValue(0),
	m_nFractionalBit(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const p_nValue)
	:m_nFractionalBit(8)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(p_nValue);
}

Fixed::Fixed(float const p_fValue)
	:m_nFractionalBit(8)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(p_fValue);
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

std::ostream & operator<<(std::ostream & o, Fixed const & p_Fixed)
{
	o << p_Fixed.toFloat();
	return (o);
}

int Fixed::getRawBits(void) const
{
	return (this->m_nFixedPointValue);
}

void Fixed::setRawBits(int const p_nRaw)
{
	this->m_nFixedPointValue = p_nRaw << this->m_nFractionalBit;
}

void Fixed::setRawBits(float const p_fRaw)
{
	float fTmp = p_fRaw;
	for (int i = 0; i < this->m_nFractionalBit; i++)
		fTmp *= 2;
	this->m_nFixedPointValue = roundf(fTmp);
}

float Fixed::toFloat(void) const
{
	float fValue = this->m_nFixedPointValue;
	for (int i = 0; i < this->m_nFractionalBit; i++)
		fValue /= 2.f;
	return (fValue);
}

int Fixed::toInt(void) const
{
	return (this->m_nFixedPointValue >> this->m_nFractionalBit);
}
