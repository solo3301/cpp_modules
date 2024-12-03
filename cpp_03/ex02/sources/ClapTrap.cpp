/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:55:53 by yadereve          #+#    #+#             */
/*   Updated: 2024/12/03 16:49:26 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called fot " << _name << NC << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap parameterized constructor called for " << _name << NC << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap copy constructor called for " << _name << NC << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called for " << _name << NC << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << NC << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << NC << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << NC << " cannot repair itself. Not enough energy or health!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (amount >= _hitPoints)
		{
			_hitPoints = 0;
			std::cout << "ClapTrap" << _name << NC << " takes " << amount << " damage and is destroyed." << std::endl;
		}
		else
		{
			_hitPoints -= amount;
			std::cout << "ClapTrap" << _name << NC << " takes " << amount << " damage. " << _hitPoints << " hit points left!" << std::endl;
		}
	}
	else
		std::cout << "ClapTrap" << _name << NC << " takes " << amount << " damage and is destroyed!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << NC << " repaired it self for " << amount
				<< " hit points. " << _hitPoints << " hit points total!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << NC << " cannot repair itself. Not enough energy or health!" << std::endl;
}
