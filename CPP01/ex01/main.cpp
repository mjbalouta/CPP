/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:25:11 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/08 14:12:37 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	//CREATING AN ARRAY OF ZOMBIES USING THE METHOD THAT CREATES AND NAMES THEM
	Zombie* horde = zombieHorde(10, "Foo");
	int i = 0;

	while (i < 10)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return 0;
}