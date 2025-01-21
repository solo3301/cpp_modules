/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:05:32 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/21 18:54:00 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm()
	: _name("Unnamed"), _signGrade(150), _executeGrade(150), _isSigned(false)
{ }

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();

}

AForm::AForm(const AForm& other)
	: _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade), _isSigned(other._isSigned)
{ }

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{ }

const std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm: Grade is too low!";
}

const char* AForm::FormNotSignetExeption::what() const throw()
{
	return "AForm: Form not signet!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
	return os;
}
