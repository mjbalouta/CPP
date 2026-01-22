/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:23:51 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/22 17:31:28 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
	std::string _type;
	
	public:
	Animal();
	Animal(const Animal& copy);
	Animal& operator=(const Animal& copy);
	~Animal();

	void makeSound();
};

#endif