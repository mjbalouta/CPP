/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:23:49 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/23 09:57:43 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Default Animal") 
{
	std::cout << "Animal default constructor called." << std::endl;	
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}

Animal::~Animal() 
{
	std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "This animal makes an unidentifiable sound." << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}