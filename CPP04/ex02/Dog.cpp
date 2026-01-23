/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:29:31 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/23 13:09:55 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() 
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called." << std::endl;
	_brain = new Brain(*copy._brain); //direct deep copy
	_type = copy._type;
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		std::cout << "Dog copy assignment called." << std::endl;
		_type = copy._type;
		delete _brain; //delete old brain to prevent mem leak
		_brain = new Brain(*copy._brain); //deep copy
	}
	return *this;
}

Dog::~Dog() 
{
	delete _brain;
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Au Auu!" << std::endl;
}

Brain& Dog::getBrain()
{
	return *_brain;
}
