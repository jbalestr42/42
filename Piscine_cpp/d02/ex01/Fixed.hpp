#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int m_nFixedPointValue;
	int const m_nFractionalBit;

public:
	Fixed(void);
	Fixed(int const p_nValue);
	Fixed(float const p_fValue);
	Fixed(Fixed const & p_Fixed);
	~Fixed(void);

	Fixed &	operator=(Fixed const & p_Fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const p_nRaw);
	void	setRawBits(float const p_fRaw);
	float	toFloat(void) const;
	int		toInt(void) const;

};

std::ostream & operator<<(std::ostream & o, Fixed const & p_Fixed);

#endif /* !FIXED_HPP */

