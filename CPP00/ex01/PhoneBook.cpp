/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:22:26 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/07 15:20:20 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contactCount = 0;
	index = 0;
}

void	detectEof()
{
	if (std::cin.eof())
	{
		std::cout << std::endl;
		exit(0);
	}
}

void	PhoneBook::addContact()
{
	std::string input;
	
	if (index == 8)
		index = 0;
	
	std::cout << std::endl;
	do {
		std::cout << "Enter first name: " << std::endl;
		std::getline(std::cin, input);
		detectEof();
		if (input.empty())
			std::cout << RED << "First name cannot be empty." << RESET << std::endl;
	} while (input.empty());
	contacts[index].setFirstName(input);

	do {
		std::cout << "Enter last name: " << std::endl;
		std::getline(std::cin, input);
		detectEof();
		if (input.empty())
			std::cout << RED << "Last name cannot be empty." << RESET << std::endl;
	} while (input.empty());
	contacts[index].setLastName(input);

	do {
		std::cout << "Enter nickname: " << std::endl;
		std::getline(std::cin, input);
		detectEof();
		if (input.empty())
			std::cout << RED << "Nickname cannot be empty." << RESET << std::endl;
	} while (input.empty());
	contacts[index].setNickname(input);

	do {
		std::cout << "Enter phone number: " << std::endl;
		std::getline(std::cin, input);
		detectEof();
		if (input.empty())
			std::cout << RED << "Phone number cannot be empty." << RESET << std::endl;
	} while (input.empty());
	contacts[index].setPhoneNumber(input);

	do {
		std::cout << "Enter darkest secret: " << std::endl;
		std::getline(std::cin, input);
		detectEof();
		if (input.empty())
			std::cout << RED << "Darkest secret cannot be empty." << RESET << std::endl;
	} while (input.empty());
	contacts[index].setDarkestSecret(input);

	index++;
	if (contactCount < 8)
		contactCount++;
	std::cout << BLUE << "Contact added to the Phonebook." << RESET << std::endl << std::endl;
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

// int	checkInput(std::string option)
// {
// 	if (option == "0" || option == "1" || option == "2" || option == "3"
// 		|| option == "4" || option == "5" || option == "6" || option == "7" || option == "8")
// 		return (0);
// 	return (1);
// }

void	PhoneBook::searchContact()
{
	int option;
	
	if (contactCount < 1)
	{
		std::cout << RED << "Phonebook still empty. Add some contacts first." << RESET << std::endl << std::endl;
		return;
	}
	
	std::cout << std::endl << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname" << std::endl;
	
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << truncate(contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << truncate(contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << truncate(contacts[i].getNickname());
		std::cout << std::endl;
	}
	
	std::cout << std::endl;

	while (true)
	{
		std::cout << "Select which contact you want to search based on its index:" << std::endl;
		std::cin >> option;
		detectEof();
		if (std::cin.fail() || option < 0 || option >= contactCount)
		{
			if (std::cin.fail())
            {
                std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
			std::cout << RED << "Invalid index. Try again." << RESET << std::endl;
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
	
	std::cout << std::endl << BLUE << "CONTACT INFORMATION" << RESET << std::endl;
	std::cout << "First name: " << contacts[option].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[option].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[option].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[option].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[option].getDarkestSecret() << std::endl << std::endl;
}