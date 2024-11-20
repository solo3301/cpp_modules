/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:04:22 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/20 11:16:28 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main()
{
	int num = 10;
	Zombie* horde = zombieHorde(num, "HordeZombie");

	for (int i = 0; i < num; i++)
		horde[i].announce();
	delete[] horde;

	return 0;
}
