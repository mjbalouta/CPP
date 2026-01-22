/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:23:49 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/22 17:35:54 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("") {}

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

Animal::~Animal() {}

void Animal::makeSound()
{
	std::cout << "This animal makes an unidentifiable sound." << std::endl;
}