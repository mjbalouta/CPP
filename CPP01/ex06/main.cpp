/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:35:58 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/09 16:22:27 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <fstream>
#include <string>
#define RESET "\033[0m"
#define PURPLE "\e[0;35m"
#define YELLOW "\e[0;33m"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: not enough parameters."
		<< std::endl << "How to use: program + complaint [DEBUG, INFO, WARNING or ERROR]" << std::endl;
		return (1);
	}
	Harl harl;
	harl.complain(av[1]);
	return (0);
}