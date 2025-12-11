/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:48:17 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/11 16:24:18 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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