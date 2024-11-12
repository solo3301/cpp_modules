/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:41 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/12 19:29:55 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact() : firstName(), lastName(), nickName(), phoneNumber(), darkestSecret() {}
	void AddDate();
	void ShowSearch(int index);
	void ValidateStr(std::string msg, std::string &param);
	void Show();
};

#endif
