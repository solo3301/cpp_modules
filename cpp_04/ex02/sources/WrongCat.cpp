/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:15:10 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/04 12:40:41 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
		type = "WrongCat";
		std::cout << RED << "WrongCat default constructor called" << NC << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << RED << "WrongCat copy constructor called" << NC << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << RED << "WrongCat copy assignment operator called" << NC << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat destructor called" << NC << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << RED << "Meow, meow!" << NC << std::endl;
}
