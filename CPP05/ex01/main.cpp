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
#include "Form.hpp"

int main(void)
{
	std::cout << std::endl << "VALID FORM BUREAUCRAT TEST:" << std::endl;
	try 
	{
		Bureaucrat a("Maria", 15);
		std::cout << a << std::endl;
		Form form("form", 16, 15);
		std::cout << form << std::endl;
		a.signForm(form);
		std::cout << form << std::endl;
		a.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "INVALID BUREAUCRAT'S GRADE TEST:" << std::endl;
	try 
	{
		Bureaucrat b("Maria", 1500);
		std::cout << b << std::endl;
		Form form("form", 1600, 15);
		std::cout << form << std::endl;
		b.signForm(form);
		std::cout << form << std::endl;
		b.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "GRADE TOO LOW TO SIGN FORM:" << std::endl;
	try 
	{
		Bureaucrat a("Maria", 15);
		std::cout << a << std::endl;
		Form form("form", 14, 15);
		std::cout << form << std::endl;
		a.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "INVALID FORM'S GRADE TEST:" << std::endl;
	try 
	{
		Bureaucrat b("Maria", 15);
		std::cout << b << std::endl;
		Form form("form", 151, 15);
		std::cout << form << std::endl;
		b.signForm(form);
		std::cout << form << std::endl;
		b.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}