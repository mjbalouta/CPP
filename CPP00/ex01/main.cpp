/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:22:20 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/07 11:29:08 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    std::string option;
    PhoneBook phoneBook;

	//ERROS:
	//1) Quando preencho 8 pessoas e vou para a 9ª pessoa, substitui a do index 0, mas os restantes são apagados
	//2) Depois de fazer o SEARCH, o prompt para selecionar o ADD(...) aparece duplicado
	
    while (1)
    {
        std::cout << "Select an option between ADD, SEARCH AND EXIT" << std::endl;
        getline(std::cin, option);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		else if (option.empty())
			continue;
        if (option == "ADD")
            phoneBook.addContact();
		else if (option == "SEARCH")
			phoneBook.searchContact();
        else if (option == "EXIT")
            return (0);
        else
            std::cout << "Invalid option." << std::endl;
    }
    return (0);
}