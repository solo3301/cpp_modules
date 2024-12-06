/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:23:58 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/06 08:14:44 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal* animal1 = new Dog();
	const Animal* animal2 = new Cat();

	// Animal animal;
	std::cout << std::endl;
	animal1->makeSound();
	animal2->makeSound();
	std::cout << std::endl;
	delete animal1;
	delete animal2;
	return 0;
}
