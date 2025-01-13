/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:15:22 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/13 18:47:34 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"

int main()
{
	try
	{
		Intern intern;
		Bureaucrat bob("Bob", 45);
		Bureaucrat president("President", 1);

		AForm* shrubbery = intern.makeForm("Shrubbery creation", "Home");
		AForm* robotomy = intern.makeForm("Robotomy request", "Target");
		AForm* pardon = intern.makeForm("Presidential pardon", "Alice");
		AForm* unknown = intern.makeForm("unknown form", "Unknown");

		if (shrubbery != NULL)
		{
			bob.signForm(*shrubbery);
			bob.executeForm(*shrubbery);
			delete shrubbery;
		}
		if (robotomy != NULL)
		{
			bob.signForm(*robotomy);
			bob.executeForm(*robotomy);
			delete robotomy;
		}
		if (pardon != NULL)
		{
			president.signForm(*pardon);
			president.executeForm(*pardon);
			delete pardon;
		}
		if (unknown != NULL)
		{
			delete unknown;
		}
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}
