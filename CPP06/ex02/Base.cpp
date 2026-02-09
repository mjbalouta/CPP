/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:33:27 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/09 17:08:18 by mjoao-fr         ###   ########.fr       */
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

	switch (nr)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
	return NULL;
}

void identify(Base* p)
{
	if (!p)
		std::cout << "Null pointer." << std::endl;
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
		(void)dynamic_cast<A&>(p); //(void) because i don't want to use the result, I just want to know if the cast throws an exception
		std::cout << "This is an A." << std::endl;
		return;
	}
	catch(std::exception&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "This is a B." << std::endl;
		return;
	}
	catch(std::exception&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "This is a C." << std::endl;
		return;
	}
	catch(std::exception&){}
}