/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:53:14 by yadereve          #+#    #+#             */
/*   Updated: 2025/02/03 13:59:33 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Functions.hpp"

int main()
{
	Base* obj = generate();
	std::cout << "\n<< Identifying by pointer >>" << std::endl;
	identify(obj);
	std::cout << "\n<< Identifying by reference >>" << std::endl;
	identify(*obj);

	delete obj;
	return 0;
}
