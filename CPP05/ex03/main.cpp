/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:04:12 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/30 15:50:20 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	try 
	{
		std::cout << std::endl << std::endl << "-------------BUREAUCRAT-------------" << std::endl;
		Bureaucrat maria("Maria", 1);
		std::cout << maria << std::endl;

		std::cout << std::endl << std::endl << "-------------INTERN-------------" << std::endl;
		Intern intern;
		std::cout << "Intern created." << std::endl;
	
		std::cout << std::endl << std::endl << "-------------SHRUBBERY-------------" << std::endl;
		// ShrubberyCreationForm form("home");
		AForm* form = intern.makeForm("shrubbery form", "home");
		std::cout << *form << std::endl;
		maria.signForm(*form);
		maria.executeForm(*form);
		delete form;

		std::cout << std::endl << std::endl << "-------------ROBOTOMY-------------" << std::endl;
		// RobotomyRequestForm rob("rob");
		AForm* rob = intern.makeForm("robotomy form", "target");
		std::cout << *rob << std::endl;
		maria.signForm(*rob);
		maria.executeForm(*rob);
		delete rob;

		std::cout << std::endl << std::endl << "-------------PRESIDENTIAL-------------" << std::endl;
		// PresidentialPardonForm presi("presi");
		AForm* presi = intern.makeForm("presidential form", "target");
		std::cout << *presi << std::endl;
		maria.signForm(*presi);
		maria.executeForm(*presi);
		delete presi;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
}