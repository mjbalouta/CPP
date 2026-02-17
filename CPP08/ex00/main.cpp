/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:54:45 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/17 12:29:04 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
	//WITH VECTOR
	std::vector<int> v;
	
	for (int i = 0; i < 5; i++)
		v.push_back(i);
	
	std::cout << std::endl << "Vector: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it;
		if (it != v.end())
			std::cout << ", ";
	}
	std::cout << std::endl << std::endl;
	
	std::cout << "--------------VALUE FOUND--------------" << std::endl;
	try
	{
		std::cout << "Trying to find the value 2 on the array:" << std::endl;
		::easyfind(v, 2);
		std::cout << "Value was found in the container!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << std::endl << "--------------VALUE NOT FOUND--------------" << std::endl;
	try
	{
		std::cout << "Trying to find the value 100 on the array:" << std::endl;
		::easyfind(v, 100);
		std::cout << "Value was found in the container!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	//WITH LISTS
	std::list<int> l;
	
	for (int i = 0; i < 5; i++)
		l.push_back(i);
	
	std::cout << std::endl << "Vector: ";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		std::cout << *it;
		if (it != l.end())
			std::cout << ", ";
	}
	std::cout << std::endl << std::endl;
	
	std::cout << "--------------VALUE FOUND--------------" << std::endl;
	try
	{
		std::cout << "Trying to find the value 2 on the array:" << std::endl;
		::easyfind(v, 2);
		std::cout << "Value was found in the container!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << std::endl << "--------------VALUE NOT FOUND--------------" << std::endl;
	try
	{
		std::cout << "Trying to find the value 100 on the array:" << std::endl;
		::easyfind(v, 100);
		std::cout << "Value was found in the container!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}