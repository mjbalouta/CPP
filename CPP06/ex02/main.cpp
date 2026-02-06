/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:03:53 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/06 13:10:46 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Base.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	
	Base* b = generate();
	Base& a = *b;
	identify(a);
	identify(b);

	delete b;
	return 0;
}