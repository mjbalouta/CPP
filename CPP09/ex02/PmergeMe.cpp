#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _dequeLeftover(-1), _listLeftover(-1) {}

PmergeMe::PmergeMe(const PmergeMe& copy) :
_deque(copy._deque), _list(copy._list), _dequePairs(copy._dequePairs), _listPairs(copy._listPairs),
_dequeLeftover(copy._dequeLeftover), _listLeftover(copy._listLeftover) {}
	
PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_deque = copy._deque;
		_list = copy._list;
		_dequePairs = copy._dequePairs;
		_listPairs = copy._listPairs;
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

void PmergeMe::processAlgorithm()
{
	groupPairs();
}

void PmergeMe::groupPairs()
{
	//for deque
	if (_deque.size() % 2 != 0)
		_dequeLeftover = _deque.back();

	for (size_t i = 0; i + 1 < _deque.size(); i += 2)
	{
		//put the larger number in the 1st position of the pairing
		if (_deque[i] > _deque[i + 1])
			_dequePairs.push_back(std::make_pair(_deque[i], _deque[i + 1]));
		else
			_dequePairs.push_back(std::make_pair(_deque[i + 1], _deque[i]));
	}

	//for list
	std::list<int>::iterator it = _list.begin();
	while (it != _list.end())
	{
		int first = *it;
		++it;
		if (it == _list.end())
		{
			_listLeftover = first;
			break;
		}
		int second = *it;
		if (first > second)
			_listPairs.push_back(std::make_pair(first, second));
		else
			_listPairs.push_back(std::make_pair(second, first));
		++it;
	}
}

