#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <cstdlib>
#include <climits>
#include <utility>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include <iomanip> 

class PmergeMe
{
	private:
	std::deque<int> _deque;
	std::list<int> _list;
	std::deque<std::pair<int, int> > _dequePairs;
	std::list<std::pair<int, int> > _listPairs;
	int _dequeLeftover;
	int _listLeftover;
	std::vector<int> _jacobDeque;
	std::vector<int> _jacobList;
	long long _startTimeDeque;
	long long _endTimeDeque;
	long long _endTimeList;
	long long _startTimeList;

	void groupPairsDeque();
	void groupPairsList();
	void orderDequeWinners(std::deque<std::pair<int, int> >& pairs);
	void orderListWinners(std::list<std::pair<int, int> >& pairs);
	void generateJacobsthalNumbersDeque();
	void generateJacobsthalNumbersList();
	void insertDequeLosers();
	void insertListLosers();
	long long getCurrentTime() const;
	void printTimeIntervals() const;
	void printNumbers(const std::string& keyword) const;
	void parseArgsDeque(int ac, char **av);
	void parseArgsList(int ac, char **av);

	public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);
	~PmergeMe();

	void processAlgorithm(int ac, char **av);

	class NegativeNumberException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Error: Negative numbers are not allowed.";
		}
	};

	class NotANumberException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Error: Only numbers are allowed.";
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