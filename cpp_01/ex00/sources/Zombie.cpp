/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:23:52 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/27 11:36:55 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name) {}

Zombie::~Zombie()
{
	std::cout << name << RED << " is destroyed." << NC << std::endl;
}

void Zombie::announce() const
{
	std::cout << BLU << name << NC << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
