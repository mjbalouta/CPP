/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:54:45 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/18 14:45:21 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <set>

int main(void)
{
	std::cout << std::endl << "---------------------EXCEPTIONS TESTS---------------------" << std::endl << std::endl;
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
		std::cout << std::endl << "Span's overflow capacity test using addMultipleNumbers:" << std::endl;
		Span sp = Span(5);
		std::vector<int> vec;
		for (int value = 0; value < 15; value++)
			vec.push_back(value);
		sp.addMultipleNumbers(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
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

	
	std::cout << std::endl << "-----------------------WORKING TESTS-----------------------" << std::endl << std::endl;
	try
	{
		std::cout << std::endl << "Provided test (subject):" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "With containers sequence (vector):" << std::endl;
		Span sp = Span(16);
		std::vector<int> vec;
		for (int value = 0; value <= 15; value++)
			vec.push_back(value);
		sp.addMultipleNumbers(vec.begin(), vec.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "With containers sequence (vector) + existing numbers on the span:" << std::endl;
		Span sp = Span(16);
		sp.addNumber(155);
		std::vector<int> vec;
		for (int value = 0; value < 15; value++)
			vec.push_back(value);
		sp.addMultipleNumbers(vec.begin(), vec.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "With containers sequence (vector) + adding 15.000 numbers:" << std::endl;
		Span sp = Span(16000);
		std::vector<int> vec;
		for (int value = 0; value <= 15000; value++)
			vec.push_back(value);
		sp.addMultipleNumbers(vec.begin(), vec.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "With containers sequence (vector) + adding no numbers:" << std::endl;
		Span sp = Span(16000);
		sp.addNumber(1);
		sp.addNumber(2);
		std::vector<int> vec;
		sp.addMultipleNumbers(vec.begin(), vec.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "With containers sequence (vector) + adding repeated numbers:" << std::endl;
		Span sp = Span(10);
		sp.addNumber(1);
		sp.addNumber(2);
		std::vector<int> vec;
		for (int value = 0; value <= 7; value++)
			vec.push_back(value);
		sp.addMultipleNumbers(vec.begin(), vec.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	
	try
	{
		std::cout << std::endl << "With containers (set) + existing numbers on the span:" << std::endl;
		Span sp = Span(16);
		sp.addNumber(155);
		std::set<int> vec;
		for (int value = 0; value < 15; value++)
			vec.insert(value); //push_back only works for sequence containers
		sp.addMultipleNumbers(vec.begin(), vec.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "With containers (set) + adding 15.000 numbers:" << std::endl;
		Span sp = Span(16000);
		std::set<int> vec;
		for (int value = 0; value <= 15000; value++)
			vec.insert(value);
		sp.addMultipleNumbers(vec.begin(), vec.end());
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "Testing repeated numbers with set container:" << std::endl;
		Span sp = Span(10);
		std::set<int> vec;
		for (int value = 0; value <= 7; value++)
			vec.insert(value);
		vec.insert(0); // added a duplicate do the set container and it eliminated it
		sp.addMultipleNumbers(vec.begin(), vec.end());
		//here the shortest span will be 1 because there are no duplicates
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "Testing repeated numbers with multiset container:" << std::endl;
		Span sp = Span(10);
		std::multiset<int> vec;
		for (int value = 0; value <= 7; value++)
			vec.insert(value);
		vec.insert(0); // added a duplicate do the set container and it eliminated it
		sp.addMultipleNumbers(vec.begin(), vec.end());
		//here the shortest span will be 0 because multiset accepts duplicates
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	
	return 0;
}