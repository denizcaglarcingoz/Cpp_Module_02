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
		Fixed() : fixRawValue(0){std::cout << "Default constructor is called." << std::endl;};

		Fixed (const Fixed& other)
		{
			std::cout << "Copy constructor is called." << std::endl;
			fixRawValue = other.getRawBits();
		}
		Fixed& operator=(const Fixed &other)
		{
			std::cout << "Copy assignment operator is called." << std::endl;
			if (this != &other)
			{
				this->fixRawValue = other.getRawBits(); 
			}
			return *this;
		}

		~Fixed()
		{
			std::cout << "Destructorr is called." << std::endl;
		}

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};


#endif