/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:22:20 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/05 16:37:31 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    std::string option;
    PhoneBook phoneBook;

	//FALTA O CONTROLO PARA NAO FICAR EM LOOP INFINITO COM CTRL+D
    while (1)
    {
        std::cout << "Select an option between ADD, SEARCH AND EXIT" << std::endl;
        std::cin >> option;
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