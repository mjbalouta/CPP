/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:36:11 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/23 13:39:34 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#define RESET "\033[0m"
#define PURPLE "\e[0;35m"
#define BLUE "\e[0;36m"

int main() 
{
	std::cout << BLUE << "Normal behaviour: " << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog(); 
	const Animal* i = new Cat(); 
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << i->getType() << ": "; 
	i->makeSound();
	std::cout << meta->getType() << ": "; 
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << RESET << PURPLE << std::endl << "Wrong behaviour: " << std::endl;
	const WrongAnimal* animal = new WrongAnimal();
	const Animal* dog = new Dog(); 
	const WrongAnimal* cat = new WrongCat();
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << cat->getType() << ": "; 
	cat->makeSound();
	std::cout << animal->getType() << ": "; 
	animal->makeSound();
	delete animal;
	delete dog;
	delete cat; //won't appear in the output because we must use a virtual destructor for the base class
	std::cout << RESET;

	std::cout << std::endl << std::endl << std::endl;
	std::cout << RESET << BLUE << std::endl << "Copy constructor test: " << std::endl;
	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog(*dog1);
	delete dog1;
	delete dog2;
	std::cout << std::endl;
	std::cout << RESET << BLUE << std::endl << "Copy assignment test: " << std::endl;
	Dog* dog3 = new Dog();
	Dog* dog4 = new Dog();
	*dog3 = *dog4;
	delete dog3;
	delete dog4;
	std::cout << RESET;

	return 0;
}