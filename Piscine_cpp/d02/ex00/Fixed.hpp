#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int m_nFixedPointValue;
	int const m_nFractionalBit;

public:
	Fixed(void);
	Fixed(Fixed const & p_Fixed);
	~Fixed(void);

	Fixed &	operator=(Fixed const & p_Fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const p_nRaw);

};

#endif /* !FIXED_HPP */

