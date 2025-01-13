#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
public:
	Form(const std::string& name, int signGrade, int executeGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool getIsSigned() const;
	void beSignet(Bureaucrat& b);
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

private:
	const std::string _name;
	const int _signGrade;
	const int _executeGrade;
	bool _isSigned;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
