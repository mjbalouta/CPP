/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:52:47 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/17 16:57:19 by mjoao-fr         ###   ########.fr       */
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
	void addMultipleNumbers(std::vector<int>::iterator numbers);

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