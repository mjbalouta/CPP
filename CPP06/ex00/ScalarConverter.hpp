/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:54:36 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/02 15:37:15 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <climits>

enum DataType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID,
};

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& copy);
	~ScalarConverter();
	
	static DataType detectFormat(const std::string& data);
	static bool detectFloat(const int countDots, const int countFs, const int countDigits, const std::string &data);
	static bool detectInt(const int countDots, const int countFs, const int countDigits, const std::string &data);
	static bool detectDouble(const int countDots, const int countFs, const int countDigits, const std::string &data);
	static bool detectChar(const int countDots, const int countFs, const int countDigits, const std::string &data);
	
	static void convertFromChar(const std::string& data);
	static void convertFromInt(const std::string& data);
	static void convertFromFloat(const std::string& data);
	static void convertFromDouble(const std::string& data);
	static void convertFromInvalid(const std::string& data);
	

	public:
	static void convert(const std::string& data);
};

#endif