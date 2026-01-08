/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:25:20 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/08 14:14:05 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#define RED "\033[91m"
#define RESET "\033[0m"
#define PURPLE "\e[0;35m"

class Zombie
{
	private:
	std::string name;
	
	public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void setName(std::string name);
	void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif