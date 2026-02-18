/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:54:45 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/18 17:29:33 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main(void)
{
	MutantStack<int> mStack;
	mStack.push(1);
	mStack.push(2);
	mStack.push(0);
	mStack.push(3);
	mStack.push(42);
	std::cout << std::endl << "Stack elements: ";
	for (MutantStack<int>::iterator it = mStack.begin(); it != mStack.end(); ++it)
	{
		std::cout << *it;
		if (it != mStack.end() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
	std::cout << "Using size to know the size of the stack: " << mStack.size() << std::endl;
	std::cout << "Using top to know which value is in the top of the stack: "
	<< mStack.top() << std::endl;
	std::cout << "Using pop to remove the last one added..." << std::endl;
	mStack.pop();
	std::cout << "Updated stack elements: ";
	for (MutantStack<int>::iterator it = mStack.begin(); it != mStack.end(); ++it)
	{
		std::cout << *it;
		if (it != mStack.end() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
	std::cout << "Now showing the top one is a different one: " << mStack.top()
	<< std::endl;
	std::cout << "Size of the stack updated: " << mStack.size() << std::endl;
	return 0;
}