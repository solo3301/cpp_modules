#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	const static int fractionalBits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed& operator = (const Fixed& other);
	
	Fixed(const int intValue);
	Fixed(const float floatValue);

	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

#endif
