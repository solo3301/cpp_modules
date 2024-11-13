/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:41 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/13 22:37:34 by yadereve         ###   ########.fr       */
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
	Contact *contact = PhoneBook::contacts;
	int index = -1;
	std::string input;

	std::cout	<< GRN << std::setw(10) << "Index" << NC << "|"
				<< GRN << std::setw(10) << "First name" << NC << "|"
				<< GRN << std::setw(10) << "Last name" << NC << "|"
				<< GRN << std::setw(10) << "Nick name" << NC << std::endl;
	for (int i = 0; i < MAX_CONTACT; i++) {
		contact[i].ShowSearch(i);
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	std::istringstream(input) >> index;
	if (index > 0 && index <= MAX_CONTACT)
		contact[index - 1].Show();
	else
		std::cout << "--- Invalid index ---" << std::endl;
	}
