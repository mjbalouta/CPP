/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:05:35 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/05 15:00:21 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int contactCount;
	
	public:
		PhoneBook();
		void addContact();
		void searchContact();
};
