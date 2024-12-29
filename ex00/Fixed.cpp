#include "Fixed.hpp"


const int Fixed::fractionalBits = 8;

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function is called." << std::endl;
	return fixRawValue;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function is called." << std::endl;
	fixRawValue = raw;
}