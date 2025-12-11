/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:20:03 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/11 16:24:27 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{	
	std::cout << std::endl << RED << "CREATING ZOMBIE USING HEAP MEMORY:" << RESET << std::endl;
	Zombie *zombie = newZombie("Foo");
	std::cout << RED << "ZOMBIE CREATED, NOW ASKING IT TO ANNOUNCE ITSELF..." << RESET << std::endl;
	zombie->announce();
	std::cout << RED << "NOW IT NEEDS TO BE DESTROYED..." << RESET << std::endl;
	delete zombie;

	std::cout << RED << "_______________________________________________________________________" << RESET << std::endl << std::endl;
	std::cout << RED << "CREATING ZOMBIE USING STACK MEMORY:" << RESET << std::endl;
	randomChump("Foo");
	std::cout << RED << "ZOMBIE WAS CREATED, ANNOUNCED ITSELF AND WAS AUTOMATICALLY DESTROYED..." << RESET << std::endl << std::endl;
}