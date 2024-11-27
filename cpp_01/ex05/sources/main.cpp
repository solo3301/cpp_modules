/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:23:47 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/27 08:20:40 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main()
{
	Harl harl;
	std::cout << "Testing DEBUG:" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "Testing INFO:" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	std::cout << "Testing WARNING:" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << "Testing ERROR:" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	std::cout << "Testing UNKNOWN:" << std::endl;
	harl.complain("");
	return 0;
}
