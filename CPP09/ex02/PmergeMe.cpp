#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) :
_deque(copy._deque), _list(copy._list) {}
	
PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_deque = copy._deque;
		_list = copy._list;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArgs(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		//check if it is a decimal number
		std::string arg = av[i];
		if (arg.find('.') != std::string::npos)
			throw DecimalNumberException();

		//check positive integer limits
		long number = std::atol(av[i]);
		if (number < 0)
			throw NegativeNumberException();
		if (number > INT_MAX)
			throw MaxNumberException();

		//check if it is a duplicate
		for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it)
		{
			if (*it == number)
				throw DuplicateNumberException();
		}

		//add to containers
		_deque.push_back(number);
		_list.push_back(number);
	}
}

void PmergeMe::printNumbers(const std::string& keyword) const
{
	std::cout << keyword;
	for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// std::cout << keyword << " ";
	// for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
}


