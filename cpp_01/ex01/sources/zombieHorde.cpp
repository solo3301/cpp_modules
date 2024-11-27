/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:21:20 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/27 11:38:47 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(const int num, const std::string& name)
{
	if (num <= 0)
		return NULL;

	Zombie* horde = new Zombie[num];

	for (int i = 0; i < num; i++)
		horde[i].setName(name);
	return horde;
}
