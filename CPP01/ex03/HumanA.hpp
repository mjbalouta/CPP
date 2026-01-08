/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:01:34 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/08 18:51:15 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
	private:
	std::string name;
	/*weapon must be by reference because this human
	must always have a weapon - reference ensures it
	sees changes outside. references can never be null.
	*/
	Weapon& weapon;
	public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void attack();
};

#endif