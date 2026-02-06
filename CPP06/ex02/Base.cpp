/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:33:27 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/06 13:09:24 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void)
{
	int nr = rand() % 3;

	if (nr == 0)
		return new A;
	else if (nr == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This is an A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This is a B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This is a C." << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "This is an A." << std::endl;
		return;
	}
	catch(std::exception&) {}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "This is a B." << std::endl;
		return;
	}
	catch(std::exception&) {}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "This is a C." << std::endl;
		return;
	}
	catch(std::exception&){}
}