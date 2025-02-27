/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:15:02 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/04 12:38:38 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << GREEN << "Cat default constructor called" << NC << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << GREEN << "Cat copy constructor called" << NC << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << GREEN << "Cat copy assignment operator called" << NC << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << GREEN << "Cat destructor called" << NC << std::endl;
}

void Cat::makeSound() const
{
	std::cout << GREEN << "Meow!" << NC << std::endl;
}
