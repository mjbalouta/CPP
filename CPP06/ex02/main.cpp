/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:03:53 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/09 17:09:50 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Base.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	
	Base* b = generate();
	Base& a = *b;
	Base* nullPointer = NULL;
	identify(a);
	identify(b);
	identify(nullPointer);

	delete b;
	return 0;
}