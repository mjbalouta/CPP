/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:54:51 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/17 13:48:14 by mjoao-fr         ###   ########.fr       */
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
typename T::const_iterator easyfind(const T& container, int toFind)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw FindException();
	return it;
}