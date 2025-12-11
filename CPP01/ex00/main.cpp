/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:20:03 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/11 14:06:50 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define RED "\033[91m"
#define RESET "\033[0m"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{	
	std::cout << std::endl << RED << "CREATING ZOMBIE USING HEAP MEMORY:" << RESET << std::endl;
	Zombie *Zombie = newZombie("Foo");
	std::cout << RED << "ZOMBIE CREATED, NOW ASKING IT TO ANNOUNCE ITSELF..." << RESET << std::endl;
	Zombie->announce();
	std::cout << RED << "NOW IT NEEDS TO BE DESTROYED..." << RESET << std::endl;
	delete Zombie;

	std::cout << RED << "_______________________________________________________________________" << RESET << std::endl << std::endl;
	std::cout << RED << "CREATING ZOMBIE USING STACK MEMORY:" << RESET << std::endl;
	randomChump("Foo");
	std::cout << RED << "ZOMBIE WAS CREATED, ANNOUNCED ITSELF AND WAS AUTOMATICALLY DESTROYED..." << RESET << std::endl << std::endl;
}