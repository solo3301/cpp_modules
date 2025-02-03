/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:00:00 by yadereve          #+#    #+#             */
/*   Updated: 2025/02/03 13:02:40 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

int main()
{
	Data* data = new Data;
	data->_name = "John";
	data->_age = 42;

	std::cout << "<< Original data >>" << std::endl;
	std::cout << "\tname: " << data->_name << std::endl;
	std::cout << "\tage: " << data->_age << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << "\nSerialize: " << raw << std::endl;
	
	Data* deserializeData = Serializer::deserialize(raw);

	std::cout << "\n<< Deserialize data >>" << std::endl;
	std::cout << "\tname: " << deserializeData->_name << std::endl;
	std::cout << "\tage: " << deserializeData->_age << std::endl;

	delete data;
	return 0;
}
