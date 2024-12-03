/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:56:05 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/03 15:53:56 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main()
{
	ScavTrap sca1("Bob");
	ScavTrap sca2;

	sca1.guardGate();
	sca1.attack("a target");
	sca1.takeDamage(140);
	sca1.beRepaired(41);

	std::cout << "\nsca1:" << std::endl;
	sca1.showTrap();

	std::cout << "\nsca2:" << std::endl;
	sca2.showTrap();

	sca2 = sca1;
	std::cout << "\nsca2:" << std::endl;
	sca2.showTrap();
	
	ScavTrap sca3 = sca2;
	std::cout << "\nsca3:" << std::endl;
	sca3.showTrap();
	return 0;
}
