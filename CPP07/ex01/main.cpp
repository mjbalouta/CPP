/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:23:44 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/06 18:20:21 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void print(const int &a)
{
	std::cout << a << ",";
}

void add(int &a)
{
	a += 1;
}

int main()
{
	int arr[] = {1, 2, 3};
	const int arr1[] = {4, 5, 6};

	::iter(arr, 3, add);
	for (int i = 0; i < 3; i++)
		std::cout << arr[i] << ",";
	std::cout << std::endl;
	::iter(arr1, 3, print);
	
	return 0;
}