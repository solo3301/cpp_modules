/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:23:27 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/01 16:35:10 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}


/* int main() {
	Fixed a(10);
	Fixed b(42.42f);
	Fixed c;

	c = a + b;
	std::cout << "a + b = " << c << std::endl;

	c = b - a;
	std::cout << "b - a = " << c << std::endl;

	c = a * b;
	std::cout << "a * b = " << c << std::endl;

	c = b / a;
	std::cout << "b / a = " << c << std::endl;

	std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;
	std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	Fixed d = a++;
	std::cout << "a++ = " << d << ", a = " << a << std::endl;
	d = ++a;
	std::cout << "++a = " << d << ", a = " << a << std::endl;

	Fixed e = b--;
	std::cout << "b-- = " << e << ", b = " << b << std::endl;
	e = --b;
	std::cout << "--b = " << e << ", b = " << b << std::endl;
	return 0;
} */
