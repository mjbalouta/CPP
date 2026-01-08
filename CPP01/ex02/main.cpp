/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:17:04 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/08 14:36:37 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define RESET "\033[0m"
#define PURPLE "\e[0;35m"
#define YELLOW "\e[0;33m"


int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << YELLOW << std::endl << "ADRESSES:" << std::endl;
	std::cout << &brain << std::endl;
	std::cout << stringPTR << std::endl; //already prints the address without the &
	std::cout << &stringREF << RESET << std::endl;

	std::cout << PURPLE << std::endl << "VALUES:" << std::endl;
	std::cout << brain << std::endl;
	std::cout << *stringPTR << std::endl; //needs * to access the value
	std::cout << stringREF << RESET << std::endl << std::endl;

	return (0);
}