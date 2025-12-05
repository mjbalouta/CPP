/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:22:26 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/05 16:35:45 by mjoao-fr         ###   ########.fr       */
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
	
	//tells the input stream to ignore characters in the buffer (prevents it from interpreting leftover '\n' as input)
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
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

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void	PhoneBook::searchContact()
{
	int option;
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
	do {
		std::cout << "Select which contact you want to search based on its index:" << std::endl;
		std::cin >> option;
		if (option < 0 || option > 7)
			std::cout << "Wrong index. Try again." << std::endl;
	} while(option < 0 || option > 7);
	
	std::cout << "Contact Information: " << std::endl;
	std::cout << "First name: " << contacts[option].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[option].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[option].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[option].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[option].getDarkestSecret() << std::endl << std::endl;
}