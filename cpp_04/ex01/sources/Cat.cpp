/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:15:02 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/05 19:59:45 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain)
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
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << GREEN << "Meow!" << NC << std::endl;
}

void Cat::setIdea(int index, std::string &idea)
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index)
{
	return brain->getIdea(index);
}
