/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:05:32 by yadereve          #+#    #+#             */
/*   Updated: 2025/01/17 21:47:09 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() 
	: _name("Unnamed"), _signGrade(1), _executeGrade(1), _isSigned(false)
{ }

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();

}

Form::Form(const Form& other)
	: _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade), _isSigned(other._isSigned)
{ }

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{ }

const std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
	return os;
}
