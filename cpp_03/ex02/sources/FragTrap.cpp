#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << BLUE << "FragTrap default constructor called for " << _name << NC << std::endl;

}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << BLUE << "FragTrap parameterised constructor called for " << _name << NC << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << BLUE << "FragTrap copy constructor called for " << _name << NC << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << BLUE << "FragTrap copy assignment operator called for " << _name << NC << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << BLUE << "FragTrap destructor called for " << _name << NC << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << BLUE << "FragTrap " << _name << " requests a high five! 🙌" << NC << std::endl;
}
