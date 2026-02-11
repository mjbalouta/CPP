/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:21:36 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/11 18:13:06 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void)
{
	std::cout << std::endl << "---------------CONSTRUCTOR WITH SIZE---------------" << std::endl;
	Array<int> arrayOne(5);
	std::cout << "size: " << arrayOne.size() << std::endl;
	std::cout << "default values: " << arrayOne[0] << std::endl;
	arrayOne[0] = 4;
	std::cout << "changed value: " << arrayOne[0] << std::endl;

	std::cout << "accessing out of bounds: ";
	try
	{
		std::cout << arrayOne[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "-----------------COPY CONSTRUCTOR-----------------" << std::endl;
	Array<int> arrayTwo(arrayOne);
	std::cout << "size: " << arrayTwo.size() << std::endl;
	std::cout << "comparing copied values: " << arrayTwo[0] << std::endl;
	arrayTwo[0] = 1;
	std::cout << "changing value here and comparing to the original: " 
	<< "(original: " << arrayOne[0] << " changed: " << arrayTwo[0] << ")" << std::endl;
	
	std::cout << std::endl << std::endl << "-----------------COPY ASSIGNMENT-----------------" << std::endl;
	Array<int> arrayThree;
	arrayThree = arrayTwo;
	std::cout << "comparing copied values: " << arrayThree[0] << std::endl;
	arrayThree[0] = 42;
	std::cout << "changing value here and comparing to the original: " 
	<< "(original: " << arrayTwo[0] << " changed: " << arrayThree[0] << ")" << std::endl << std::endl;

	std::cout << std::endl << "-------------CONSTRUCTOR WITH STRINGS-------------" << std::endl;
	Array<std::string> arrayFour(3);
	std::cout << "size: " << arrayFour.size() << std::endl;
	std::cout << "default values: " << arrayFour[0] << std::endl;
	arrayFour[0] = "Maria";
	std::cout << "changing the value: " << arrayFour[0] << std::endl;
	std::cout << "accessing out of bounds: ";
	try
	{
		std::cout << arrayFour[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

}	