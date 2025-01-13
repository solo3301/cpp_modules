#ifndef INTERN_HPP
#define INTERN_HPP

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string formName, const std::string& target);

private:
	static AForm* createRobotomyForm(const std::string& target);
	static AForm* createShrubberyForm(const std::string& target);
	static AForm* createPresidentialForm(const std::string& target);
};

#endif
