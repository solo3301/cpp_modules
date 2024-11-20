/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:23:52 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/19 19:47:30 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name) {}

Zombie::~Zombie()
{
	std::cout << name << RED << " is destroyed." << NC << std::endl;
}

void Zombie::announce() const
{
	std::cout << BLU << name << NC << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
