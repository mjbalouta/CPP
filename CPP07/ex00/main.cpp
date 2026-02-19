/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:23:44 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/19 11:28:40 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;
	std::cout << "initial values of a and b: " << std::endl
	<< "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "values after swap: " << std::endl << "a = " << a 
	<< ", b = " << b << std::endl;
	std::cout << "min(a,b) = " << ::min(a,b) << std::endl;
	std::cout << "max(a,b) = " << ::max(a,b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "initial values of c and d: " << std::endl
	<< "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "values after swap: " << std::endl << "c = " << c 
	<< ", d = " << d << std::endl;
	std::cout << "min(c,d) = " << ::min(c,d) << std::endl;
	std::cout << "max(c,d) = " << ::max(c,d) << std::endl;
	
	return 0;
}