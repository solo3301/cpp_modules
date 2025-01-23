/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:00:00 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/23 17:40:10 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

int main()
{
	Data* data = new Data;
	data->_name = "John";
	data->_age = 42;

	std::cout << "Original data:" << std::endl;
	std::cout << "name: " << data->_name << std::endl;
	std::cout << "age: " << data->_age << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << "Serialize: " << raw << std::endl;
	Data* deserializeData = Serializer::deserialize(raw);

	std::cout << "Deserialize data:" << std::endl;
	std::cout << "name: " << deserializeData->_name << std::endl;
	std::cout << "age: " << deserializeData->_age << std::endl;

	delete data;
	return 0;
}
