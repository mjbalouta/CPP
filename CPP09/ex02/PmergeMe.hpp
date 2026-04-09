#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <cstdlib>
#include <climits>
#include <utility>

class PmergeMe
{
	private:
	std::deque<int> _deque;
	std::deque<std::pair<int, int> > _dequePairs;
	int _dequeLeftover;
	std::list<int> _list;
	std::list<std::pair<int, int> > _listPairs;
	int _listLeftover;

	void groupPairs();
	void orderDequeWinners(std::deque<std::pair<int, int> >& pairs);
	void orderListWinners(std::list<std::pair<int, int> >& pairs);

	public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);
	~PmergeMe();

	void parseArgs(int ac, char **av);
	void printNumbers(const std::string& keyword) const;
	void processAlgorithm();

	class NegativeNumberException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Error: Negative numbers are not allowed.";
		}
	};

	class DecimalNumberException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Error: Decimal numbers are not allowed.";
		}
	};

	class MaxNumberException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Error: Only numbers in the <0-INT_MAX> range are allowed.";
		}
	};

	class DuplicateNumberException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Error: Duplicates are not allowed.";
		}
	};
};