/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:55:53 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/02 19:39:09 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("no_name"), _hitPoints(10), _energyPoints(10), _attakDemage(0)
{
	std::cout << "ClapTrap default constructor called fot " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attakDemage(0)
{
	std::cout << "ClapTrap parameterized constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attakDemage = other._attakDemage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target
			<< ", causing " << _attakDemage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " cannot repair itself. Not enough energy or health!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0 && _hitPoints >= int(amount))
	{
		_hitPoints -= amount; //TODO
		std::cout << "ClapTrap "<< _name << " takes " << amount << " damage. " << _hitPoints << " hit points left!" << std::endl;
	}
	else
		std::cout << "ClapTrap" << _name << " takes " << amount << " damage and is destroyed!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 1)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repaired it self for " << amount << " hit points. " << _hitPoints << " hit points total!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " cannot repair itself. Not enough energy or health!" << std::endl;
}
