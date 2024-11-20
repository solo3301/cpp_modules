/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:41 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/18 19:34:52 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

# define NC "\x1b[0m"
# define RED "\x1b[91m"
# define GRN "\x1b[92m"
# define YEL "\x1b[93m"
# define BLU "\x1b[94m"

# define MAX_CONTACT 8
class PhoneBook
{
private:
	Contact contacts[MAX_CONTACT];
public:
	void AddContact();
	void SearchContact();
};

# endif
