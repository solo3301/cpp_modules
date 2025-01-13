/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:34:02 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/13 18:38:20 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{ }

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{ }

AForm* Intern::makeForm(const std::string formName, const std::string& target)
{
	std::string formTypes[3] = {
		"Shrubbery creation",
		"Robotomy request",
		"Presidential pardon"
	};

	AForm* (*formCreators[3])(const std::string&) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
        &Intern::createPresidentialForm
    };

	for (int i = 0; i < 3; i++)
	{
		if(formName == formTypes[i])
		{
			std::cout << "Intern created " << formName << std::endl;
			return formCreators[i](target);
		}
	}

	std::cout << "Intern couldn't find the form: " << std::endl;
	return NULL;
}

AForm* Intern::createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

