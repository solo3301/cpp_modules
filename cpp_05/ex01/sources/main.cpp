/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:15:22 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/09 11:29:28 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice", 50);
		Form formA("FormA", 45, 30);
		Form formB("FormB", 60, 50);

		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

		alice.signForm(formA);
		alice.signForm(formB);

		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std:: endl;
	}

	return 0;
}
