/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:42:36 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/02/28 11:49:35 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
	std::map<std::string, double> _database;
	void loadDatabase();
	void parseDate(std::string& date) const;
	void parseRate(std::string& rate) const;
	void parseFirstLine(const std::string& firstLine) const;

	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& copy);
	~BitcoinExchange();

	void processInput(const std::string& filename) const;

	class InputWrongException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Invalid input format. \
			Must be date | value, with date being 'year-month-day' and value \
			a positive float or integer between 0 and 1000.";
		}
	};

	class OpenDataFileException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Couldn't open data file.";
		}
	};

	class OpenInputFileException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Couldn't open input file.";
		}
	};
};