#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << BLUE << "Brain default constructor called" << NC << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Default idea";
}

Brain::Brain(const Brain &other)
{
	std::cout << BLUE << "Brain copy constructor called" << NC << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << BLUE << "Brain copy assignment operator called" << NC << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << BLUE << "Brain destructor called" << NC << std::endl;
}

void Brain::setIdea(int index, std::string &idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}
