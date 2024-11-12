/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:41 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/12 19:38:36 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

void Contact::ValidateStr(std::string msg, std::string &param) {
	std::string str;

	while (!str[0]) {
		if (msg.length() > 0)
			std::cout << msg;
		std::getline(std::cin, str);
		if (msg == "Enter Phone number: ") {
			for (std::string::size_type i = 0; i < str.length(); i++) {
				if (!isdigit(str[i])) {
					str.clear();
					break;
				}
			}
		}
	}
	param = str;
}

void Contact::AddDate() {
	ValidateStr("Enter First name: ", firstName);
	ValidateStr("Enter Last name: ", lastName);
	ValidateStr("Enter Nick name: ", nickName);
	ValidateStr("Enter Phone number: ", phoneNumber);
	ValidateStr("Enter Darkest secret: ", darkestSecret);
}

static void PrintFormatted(const std::string str) {
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void Contact::ShowSearch(int index) {
	PrintFormatted(std::to_string(index));
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
