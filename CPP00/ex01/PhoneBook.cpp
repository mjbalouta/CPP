/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:22:26 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/05 15:04:13 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contactCount = 0;
}

void	PhoneBook::addContact()
{
	std::string input;
	
	if (contactCount == 8)
		contactCount = 0;
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //tells the input stream to ignore characters in the buffer (prevents it from accepting an empty line as input)

	do {
		std::cout << "Enter first name: " << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "First name cannot be empty." << std::endl;
		
	} while (input.empty());
	contacts[contactCount].setFirstName(input);

	do {
		std::cout << "Enter last name: " << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Last name cannot be empty." << std::endl;
		
	} while (input.empty());
	contacts[contactCount].setLastName(input);

	do {
		std::cout << "Enter nickname: " << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Nickname cannot be empty." << std::endl;
		
	} while (input.empty());
	contacts[contactCount].setNickname(input);

	do {
		std::cout << "Enter phone number: " << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Phone number cannot be empty." << std::endl;
		
	} while (input.empty());
	contacts[contactCount].setPhoneNumber(input);

	do {
		std::cout << "Enter darkest secret: " << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Darkest secret cannot be empty." << std::endl;
		
	} while (input.empty());
	contacts[contactCount].setDarkestSecret(input);

	contactCount++;
	std::cout << "Contact added to the Phonebook." << std::endl;
}

// void	PhoneBook::searchContact()
// {
	
// }