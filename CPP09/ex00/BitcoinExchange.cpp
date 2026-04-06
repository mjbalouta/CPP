/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:42:39 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/28 11:54:03 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _database() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
: _database(copy._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
		_database = copy._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string& trimSpaces(std::string& str)
{
	//set of chars to search against
	const std::string whitespace = " \t\n\r\f\v";
	
	/*searches for the index of first not whitespace and erases everything
	from beggining of str until that pos*/
	str.erase(0, str.find_first_not_of(whitespace));
	
	/*erases everything from the pos of the last not whitespace (+1) until
	the end of the string*/
	str.erase(str.find_last_not_of(whitespace) + 1);

	return str;
}

bool BitcoinExchange::validDate(std::string& date) const
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	//usage substr(position, nr of digits)
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	//parsing year
	//leap year (february with 29 days)
	if (year < 1)
		return false;
	int leapYear = 0;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		leapYear = 1;
	
	//parsing month
	if (month < 1 || month > 12)
		return false;
	int maxDays = 0;
	if (month == 2 && leapYear == 1)
		maxDays = 29;
	else if (month == 2 && leapYear == 0)
		maxDays = 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDays = 30;
	else
		maxDays = 31;
	
	//parsing day
	if (day > maxDays || day < 1)
		return false;
	return true;
}

std::string BitcoinExchange::validValue(std::string& value) const
{
	if (value.empty())
		return "Error: empty value.";

	int dotCount = 0;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (i == 0 && value[0] == '-' && value.size() > 1)
			return "Error: not a positive number.";	
		//first and last pos must be a digit (can't be a '.')
		if ((i == 0 || i == value.size() - 1) && !std::isdigit(static_cast<unsigned char>(value[i])))
			return "Error: not a valid number.";
		//every other character must be a digit or a '.'
		if (!std::isdigit(value[i]) && value[i] != '.')
			return "Error: not a valid number.";
		if (value[i] == '.')
			dotCount++;
		if (dotCount > 1)
			return "Error: not a valid number.";
	}
	
	//using double works for both int and float
	double number = std::atof(value.c_str());
	if (number < 0)
		return "Error: not a positive number.";
	else if (number > 1000)
		return "Error: too large a number.";
	return "Valid.";
}

void BitcoinExchange::parseFirstLine(const std::string& firstLine) const
{
	size_t separator = firstLine.find('|');
	if (separator != std::string::npos)
	{
		std::string firstPart = firstLine.substr(0, separator);
		std::string secondPart = firstLine.substr(separator + 1);
	
		firstPart = trimSpaces(firstPart);
		secondPart = trimSpaces(secondPart);
		if (firstPart != "date" || secondPart != "value")
			throw InputWrongException();	
	}
	else
		throw InputWrongException();
}

void BitcoinExchange::loadDatabase()
{
	std::ifstream file("data.csv");

	if (!file.is_open())
		throw OpenDataFileException();
		
	std::string date;
	std::string rate;
	std::string line;
	bool firstLine = true;
	//for each line, it will split the first part into date and the second into rate
	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue;	
		}
		size_t pos = line.find(',');
		if (pos != std::string::npos)
		{
			date = line.substr(0, pos);
			rate = line.substr(pos + 1);
		}
		//converts from string to double
		double rateValue = std::atof(rate.c_str());
		//stores in map
		_database[date] = rateValue;
	}
}

void BitcoinExchange::processInput(const std::string& filename)
{
	loadDatabase();
	std::ifstream input(filename.c_str());
	if (!input.is_open())
		throw OpenInputFileException();
	std::string date;
	std::string value;
	std::string line;
	bool firstLine = true;
	while (std::getline(input, line))
	{
		if (firstLine)
		{
			parseFirstLine(line);
			firstLine = false;
			continue;
		}
		size_t pos = line.find('|');
		if (pos != std::string::npos)
		{
			date = line.substr(0, pos);
			value = line.substr(pos + 1);
		}
		else
			date = line;
		date = trimSpaces(date);
		value = trimSpaces(value);
		if (!validDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (validValue(value) != "Valid.")
		{
			std::cout << validValue(value) << std::endl;
			continue;
		}
		//using upper_bound() to find the one element that is greater than the date
		//then we subtract one and we get the exact date or the one immediately before
		std::map<std::string, double>::const_iterator it = _database.upper_bound(date);
		if (it == _database.end())
		{
			std::cout << "Error: not a match for the " << date << "date." << std::endl;
			continue ;
		}
		--it;
		//date => value = result of value * exchange rate
		std::cout << date << " => " << value << " = " << std::atof(value.c_str()) * it->second << std::endl;
	}
}

