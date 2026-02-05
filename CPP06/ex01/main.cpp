/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:11:01 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/05 18:16:21 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data d;
	d.value = 42;

	Data* ptr = &d;
	std::cout << "Original pointer: " << ptr << std::endl;
	std::cout << "Data's value before serialize: " << ptr->value << std::endl;

	uintptr_t raw = Serializer::serialize(ptr);
	Data* restored = Serializer::deserialize(raw);
	std::cout << "Restored pointer: " << restored << std::endl;
	std::cout << "Data's value after serialize: " << restored->value << std::endl;

	return 0;
}