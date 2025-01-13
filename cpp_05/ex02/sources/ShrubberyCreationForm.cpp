/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:04:08 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/10 20:19:36 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{ }

ShrubberyCreationForm::~ShrubberyCreationForm()
{ }

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw FormNotSignetExeption();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();

	std::ofstream file(_target + "_shrubbery");
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
