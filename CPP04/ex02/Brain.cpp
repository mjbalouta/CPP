/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:37:53 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/23 14:40:35 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _ideas()
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& copy) 
{
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = copy._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index > 100)
	{
		std::cout << "Error. Nonexistent index." << std::endl;
		return (NULL);		
	}
	return (_ideas[index]);
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index > 100)
	{
		std::cout << "Error. Nonexistent index." << std::endl;
		return ;		
	}
	_ideas[index] = idea;
}