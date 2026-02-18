/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:53:31 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/18 17:14:18 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack& copy) : std::stack<T, Container>(copy) {}
	MutantStack& operator=(const MutantStack& copy)
	{
		std::stack<T, Container>::operator=(copy);
		return *this;
	}
	~MutantStack() {};

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
	const_iterator begin() const //needed if the container is created as a const
	{
		return this->c.begin();
	}
	const_iterator end() const
	{
		return this->c.end;
	}
};