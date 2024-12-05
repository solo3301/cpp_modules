/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:23:58 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/05 19:41:21 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	delete j;//should not create a leak
	delete i;
	return 0;
}

/* int main()
{
	const int animalCount = 4;
	Animal* animals[animalCount];

	// For Dog
	for (int i = 0; i < animalCount / 2; ++i)
		animals[i] = new Dog;
	// For CAT
	for (int i = animalCount / 2; i < animalCount; ++i)
		animals[i] = new Cat;

	std::cout << "\nTesting ideas: " << std::endl;

	// For Dog
	for (int i = 0; i < animalCount / 2; ++i)
	{
		std::string ideaDog = "I want to chase a cat!";
		dynamic_cast<Dog*>(animals[i])->setIdea(i, ideaDog);
		std::cout << "Dog's idea: " << dynamic_cast<Dog*>(animals[i])->getIdea(i) << std::endl;
	}

	// For CAT
	for (int i = animalCount / 2; i < animalCount; ++i)
	{
		std::string ideaCat = "I want to chase a mouse!";
		dynamic_cast<Cat*>(animals[i])->setIdea(i, ideaCat);
		std::cout << "Cat's idea: " << dynamic_cast<Cat*>(animals[i])->getIdea(i - animalCount / 2) << std::endl;
	}

	std::cout << "\nCleaning up:" << std::endl;
	for (int i = 0; i < animalCount; i++)
		delete animals[i];
	return 0;
} */

