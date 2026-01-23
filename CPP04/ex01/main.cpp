/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:36:11 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/23 14:42:17 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"
#define RESET "\033[0m"
#define PURPLE "\e[0;35m"
#define BLUE "\e[0;36m"

int main() 
{
	Animal* array[10];

	std::cout << std::endl << PURPLE << "CREATING DOGS:" << std::endl;
	for (int i = 0; i < 5; i++)
		array[i] = new Dog();
	
	std::cout << std::endl << RESET << "CREATING CATS:" << std::endl;
	for (int i = 5; i < 10; i++)
		array[i] = new Cat();

	std::cout << std::endl << BLUE << "DELETING ALL:" << std::endl;
	for (int i = 0; i < 10; i++)
		delete array[i];
	std::cout << std::endl;

	std::cout << std::endl << PURPLE << "PROVING DEEP COPY (COPY CONSTRUCTOR):" << std::endl;
	Dog* dog1 = new Dog();
	dog1->getBrain().setIdea(0, "I like to run.");
	std::cout << "First dog's idea: " << dog1->getBrain().getIdea(0) << std::endl;
	std::cout << "Now creating another dog based on the first one and showing they share the same idea." << std::endl;
	Dog* dog2 = new Dog(*dog1);
	std::cout << "Second dog's idea: " << dog2->getBrain().getIdea(0) << std::endl;
	std::cout << "Modifying second dog's idea and verifying if the first one's is also modified:" << std::endl;
	dog2->getBrain().setIdea(0, "I like to sleep.");
	std::cout << "Second dog's idea: " << dog2->getBrain().getIdea(0) << std::endl;
	std::cout << "First dog's idea: " << dog1->getBrain().getIdea(0) << std::endl;
	delete dog1;
	delete dog2;

	std::cout << RESET << std::endl << BLUE << "PROVING DEEP COPY (COPY ASSIGNMENT):" << std::endl;
	Dog* dog3 = new Dog();
	dog3->getBrain().setIdea(0, "I like to run.");
	std::cout << "First dog's idea: " << dog3->getBrain().getIdea(0) << std::endl;
	std::cout << "Now creating another dog based on the first one and showing they share the same idea." << std::endl;
	Dog* dog4 = new Dog();
	*dog4 = *dog3;
	std::cout << "Second dog's idea: " << dog4->getBrain().getIdea(0) << std::endl;
	std::cout << "Modifying second dog's idea and verifying if the first one's is also modified:" << std::endl;
	dog4->getBrain().setIdea(0, "I like to sleep.");
	std::cout << "Second dog's idea: " << dog4->getBrain().getIdea(0) << std::endl;
	std::cout << "First dog's idea: " << dog3->getBrain().getIdea(0) << std::endl;
	delete dog3;
	delete dog4;
	std::cout << RESET;
	
	return 0;
}
