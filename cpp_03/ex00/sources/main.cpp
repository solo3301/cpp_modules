/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:56:05 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/02 16:07:22 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
	ClapTrap ben("Ben");
	ClapTrap steav("Steav");
	ClapTrap bob;

	bob = ben;
	ben.attack("a target");
	ben.takeDamage(5);
	ben.beRepaired(3);
	ben.takeDamage(10);
	ben.beRepaired(5);

	steav.attack("another target");
	steav.takeDamage(12);
	bob.takeDamage(1);
	return 0;
}
