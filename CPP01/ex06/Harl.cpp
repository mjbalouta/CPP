/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:35:37 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/09 16:16:06 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl () {}

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl; 
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int option = 0;
	
	if (level == "DEBUG")
		option = 1;
	else if (level == "INFO")
		option = 2;
	else if (level == "WARNING")
		option = 3;
	else if (level == "ERROR")
		option = 4;

	switch (option)
	{
		case 1:
			debug();
			/* fall through */
		case 2:
			info();
			/* fall through */
		case 3:
			warning();
			/* fall through */
		case 4:
			error();
		break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}