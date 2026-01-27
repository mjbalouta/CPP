/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:04:12 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/27 17:46:15 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl << "VALID BUREAUCRAT TEST:" << std::endl;
	try 
	{
		Bureaucrat a("Maria", 15);
		std::cout << a << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "GRADE TOO LOW BUREAUCRAT TEST:" << std::endl;
	try 
	{
		Bureaucrat b("Maria", 1500);
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "GRADE TOO HIGH BUREAUCRAT TEST:" << std::endl;
	try 
	{
		Bureaucrat b("Maria", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "VALID INCREMENT GRADE TEST:" << std::endl;
	try 
	{
		Bureaucrat c("Maria", 16);
		c.incrementGrade();
		std::cout << c << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "INVALID INCREMENT GRADE TEST:" << std::endl;
	try 
	{
		Bureaucrat d("Maria", 1);
		d.incrementGrade();
		std::cout << d << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "VALID DECREMENT GRADE TEST:" << std::endl;
	try 
	{
		Bureaucrat f("Maria", 16);
		f.decrementGrade();
		std::cout << f << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "INVALID DECREMENT GRADE TEST:" << std::endl;
	try 
	{
		Bureaucrat g("Maria", 150);
		g.decrementGrade();
		std::cout << g << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}