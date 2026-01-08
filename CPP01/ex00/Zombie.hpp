/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:48:17 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/08 13:30:01 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#define RED "\033[91m"
#define RESET "\033[0m"

class Zombie
{
	private:
	std::string name;

	public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif