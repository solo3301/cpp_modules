#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attakDemage;


public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif

// Operador de atribuição de cópia = Copy assignment operator
