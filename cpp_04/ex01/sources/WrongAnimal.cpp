/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:15:07 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/04 12:39:46 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << BLUE << "WrongAnimal default constructor called" << NC << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << BLUE << "WrongAnimal copy constructor called" << NC << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << BLUE << "WrongAnimal copy assignment operator called" << NC << std::endl;
	return *this;

}

WrongAnimal::~WrongAnimal()
{
	std::cout << BLUE << "WrongAnimal destructor called" << NC << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << BLUE << "WrongAnimal makes a generic sound" << NC << std::endl;
}
