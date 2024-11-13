/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:41 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/13 22:19:57 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

static void GetValidatedInput(const std::string msg, std::string &param, bool digitalOnly = false) {
	std::string str;

	while (str.empty()) {
		if (!msg.empty())
			std::cout << msg;
		std::getline(std::cin, str);
		if (digitalOnly) {
			bool isNumeric = true;
			for (std::string::size_type i = 0; i < str.length(); i++) {
				if (!isdigit(str[i])) {
					isNumeric = false;
					break;
				}
			}
			if (!isNumeric) {
				std::cout << "Invalid input! Please enter only digits.\n";
				str.clear();
			}
		}
	}
	param = str;
}

void Contact::AddDate() {
	GetValidatedInput("Enter First name: ", firstName);
	GetValidatedInput("Enter Last name: ", lastName);
	GetValidatedInput("Enter Nick name: ", nickName);
	GetValidatedInput("Enter Phone number: ", phoneNumber, true);
	GetValidatedInput("Enter Darkest secret: ", darkestSecret);
}

static void PrintFormatted(const std::string &str) {
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void Contact::ShowSearch(int index) {
	PrintFormatted(std::to_string(index + 1));
	std::cout << "|";
	PrintFormatted(firstName);
	std::cout << "|";
	PrintFormatted(lastName);
	std::cout << "|";
	PrintFormatted(nickName);
	std::cout << std::endl;
}

void Contact::Show() {
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nick name: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
