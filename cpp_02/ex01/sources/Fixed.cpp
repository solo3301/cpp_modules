/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:46:27 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/30 12:28:58 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	value = static_cast <int>(roundf(floatValue * (1 << fractionalBits)));
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast <float>(value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed &other)
{
	os << other.toFloat();
	return os;
}
