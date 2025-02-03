/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:53:06 by yadereve          #+#    #+#             */
/*   Updated: 2025/02/03 13:16:11 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Functions.hpp"

Base* generate()
{
	std::srand(std::time(NULL));
	int randValue = std::rand() % 4;
	switch (randValue)
	{
		case 0:
			std::cout << "Generate type A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generate type B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generate type C" << std::endl;
			return new C();
	};
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Type: Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
	}
	catch (std::exception& e)
	{ }

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
	}
	catch (std::exception& e)
	{ }

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
	}
	catch (std::exception& e)
	{ }
}
