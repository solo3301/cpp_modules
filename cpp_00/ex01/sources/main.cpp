/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:41 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/12 19:08:55 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int main() {
	std::string command = "";
	PhoneBook phonebook = PhoneBook();

	std::cout << GRN
	<< "Write the following commands in uppercase: EXIT, ADD, SEARCH."
	<< NC << std::endl;
	while (true) {
		std::cout << BLU << "-> " << NC;
		std::getline(std::cin, command);
		if (command == "EXIT") {
			// std::cout << RED << "\t>>> exit <<<" << NC << std::endl;
			break;
		}
		else if (command == "ADD")
			phonebook.AddContact();
		else if (command == "SEARCH")
			phonebook.SearchContact();
		else
			std::cout << YEL "Only EXIT or ADD or SEARCH." NC << std::endl;
	}
	return 0;
}
