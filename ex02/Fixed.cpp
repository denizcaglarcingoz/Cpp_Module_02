#include "Fixed.hpp"


const int Fixed::fractionalBits = 8;

Fixed::Fixed(const int RawIntToConvert)
{
	std::cout << "Int constructor called" << std::endl;
	fixRawValue = RawIntToConvert*256;
}


Fixed::Fixed(const float RawFlotToConvert)
{
	std::cout << "Float constructor called" << std::endl;
	fixRawValue = (int)(RawFlotToConvert * 256 + 0.5f);
}

int	Fixed::getRawBits(void) const
{
	return fixRawValue;
}

void	Fixed::setRawBits(int const raw)
{
	fixRawValue = raw;
}


int	Fixed::toInt(void)const
{
	return (fixRawValue / 256);
}


float	Fixed::toFloat(void)const
{
	float returnVal;

	returnVal = fixRawValue;
	returnVal = returnVal / 256;
	return returnVal;
}

std::ostream	&operator<<(std::ostream &os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}