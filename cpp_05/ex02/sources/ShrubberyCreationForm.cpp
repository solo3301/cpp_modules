/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:04:08 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/21 18:54:59 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{ }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{ }

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
		throw FormNotSignetExeption();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();

	std::ofstream file((_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "       _-_\n"
                "    /~~   ~~\\\n"
                " /~~         ~~\\\n"
                "{               }\n"
                " \\  _-     -_  /\n"
                "   ~  \\\\ //  ~\n"
                "       | |\n"
                "       | |\n";
		file.close();
	}
	else
		std::cerr << "Failed to open file for writing." << std::endl;
}
