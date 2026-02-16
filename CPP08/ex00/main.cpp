/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:54:45 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/16 15:48:01 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int> array(5);
	for (int i = 0; i < 5; i++)
		array[i] = i;
	std::cout << "Trying to find the value 2 on the array:" << std::endl;
	std::cout << "Array: ";
	for (int i = 0; i < 5; i++)
	{
		std::cout << array[i];
		if (i != 4)
			std::cout << ", ";
	}
	std::cout << std::endl;
	unsigned int position = ::easyfind(array, 2);
	std::cout << "Value found at position: " << position << std::endl;
}