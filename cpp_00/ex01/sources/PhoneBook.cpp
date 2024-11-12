/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:41 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/12 19:42:21 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

void PhoneBook::AddContact() {
	static int i = 0;

	contacts[i].AddDate();
	if (i < MAX_CONTACT - 1)
		i++;
	else
		i = 0;
}

void PhoneBook::SearchContact() {
	Contact *cont;
	std::string index;

	cont = PhoneBook::contacts;
	std::cout << YEL << "     Index" << NC << "|"
			<< YEL << "First name" << NC << "|"
			<< YEL << " Last name" << NC << "|"
			<< YEL << " Nick name" << NC << std::endl;
	for (int i = 0; i < MAX_CONTACT; i++) {
		cont[i].ShowSearch(i);
		(i < MAX_CONTACT) ? : i = 0;
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, index);
	if (index.length() > 0)
		cont[std::stoi(index)].Show();

}

