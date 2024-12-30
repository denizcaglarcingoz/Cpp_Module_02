#include "Fixed.hpp"
#include <cstdlib>
#include <stdexcept>


const int Fixed::fractionalBits = 8;

Fixed::Fixed(const int inToRawConvert)
{
	fixRawValue = inToRawConvert*256;
}


Fixed::Fixed(const float floatToRawConver)
{
	fixRawValue = (int)(floatToRawConver * 256 + 0.5f);
}

Fixed::Fixed(const int rawValueDirect, bool raw)
{
	if (raw)
		fixRawValue = rawValueDirect;
}

Fixed::Fixed(const Fixed&other)
{
	fixRawValue = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->fixRawValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
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

Fixed	Fixed::operator+(const Fixed& other) const
{
	return Fixed((this->fixRawValue + other.fixRawValue), true);
}
	
Fixed	Fixed::operator-(const Fixed& other) const
{
	return Fixed((this->fixRawValue - other.fixRawValue), true);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return Fixed((this->fixRawValue * other.fixRawValue) / 256, true);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	try
	{
		if (other.fixRawValue == 0)
			throw std::runtime_error("Can't divide by 0. It is a crash");
		return Fixed(((this->fixRawValue) / other.fixRawValue) * 256, true);
	} catch(const std::runtime_error& err)
	{
		std::cerr << "Caught an error" << err.what() << std::endl;
		std::terminate();
	}
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (this->fixRawValue < other.fixRawValue)
		return (true);
	
	return (false);
}

bool	Fixed::operator>(const Fixed& other) const
{
	if (this->fixRawValue > other.fixRawValue)
		return (true);
	
	return (false);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	if (this->fixRawValue >= other.fixRawValue)
		return (true);
	
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	if (this->fixRawValue <= other.fixRawValue)
		return (true);
	
	return (false);
}

bool	Fixed::operator==(const Fixed& other) const
{
	if (this->fixRawValue == other.fixRawValue)
		return (true);
	
	return (false);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	if (this->fixRawValue != other.fixRawValue)
		return (true);
	
	return (false);
}

Fixed&	Fixed::operator++()
{
	++(this->fixRawValue);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp;
	temp = *this;
	++(this->fixRawValue);
	return temp;
}

Fixed&	Fixed::operator--()
{
	--(this->fixRawValue);
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp;
	temp = *this;
	--(this->fixRawValue);
	return temp;
}


Fixed&		Fixed::min(Fixed& first, Fixed& second)
{
	if (first < second)
			return first;
	return second;
}

Fixed&		Fixed::max(Fixed& first, Fixed& second)
{
	if (first > second)
			return first;
	return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first > second)
			return first;
	return second;
}