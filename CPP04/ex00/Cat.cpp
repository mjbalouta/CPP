/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:36:07 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/22 17:42:59 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() 
{
	_type = "Cat";	
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

Cat::~Cat() {}

void Cat::makeSound()
{
	std::cout << "Meowwww" << std::endl;
}

