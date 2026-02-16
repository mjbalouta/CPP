/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:54:51 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/16 15:51:53 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>

class FindException : public std::exception
{
	public:
	virtual const char* what() const throw()
	{
		return "Occurence not found.";
	}		
};

template <typename T>
unsigned int easyfind(T container, int toFind)
{
	unsigned int position = std::find(container.begin(), container.end(), toFind);
	if (!position)
		throw FindException();
	return position;
}