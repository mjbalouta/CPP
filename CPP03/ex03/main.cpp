/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:18:44 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/26 16:09:34 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap Maria("Maria");
	ScavTrap Bolota("Bolota");
	FragTrap Fraga("Fraga");
	
	std::cout << std::endl << "---------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl << RED << "Maria's fight history: "<< std::endl;
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
	
	std::cout << RESET << "----------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl << PURPLE << "Bolota's fight history: " << std::endl;
	Bolota.attack("Joao");
	Bolota.guardGate();
	Bolota.takeDamage(2);
	Bolota.beRepaired(1);

	std::cout << std::endl;
	std::cout << "Bolota only has 48 points of energy left, so she can only attack 48 times more!" << std::endl; 
	for (int i = 0; i < 200; i++)
		Bolota.attack("Joao");

	std::cout << std::endl;
	Bolota.takeDamage(100);
	Bolota.attack("Joao"); // will not be visible because Bolota has no more hitPoints left

	std::cout << RESET << std::endl << "----------------------------------------------------------------------------" << std::endl;
	std::cout <<  YELLOW << std::endl << "Fraga's fight history: " << std::endl;
	std::cout << std::endl;
	Fraga.attack("Joao");
	Fraga.takeDamage(2);
	Fraga.beRepaired(1);
	Fraga.highFivesGuys();

	std::cout << std::endl;
	std::cout << "Fraga only has 98 points of energy left, so she can only attack 98 times more!" << std::endl; 
	for (int i = 0; i < 200; i++)
		Fraga.attack("Joao");

	std::cout << std::endl;
	Fraga.takeDamage(100);
	Fraga.attack("Joao"); // will not be visible because Fraga has no more hitPoints left
	std::cout << RESET << std::endl;

	std::cout << std::endl << "---------------------------------------------------------------------------" << std::endl;
	DiamondTrap Joao("Joao");
	std::cout << std::endl << RED << "Joao's fight history: "<< std::endl;
	Joao.attack("Maria");
	Joao.takeDamage(2);
	Joao.beRepaired(1);
	Joao.whoAmI();
	
	std::cout << std::endl;
	std::cout << "Joao only has 48 points of energy left, so she can only attack 48 times more!" << std::endl; 
	for (int i = 0; i < 200; i++)
		Joao.attack("Maria");
	
	std::cout << std::endl;
	Joao.takeDamage(100);
	Joao.takeDamage(100); //won't be visible because he can't take anymore damage
	Joao.attack("Maria"); // will not be visible because Joao has no more hitPoints left
}