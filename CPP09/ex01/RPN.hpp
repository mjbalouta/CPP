/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:11:34 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/04/07 13:46:12 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <cstdlib>
#include <iostream>

class RPN
{
	private:
	//it's easier to remove numbers because of pop()
	//default: stack wraps a deque (faster than the list)
	std::stack<int> _stack;
	char _operator;
	
	void identifyOperator(char op);
	void performOperation();
	void printResult();

	public:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& copy);
	~RPN();

	void processArgs(std::string expression);

	class CharacterException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Error: Invalid character.";
		}
	};

	class OperationException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Error: Operation error.";
		}
	};

	class FormatException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Error: Invalid format.";
		}
	};
	
};