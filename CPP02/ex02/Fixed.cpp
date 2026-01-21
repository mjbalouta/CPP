/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:02:42 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/21 15:09:19 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) 
{
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        value = other.getRawBits();     
    return *this;
}

Fixed::~Fixed() 
{
}

int Fixed::getRawBits(void) const 
{
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}
/**
 * @brief converts an integer into fixed-point by shifting 'fractional' bits
 * to the left
 * 
 * @param num 
 */
Fixed::Fixed(const int num)
{
    value = num << fractional;
}
/**
 * @brief converts a float into a fixed-point
 * 
 * @param num 
 */
Fixed::Fixed(const float num)
{
    value = roundf(num * (1 << fractional)); //using roundf gives more accuracy when converting
}

/**
 * @brief converts the fixed-point into a float again
 * 
 * @return float 
 */
float Fixed::toFloat(void) const
{
    float new_value;

    new_value = static_cast<float>(this->value) / (1 << fractional); //cast to float because otherwise it would return an int and not a float
    return (new_value);
}

/**
 * @brief converts the fixed-point into an int again
 * 
 */
int Fixed::toInt(void) const
{
    int new_value;
    
    new_value = this->value >> fractional;
    return (new_value);
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->value > other.value);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->value < other.value);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->value <= other.value);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->value >= other.value);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->value != other.value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->value + other.value);
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->value - other.value);
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->value * other.value) >> fractional);
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->value << fractional) / other.value);
    return (result);
}

Fixed& Fixed::operator++(void)
{
    value += 1;
    return (*this); //returns the object updated
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this; //saves old value
    value += 1; //increments value
    return (temp); //returns old value
}

Fixed& Fixed::operator--(void)
{
    value -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    value -= 1;
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a < b)
        return (b);
    else
        return (a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (b);
    else
        return (a);
}
/**
 * @brief defines how to represent the Fixed class in the output stream
 * 
 * @param os 
 * @param fixed 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}


