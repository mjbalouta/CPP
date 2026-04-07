/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:11:31 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/04/07 13:52:35 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) :
_stack(copy._stack), _operator(copy._operator) {}

RPN& RPN::operator=(const RPN& copy)
{
	if (this != &copy)
	{
		_stack = copy._stack;
		_operator = copy._operator;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::processArgs(std::string expression)
{
	size_t spacePos;
	
	for (size_t i = 0; i < expression.size(); i++)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			int digit = expression[i] - '0';
			_stack.push(digit);
		}
		else if (expression[i] == ' ')
			continue;
		else
		{
			identifyOperator(expression[i]);
			performOperation();
		}
		spacePos = expression.find(' ', i);
		if (spacePos != i + 1 && i != expression.size() - 1)
			throw FormatException();
	}
	printResult();
}

void RPN::identifyOperator(char op)
{
	if (op == '+')
		_operator = '+';
	else if (op == '-')
		_operator = '-';
	else if (op == '/')
		_operator = '/';
	else if (op == '*')
		_operator = '*';
	else
		throw CharacterException();
}

void RPN::performOperation()
{
	if (_stack.size() < 2)
		throw OperationException();
		
	int firstValue;
	int secondValue;

	secondValue = _stack.top();
	_stack.pop();
	firstValue = _stack.top();
	_stack.pop();

	if (_operator == '+')
		_stack.push(firstValue + secondValue);
	else if (_operator == '-')
		_stack.push(firstValue - secondValue);
	else if (_operator == '/')
	{
		if (secondValue == 0)
			throw OperationException();
		_stack.push(firstValue / secondValue);
	}
	else if (_operator == '*')
		_stack.push(firstValue * secondValue);
}

void RPN::printResult()
{
	if (_stack.size() > 1)
		throw FormatException();
	if (_stack.empty())
		throw OperationException();
	while (!_stack.empty())
	{
		std::cout << _stack.top() << std::endl;
		_stack.pop();
	}
}
