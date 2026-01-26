/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:00:59 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/26 15:49:31 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
	static const int _initialHitPoints = 100;
	static const int _initialAttackDamage = 30;
	FragTrap();
	FragTrap(const FragTrap& copy);
	FragTrap& operator=(const FragTrap& copy);
	~FragTrap();

	FragTrap(std::string name);
	void highFivesGuys(void);
};

#endif