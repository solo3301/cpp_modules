#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(const std::string& name, int signGrade, int executeGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool getIsSigned() const;
	void beSigned(const Bureaucrat& b);
	virtual void execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class FormNotSignetExeption : public std::exception
	{
		public:
			const char* what() const throw();
	};

private:
	const std::string _name;
	const int _signGrade;
	const int _executeGrade;
	bool _isSigned;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
