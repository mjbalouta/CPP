/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:25:27 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/08 14:14:25 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
	
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << RED << name << " has been destroyed..." << RESET << std::endl;
}

void Zombie::announce(void)
{
	std::cout << PURPLE << name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}