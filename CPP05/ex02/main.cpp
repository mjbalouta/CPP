/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:04:12 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/11 18:26:54 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	try 
	{
		std::cout << std::endl << std::endl << "-------------BUREAUCRAT-------------" << std::endl;
		Bureaucrat m("Maria", 1);
		std::cout << m << std::endl;
		
		std::cout << std::endl << std::endl << "-------------SHRUBBERY-------------" << std::endl;
		ShrubberyCreationForm form("home");
		std::cout << form << std::endl;
		m.signForm(form);
		m.executeForm(form);

		std::cout << std::endl << std::endl << "-------------ROBOTOMY-------------" << std::endl;
		RobotomyRequestForm rob("rob");
		std::cout << rob << std::endl;
		m.signForm(rob);
		m.executeForm(rob);

		std::cout << std::endl << std::endl << "-------------PRESIDENTIAL-------------" << std::endl;
		PresidentialPardonForm presi("presi");
		std::cout << presi << std::endl;
		m.signForm(presi);
		m.executeForm(presi);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
}