/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:02:46 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/21 12:43:47 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
    
    Fixed(const int num);
    Fixed(const float num); 
    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    Fixed& operator++(void); //pre-increment
    Fixed operator++(int); //post-increment - the int paramether is only used to differentiate the signature
    Fixed& operator--(void); //pre-decrement
    Fixed operator--(int); //post-decrement
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif