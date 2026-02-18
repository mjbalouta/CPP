/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:52:47 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/18 14:46:44 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
	private:
	unsigned int _capacity;
	std::vector<int> _numbers;

	public:
	Span();
	Span(unsigned int capacity);
	Span(const Span& copy);
	Span& operator=(const Span& copy);
	~Span();
	
	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	template <typename T>
	void addMultipleNumbers(T begin, T end)
	{
		int nrElementsToAdd = std::distance(begin, end);
		
		if (_numbers.size() + nrElementsToAdd > _capacity)
			throw FullCapacityException();
		
		_numbers.insert(_numbers.end(), begin, end);

		//for testing:
		// std::cout << "_numbers vector with the added values: ";
		// for (std::vector<int>::iterator it = _numbers.begin(); it != _numbers.end(); ++it)
		// {
		// 	std::cout << *it;
		// 	if (it != _numbers.end() - 1)
		// 		std::cout << ", ";
		// }
		// std::cout << std::endl;
	}

	class FullCapacityException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Span's capacity is already full.";
		}
	};

	class NotEnoughNumbersException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Not enough numbers to compare.";
		}	
	};
};