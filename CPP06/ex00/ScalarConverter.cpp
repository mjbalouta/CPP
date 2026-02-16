/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:28:02 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/12 12:15:19 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool detectFloat(const int countDots, const int countFs, const int countDigits, const std::string &data)
{
	if (data == "nanf")
    	return true;
	if (data == "+inff" || data == "-inff")
    	return true;
	size_t size = data.length();
	int notDigits = 0;
	if (countDots == 1 && countFs == 1 && data[size - 1] == 'f')
	{
		notDigits = 2;
		size_t position = data.find('.', 0);
		if (data[0] == '-' || data[0] == '+')
		{
			notDigits = 3;
			if (position == 1 || position == size - 2)
				return false;
		}
		else
		{
			if (position == 0 || position == size - 2)
				return false;	
		}
		if (countDigits == (static_cast<int>(size)) - notDigits)
			return true;
	}
	return false;
}

bool detectInt(const int countDots, const int countFs, const int countDigits, const std::string &data)
{
	if (countDots == 0 && countFs == 0)
	{
		int size = data.length();
		if (countDigits == size)
			return true;
		else if (countDigits == size - 1 && (data[0] == '-' || data[0] == '+') && size > 1)
			return true;
	}
	return false;
}

bool detectDouble(const int countDots, const int countFs, const int countDigits, const std::string &data)
{
	if (data == "nan")
   		return true;
	if (data == "+inf" || data == "-inf")
		return true;
	size_t size = data.length();
	int notDigits = 0;
	if (countDots == 1 && countFs == 0)
	{
		notDigits = 1;
		size_t position = data.find('.', 0);
		if (data[0] == '-' || data[0] == '+')
		{
			notDigits = 2;
			if (position == 1 || position == size - 1)
				return false;
		}
		else
		{
			if (position == 0 || position == size - 1)
				return false;
		}
		if (countDigits == (static_cast<int>(size)) - notDigits)
			return true;
	}
	return false;
}

bool detectChar(const int countDigits, const std::string &data)
{
	if (countDigits == 0 && data.length() == 1)
		return true;
	return false;
}

DataType detectFormat(const std::string& data)
{	
	int countDots = 0;
	int countFs = 0;
	int countDigits = 0;

	for (int i = 0; i < (static_cast<int>(data.length())); i++)
	{
		if (data[i] == '.')
			countDots++;
		else if (data[i] == 'f')
			countFs++;
		else if (std::isdigit(static_cast<unsigned char>(data[i])))
			countDigits++;
	}

	if (detectFloat(countDots, countFs, countDigits, data))
		return FLOAT;
	else if (detectDouble(countDots, countFs, countDigits, data))
		return DOUBLE;
	else if (detectInt(countDots, countFs, countDigits, data))
		return INT;
	else if (detectChar(countDigits, data))
		return CHAR;
	return INVALID;
}

void convertFromChar(const std::string& data)
{
	char c = data[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;		
	float f = static_cast<float>(c);
	std::cout << "float: " << f << ".0f" << std::endl;
	double d = static_cast<double>(c);
	std::cout << "double: " << d << ".0" << std::endl;
}

void convertFromInt(const std::string& data)
{
	double d = std::strtod(data.c_str(), NULL);

	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<char>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
		
	if (d >= static_cast<double>(std::numeric_limits<int>::min()) && d <= static_cast<double>(std::numeric_limits<int>::max())) //check for int overflow
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (f > -1000000 && f < 1000000 && f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	
	std::cout << "double: " << d;
	if (d > -1000000 && d < 1000000 && d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void convertFromFloat(const std::string& data)
{
	if (data == "nanf" || data == "+inff" || data == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << data << std::endl;
		std::string str = data;
		str.erase(str.length() - 1);
		std::cout << "double: " << str << std::endl;
		return;
	}
	
	float f = static_cast<float>(std::strtod(data.c_str(), NULL));
	char c = static_cast<char>(f);
	if (f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
		
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max()) //check for int overflow
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
		
	std::cout << "float: " << f;
	if (f > -1000000 && f < 1000000 && f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	
	double d = static_cast<double>(f);
	std::cout << "double: " << d;
	if (d > -1000000 && d < 1000000 && d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void convertFromDouble(const std::string& data)
{
	if (data == "nan" || data == "+inf" || data == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << data << "f" << std::endl;
		std::cout << "double: " << data << std::endl;
		return;
	}

	double d = std::strtod(data.c_str(), NULL);
	char c = static_cast<char>(d);
	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (f > -1000000 && f < 1000000 && f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << d;
	if (d > -1000000 && d < 1000000 && d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void convertFromInvalid(void)
{
	std::cout << "char: impossible" << std::endl;
 	std::cout << "int: impossible" << std::endl;
 	std::cout << "float: impossible" << std::endl;
 	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& data)
{
	DataType typeOfData = detectFormat(data);
	
	switch (typeOfData)
	{
		case CHAR:
			convertFromChar(data);
			break;
		case INT:
			convertFromInt(data);
			break;
		case FLOAT:
			convertFromFloat(data);
			break;
		case DOUBLE:
			convertFromDouble(data);
			break;
		default:
			convertFromInvalid();
	}
}