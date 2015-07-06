#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
	:m_nFixedPointValue(0),
	m_nFractionalBit(8)
{
}

Fixed::Fixed(int const p_nValue)
	:m_nFractionalBit(8)
{
	this->setRawBits(p_nValue);
}

Fixed::Fixed(float const p_fValue)
	:m_nFractionalBit(8)
{
	this->setRawBits(p_fValue);
}

Fixed::Fixed(Fixed const & p_Fixed)
	:m_nFractionalBit(8)
{
	*this = p_Fixed;
}

Fixed::~Fixed(void)
{
}

Fixed & Fixed::operator=(Fixed const & p_Fixed)
{
	this->m_nFixedPointValue = p_Fixed.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(Fixed const & p_Fixed) const
{
	Fixed f;
	f.m_nFixedPointValue = this->getRawBits() + p_Fixed.getRawBits();
	return (f);
}

Fixed Fixed::operator-(Fixed const & p_Fixed) const
{
	Fixed f;
	f.m_nFixedPointValue = this->getRawBits() - p_Fixed.getRawBits();
	return (f);
}

Fixed Fixed::operator*(Fixed const & p_Fixed) const
{
	Fixed f;
	f.m_nFixedPointValue = (this->getRawBits() * p_Fixed.getRawBits()) >> this->m_nFractionalBit;
	return (f);
}

Fixed Fixed::operator/(Fixed const & p_Fixed) const
{
	Fixed f;
	if (p_Fixed.getRawBits() == 0)
	{
		f.m_nFixedPointValue = 2147483647;
	}
	else
		f.m_nFixedPointValue = (this->getRawBits() << this->m_nFractionalBit) / p_Fixed.getRawBits();
	return (f);
}

std::ostream & operator<<(std::ostream & o, Fixed const & p_Fixed)
{
	o << p_Fixed.toFloat();
	return (o);
}

bool Fixed::operator<(Fixed const & p_Fixed) const
{
	return (this->m_nFixedPointValue < p_Fixed.m_nFixedPointValue);
}

bool Fixed::operator>(Fixed const & p_Fixed) const
{
	return (this->m_nFixedPointValue > p_Fixed.m_nFixedPointValue);
}

bool Fixed::operator<=(Fixed const & p_Fixed) const
{
	return (this->m_nFixedPointValue <= p_Fixed.m_nFixedPointValue);
}

bool Fixed::operator>=(Fixed const & p_Fixed) const
{
	return (this->m_nFixedPointValue >= p_Fixed.m_nFixedPointValue);
}

bool Fixed::operator==(Fixed const & p_Fixed) const
{
	return (this->m_nFixedPointValue == p_Fixed.m_nFixedPointValue);
}

bool Fixed::operator!=(Fixed const & p_Fixed) const
{
	return (this->m_nFixedPointValue != p_Fixed.m_nFixedPointValue);
}

Fixed & Fixed::operator++(void)
{
	this->m_nFixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy = (*this);
	this->m_nFixedPointValue++;
	return (copy);
}

Fixed & Fixed::operator--(void)
{
	this->m_nFixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed copy = (*this);
	this->m_nFixedPointValue--;
	return (copy);
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

Fixed & Fixed::min(Fixed & p_Fixed1, Fixed & p_Fixed2)
{
	return (p_Fixed1 < p_Fixed2 ? p_Fixed1 : p_Fixed2);
}

Fixed const & Fixed::min(Fixed const & p_Fixed1, Fixed const & p_Fixed2)
{
	return (p_Fixed1 < p_Fixed2 ? p_Fixed1 : p_Fixed2);
}

Fixed & Fixed::max(Fixed & p_Fixed1, Fixed & p_Fixed2)
{
	return (p_Fixed1 > p_Fixed2 ? p_Fixed1 : p_Fixed2);
}

Fixed const & Fixed::max(Fixed const & p_Fixed1, Fixed const & p_Fixed2)
{
	return (p_Fixed1 > p_Fixed2 ? p_Fixed1 : p_Fixed2);
}

