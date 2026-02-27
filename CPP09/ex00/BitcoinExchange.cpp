/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:42:39 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/27 16:25:01 by mjoao-fr         ###   ########.fr       */
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

void BitcoinExchange::parseDate(const std::string& date) const
{
	if (date.length() != 10)
		throw InputWrongException();
	if (date[4] != '-' || date[7] != '-')
		throw InputWrongException();
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			throw InputWrongException();
	}
	//usage substr(position, nr of digits)
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	//parsing year
	//leap year (february with 29 days)
	if (year < 1)
		throw InputWrongException();
	int leapYear = 0;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		leapYear = 1;
	
	//parsing month
	if (month < 1 || month > 12)
		throw InputWrongException();
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
		throw InputWrongException();
}

void BitcoinExchange::parseRate(const std::string& rate) const
{
	if (rate.empty())
		throw InputWrongException();

	int dotCount = 0;
	for (int i = 0; i < rate.size(); i++)
	{
		//first and last pos must be a digit (can't be a '.')
		if ((i == 0 || i == rate.size() - 1) && !std::isdigit(rate[i]))
			throw InputWrongException();
		//every other character must be a digit or a '.'
		if (!std::isdigit(rate[i]) && rate[i] != '.')
			throw InputWrongException();
		if (rate[i] == '.')
			dotCount++;
		if (dotCount > 1)
			throw InputWrongException();
	}
	
	//using double works for both int and float
	double number = std::atof(rate.c_str());
		if (number < 0 || number > 1000)
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
	//for each line, it will split the first part into date and the second into rate
	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		if (pos != std::string::npos)
		{
			std::string date = line.substr(0, pos);
			std::string rate = line.substr(pos + 1);
		}
		else
			throw InputWrongException();
		//add here parse for date and parse for rate
		parseDate(date);
		
	}
	
}


