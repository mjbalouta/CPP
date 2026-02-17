/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:52:49 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/17 17:32:29 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _capacity(0) {}

Span::Span(unsigned int capacity) : _capacity(capacity)
{
	_numbers.reserve(capacity);
}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		_capacity = copy._capacity;
		_numbers = copy._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_numbers.size() == _capacity)
		throw FullCapacityException();
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();
		
	std::vector<int> copy = _numbers;

	std::sort(copy.begin(), copy.end());
	unsigned int shortest = INT_MAX;
	unsigned int result = 0;
	for (std::vector<int>::iterator it = copy.begin(); it < copy.end() - 1; ++it)
	{
		result = *(it + 1) - *it;
		if (result < shortest)
			shortest = result;
	}
	return static_cast<unsigned int>(shortest);
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> copy = _numbers;
	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator it = copy.begin();
	int lowest = *it;
	int greatest = 0;
	for (it = copy.begin(); it < copy.end(); ++it)
	{
		if (it == copy.end() - 1)
			greatest = *it;
	}
	int result = greatest - lowest;
	return static_cast<unsigned int>(result);
}

