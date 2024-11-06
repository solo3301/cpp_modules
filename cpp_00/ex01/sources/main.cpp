/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:41 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/06 07:46:28 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int main() {
	while (true) {
		std::string line;
		std::cout << BLU << "Commands: ADD, SEARCH, EXIT" << NC << std::endl;
		std::getline(std::cin, line);
		if (line == "EXIT") {
			std::cout << RED << "exit" << NC << std::endl;
			break;
		}
		else if (line == "ADD") {
			// AddContact();
		}
		else if (line == "SEARCH") {
			// SearchContact();
		}
		else {
			std::cout << "Only EXIT, ADD, SEARCH" << std::endl;
		}
	}
	return 0;
}
