#include "Fixed.hpp"

#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	a = 10;
	std::cout << std::endl << "a: " << a << " b: " << b << std::endl;
	std::cout << std::endl << "a * b " << a*b << std::endl;
	std::cout << "a + b: " << a+b << std::endl;
	std::cout << "a - b: " << a-b << std::endl;
	std::cout << "a / b: " << a/b << std::endl;

	std::cout << std::endl;
	if (a < b)
		std::cout << "a is smaller than b" << std::endl;
	if (a != b)
		std::cout << "a is not equal to b" << std::endl;
	if (a >= b)
		std::cout << "a is equal or bigger than b" << std::endl;

	return 0;
}