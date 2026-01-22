/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:40:18 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/22 14:38:31 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
	std::string _name;

	public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& copy);
	DiamondTrap& operator=(const DiamondTrap& copy);
	~DiamondTrap();

	DiamondTrap(std::string name);
	void attack(const std::string& target);
	void whoAmI();
};

#endif