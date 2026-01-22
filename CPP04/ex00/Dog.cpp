/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:29:31 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/22 23:22:29 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() 
{
	_type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
		_type = copy._type;
	return *this;
}

Dog::~Dog() {}

void Dog::makeSound() const
{
	std::cout << "Au Auu!" << std::endl;
}
