/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:41 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/06 07:50:00 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include "Contact.hpp"

# define NC "\033[0m"
# define RED "\033[91m"
# define GRN "\033[92m"
# define YEL "\033[93m"
# define BLU "\033[94m"
# define MAG "\033[95m"
# define CYN "\033[96m"
# define WHT "\033[97m"

class PhoneBook {
private:

public:
	PhoneBook();
	~PhoneBook();
};

# endif
