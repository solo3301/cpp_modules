/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:53:14 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/23 20:04:40 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Functions.hpp"

int main()
{
	Base* obj = generate();
	std::cout << "Identifying by pointer:" << std::endl;
	identify(obj);
	std::cout << "Identifying by reference:" << std::endl;
	identify(*obj);

	delete obj;
	return 0;
}
