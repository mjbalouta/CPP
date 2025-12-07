/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:22:20 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/07 12:52:20 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    std::string option;
    PhoneBook phoneBook;

	//ERROS:
	//2) Depois de fazer o SEARCH, o prompt para selecionar o ADD(...) aparece duplicado
	
	std::cout << std:: endl;
    while (1)
    {
        std::cout << YELLOW << "Select an option between ADD(1), SEARCH(2) AND EXIT(3)" << RESET << std::endl;
        getline(std::cin, option);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		else if (option.empty())
			continue;
        if (option == "ADD" || option == "add" || option == "1")
            phoneBook.addContact();
		else if (option == "SEARCH" || option == "search" || option == "2")
			phoneBook.searchContact();
        else if (option == "EXIT" || option == "exit" || option == "3")
            return (0);
        else
            std::cout << RED << "Invalid option." << RESET << std::endl;
    }
    return (0);
}