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
	Fixed	operator+(Fixed const & p_Fixed) const;
	Fixed	operator-(Fixed const & p_Fixed) const;
	Fixed	operator*(Fixed const & p_Fixed) const;
	Fixed	operator/(Fixed const & p_Fixed) const;
	bool	operator<(Fixed const & p_Fixed) const;
	bool	operator>(Fixed const & p_Fixed) const;
	bool	operator<=(Fixed const & p_Fixed) const;
	bool	operator>=(Fixed const & p_Fixed) const;
	bool	operator==(Fixed const & p_Fixed) const;
	bool	operator!=(Fixed const & p_Fixed) const;
	Fixed &	operator++(void);
	Fixed	operator++(int);
	Fixed &	operator--(void);
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const p_nRaw);
	void	setRawBits(float const p_fRaw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed &			min(Fixed & p_Fixed1, Fixed & p_Fixed2);
	static Fixed const &	min(Fixed const & p_Fixed1, Fixed const & p_Fixed2);
	static Fixed &			max(Fixed & p_Fixed1, Fixed & p_Fixed2);
	static Fixed const &	max(Fixed const & p_Fixed1, Fixed const & p_Fixed2);
};

std::ostream & operator<<(std::ostream & o, Fixed const & p_Fixed);

#endif /* !FIXED_HPP */

