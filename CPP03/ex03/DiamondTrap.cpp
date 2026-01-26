/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:40:24 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/26 16:06:32 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap("Diamond_clap_name"), FragTrap(), ScavTrap(), _name("Default")
{
	_hitPoints = FragTrap::_initialHitPoints;
	_energyPoints = ScavTrap::_initialEnergyPoints;
	_attackDamage = FragTrap::_initialAttackDamage;
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
: ClapTrap(copy), FragTrap(copy), ScavTrap(copy), _name(copy._name)
{
	*this = copy;
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"),
FragTrap(),
ScavTrap(),
_name(name)
{
	_hitPoints = FragTrap::_initialHitPoints;
	// std::cout << "Hit Points: (should be 100) "<< _hitPoints << std::endl;
	_energyPoints = ScavTrap::_initialEnergyPoints;
	// std::cout << "Energy Points: (should be 50) "<< _energyPoints << std::endl;
	_attackDamage = FragTrap::_initialAttackDamage;
	// std::cout << "Attack Damage: (should be 30) "<< _attackDamage << std::endl;
	std::cout << "DiamondTrap name constructor called." << std::endl;
}
void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
	std::cout << "My DiamondTrap name is " << _name << std::endl;
}