/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:36:11 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/22 22:34:44 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() 
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog(); 
	const Animal* i = new Cat(); 
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl; 
	i->makeSound(); //will output the cat sound!
	j->makeSound(); 
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	
	return 0;
}