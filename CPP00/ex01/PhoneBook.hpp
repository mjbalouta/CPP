/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:05:35 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/07 15:31:50 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <limits>
#include "Contact.hpp"

#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"
#define RED     "\033[31m"

class PhoneBook
{
	private:
		Contact contacts[8];
		int contactCount;
		int	index;
	
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact();
};
