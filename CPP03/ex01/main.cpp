/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:18:44 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/22 15:23:45 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap Maria("Maria");
	ScavTrap Bolota("Bolota");
	
	std::cout << std::endl;
	Maria.attack("Joao");
	Maria.takeDamage(2);
	Maria.beRepaired(1);
	
	std::cout << std::endl;
	std::cout << "Maria only has 8 points of energy left, so she can only attack 8 times more!" << std::endl; 
	for (int i = 0; i < 200; i++)
		Maria.attack("Joao");
	
	std::cout << std::endl;
	Maria.takeDamage(10);
	Maria.attack("Joao"); // will not be visible because Maria has no more hitPoints left
	
	std::cout << std::endl;
	Bolota.attack("Joao");
	Bolota.guardGate();
	Bolota.takeDamage(2);
	Bolota.beRepaired(1);

	std::cout << std::endl;
	std::cout << "Bolota only has 48 points of energy left, so she can only attack 48 times more!" << std::endl; 
	for (int i = 0; i < 400; i++)
		Bolota.attack("Joao");
}