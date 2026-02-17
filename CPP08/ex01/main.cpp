/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:54:45 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/17 17:40:41 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{

	std::cout << std::endl << "----------Provided test---------" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl << "--------Exceptions tests--------" << std::endl << std::endl;
	try
	{
		std::cout << "Span's overflow capacity test:" << std::endl;
		Span sp = Span(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "Not enough numbers to compare test:" << std::endl;
		Span sp = Span(2);
		sp.addNumber(1);
		// sp.longestSpan(); //to test also the throw error in longest
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// std::cout << std::endl << "--------Working tests--------" << std::endl << std::endl;
	// try
	// {
	// 	std::cout << "Span's overflow capacity test:" << std::endl;
	// 	Span sp = Span(2);
	// 	sp.addNumber(1);
	// 	sp.addNumber(2);
	// 	sp.addNumber(3);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	
	return 0;
}