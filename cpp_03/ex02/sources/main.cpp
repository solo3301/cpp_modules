/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:56:05 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/03 16:58:53 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main()
{
	FragTrap jobs1("Jobs");
	FragTrap jobs2;

	jobs1.highFivesGuys();
	jobs1.attack("a target");
	jobs1.takeDamage(40);
	jobs1.beRepaired(50);

	jobs2 = jobs1;

	std::cout << "\nfrag2 state:" << std::endl;
	jobs2.attack("another target");

	FragTrap jobs3 = jobs2;
	std::cout << "\nfrag3 state:" << std::endl;
	jobs3.highFivesGuys();
	return 0;
}
