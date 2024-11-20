/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:07:35 by yadereve          #+#    #+#             */
/*   Updated: 2024/11/19 13:29:50 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

# define NC "\x1b[0m"
# define RED "\x1b[91m"
# define GRN "\x1b[92m"
# define YEL "\x1b[93m"
# define BLU "\x1b[94m"

class Zombie
{
private:
	std::string name;
public:
	Zombie (const std::string& name);
	~Zombie();
	void announce() const;
};

Zombie*	newZombie(const std::string& name);
void	randomChump(const std::string& name);

#endif
