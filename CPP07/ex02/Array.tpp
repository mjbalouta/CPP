/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:21:47 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/09 17:55:19 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& copy) : _array(NULL), _size(0)
{
	*this = copy;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& copy)
{
	if (this != &copy)
	{
		delete[] _array;
		_array = new T[_size];
		_size = copy._size;
		for (unsigned int = 0; i < _size; i++)
			_array[i] = copy._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}
template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}