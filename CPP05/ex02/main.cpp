/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:04:12 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/28 14:47:36 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << std::endl << "SHRUBBERY FORM TEST:" << std::endl;
	try 
	{
		ShrubberyCreationForm form("home");
		std::cout << form << std::endl;
		Bureaucrat m("Maria", 136);
		m.signForm(form);
		m.executeForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}