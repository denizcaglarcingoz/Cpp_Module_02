#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
	//FixedPointNumber(FPN)
class Fixed
{
	private:
		int					fixRawValue;
		const static int	fractionalBits;

	public:
		Fixed() : fixRawValue(0){};
		Fixed(const float floatToRawConver);
		Fixed(const int intToRawConver);
		Fixed(const int rawValueDirect, bool raw);

		Fixed		(const Fixed& other);
		Fixed&		operator=(const Fixed& other);

		~Fixed();

		int			getRawBits(void) const;
		void		setRawBits(int const raw);		
		
		int			toInt(void)const;
		float		toFloat(void)const;

		Fixed		operator+(const Fixed& other)const;
		Fixed		operator-(const Fixed& other)const;
		Fixed		operator*(const Fixed& other)const;
		Fixed		operator/(const Fixed& other)const;

		bool		operator<(const Fixed& other) const;
		bool		operator>(const Fixed& other) const;
		bool		operator>=(const Fixed& other) const;
		bool		operator<=(const Fixed& other) const;
		bool		operator==(const Fixed& other) const;
		bool		operator!=(const Fixed& other) const;

		Fixed&		operator++();
		Fixed		operator++(int);
		Fixed&		operator--();
		Fixed		operator--(int);

		static Fixed&		min(Fixed& first, Fixed& second);
		const static Fixed&	min(const Fixed& first, const Fixed& second);
		static Fixed&		max(Fixed& first, Fixed& second);
		const static Fixed&	max(const Fixed& first, const Fixed& second);

};


std::ostream&		operator<<(std::ostream &os, const Fixed& fixed);


#endif