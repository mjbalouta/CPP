/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:21:33 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/09 17:41:14 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array
{
	private:
	T* _array;
	unsigned int _size;

	public:
	Array();
	Array(unsigned int n);
	Array(const Array<T>& copy);
	Array<T>& operator=(const Array<T>& copy);
	~Array();

	unsigned int size() const;

	class IndexException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Index out of bounds";
		}
	};
};

#include "Array.tpp"