/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:20:54 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/08 18:47:57 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#define RESET "\033[0m"
#define PURPLE "\e[0;35m"
#define YELLOW "\e[0;33m"

#include <iostream>

class Weapon
{
	private:
	std::string type;

	public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType() const;
	void setType(std::string type);
};

#endif