/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:37:51 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/23 11:56:01 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	protected:
	std::string _ideas[100];	

	public:
	Brain();
	Brain(const Brain& copy);
	Brain& operator=(const Brain& copy);
	~Brain();

	std::string getIdea(int index) const;
	void setIdea(int index, const std::string& idea);
};

#endif