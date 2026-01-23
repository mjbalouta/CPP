/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:31:37 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/23 10:00:04 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() 
{
	_type = "Cat";
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

WrongCat::~WrongCat() 
{
	std::cout << "WrongCat default constructor called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meowwww" << std::endl;
}