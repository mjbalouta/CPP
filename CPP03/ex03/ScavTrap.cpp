/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:22:28 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/22 15:00:58 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) 
{
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap destructor called." << std::endl;	
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	if (_hitPoints > 0 && _energyPoints > 0)
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name <<  " atacks " << target 
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;	
	}
}