/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:18:44 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/21 21:52:46 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap Maria("Maria");
	
	Maria.attack("Joao");
	Maria.takeDamage(2);
	Maria.beRepaired(1);
	
	std::cout << "Maria only has 8 points of energy left, so she can only attack 8 times more!" << std::endl; 
	for (int i = 0; i < 200; i++)
		Maria.attack("Joao");
}