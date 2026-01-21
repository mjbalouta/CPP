/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:02:48 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/21 15:45:22 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    // Fixed const c(Fixed(2.2f) / Fixed(1.2f));
    // Fixed const d(Fixed(5.5f) + Fixed(2.1f));
    // Fixed const e(Fixed(5.5f) - Fixed(2.1f));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    // std::cout << --a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a-- << std::endl;
    // std::cout << a << std::endl;
    // std::cout << c << std::endl;
    // std::cout << d << std::endl;
    // std::cout << e << std::endl;
    
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    // std::cout << Fixed::min( a, b ) << std::endl;
    
    return 0;
}