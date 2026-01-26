/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:21:39 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/26 15:50:28 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
	static const int _initialEnergyPoints = 50;
	ScavTrap();
	ScavTrap(const ScavTrap& copy);
	ScavTrap& operator=(const ScavTrap& copy);
	~ScavTrap();
	
	ScavTrap(std::string name);
	void guardGate();
	void attack(const std::string& target);
};

#endif