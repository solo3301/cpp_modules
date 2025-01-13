#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();

	void execute(const Bureaucrat& executor) const;

private:
	const std::string _target;
};

#endif
