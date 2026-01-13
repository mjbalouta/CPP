/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:02:46 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/13 11:46:56 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
    int value;
    static const int fractional = 8;

    public:
    Fixed(); //default constructor
    Fixed(const Fixed& other); //copy constructor
    Fixed& operator=(const Fixed& other); //copy assignment operator
    ~Fixed(); //destructor
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif