#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "../includes/Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string target);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat & executor) const;

private:
	const std::string _target;
};

#endif
