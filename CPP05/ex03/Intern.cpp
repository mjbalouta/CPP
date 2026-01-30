/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:10:39 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/30 13:29:49 by mjoao-fr         ###   ########.fr       */
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
	if (name == "shrubbery form")
		return new ShrubberyCreationForm(target);
	if (name == "robotomy form")
		return new RobotomyRequestForm(target);
	if (name == "presidential form")
		return new PresidentialPardonForm(target);
	throw AForm::FormNotFoundException();
}