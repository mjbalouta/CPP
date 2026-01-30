/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:10:39 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/30 15:49:47 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern& Intern::operator=(const Intern& copy) 
{
	if (this != &copy)
		*this = copy;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string list[3] = {"shrubbery form", "robotomy form", "presidential form"};
	int i = 0;
	int id = -1;

	for (i = 0; i < 3; i++)
	{
		if (name == list[i])
			id = i;
	}

	switch (id)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			throw FormNotFoundException();
	}
}