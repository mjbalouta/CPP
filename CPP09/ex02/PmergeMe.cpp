#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _dequeLeftover(-1), _listLeftover(-1), _loosersSize(0) {}

PmergeMe::PmergeMe(const PmergeMe& copy) :
_deque(copy._deque), _list(copy._list), _dequePairs(copy._dequePairs), _listPairs(copy._listPairs),
_dequeLeftover(copy._dequeLeftover), _listLeftover(copy._listLeftover), _jacob(copy._jacob),
_loosersSize(copy._loosersSize) {}
	
PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_deque = copy._deque;
		_list = copy._list;
		_dequePairs = copy._dequePairs;
		_listPairs = copy._listPairs;
		_dequeLeftover = copy._dequeLeftover;
		_listLeftover = copy._listLeftover;
		_jacob = copy._jacob;
		_loosersSize = copy._loosersSize;
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
	orderDequeWinners(_dequePairs);
	orderListWinners(_listPairs);
	generateJacobsthalNumbers();
	insertDequeLosers();
	// insertListLosers();
	//insertLoosers
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

void PmergeMe::orderDequeWinners(std::deque<std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return;

	size_t mid = pairs.size() / 2;
	std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
	std::deque<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

	orderDequeWinners(left);
	orderDequeWinners(right);

	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i].first < right[j].first)
			pairs[k++] = left[i++];
		else
			pairs[k++] = right[j++];
	}

	while (i < left.size())
		pairs[k++] = left[i++];

	while (j < right.size())
		pairs[k++] = right[j++];
}

void PmergeMe::orderListWinners(std::list<std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return;

	size_t middle = pairs.size() / 2;
	std::list<std::pair<int, int> >::iterator middleIt = pairs.begin();
	//to advance middleIt to the middle position
	std::advance(middleIt, middle);

	//middleIt is included in the right one (the first iterator is inclusive, the second is exclusive)
	std::list<std::pair<int, int> > left(pairs.begin(), middleIt);
	std::list<std::pair<int, int> > right(middleIt, pairs.end());

	//after creating left and right, we need to clear the original one to store there the sorted pairs
	pairs.clear();

	orderListWinners(left);
	orderListWinners(right);

	std::list<std::pair<int, int> >::iterator leftIt = left.begin();
	std::list<std::pair<int, int> >::iterator rightIt = right.begin();
	while (leftIt != left.end() && rightIt != right.end())
	{
		if (leftIt->first < rightIt->first)
		{
			pairs.push_back(*leftIt);
			++leftIt;	
		}
		else
		{
			pairs.push_back(*rightIt);
			++rightIt;
		}
	}

	//if there are remaining pairs in left or right after all the
	//comparisons, we should do individual loops to add them to pairs
	while (leftIt != left.end())
	{
		pairs.push_back(*leftIt);
		++leftIt;
	}

	while (rightIt != right.end())
	{
		pairs.push_back(*rightIt);
		++rightIt;
	}
}

void PmergeMe::generateJacobsthalNumbers()
{
	if (_dequeLeftover >= 0)
		_loosersSize = 1;
	_loosersSize += (int)_dequePairs.size();

	//push the first two jacobsthal numbers
	_jacob.push_back(0);
	_jacob.push_back(1);

	int i = 2;
	while (_jacob.back() < _loosersSize)
	{
		int nextNumber = _jacob[i - 1] + 2 * (_jacob[i - 2]);
		_jacob.push_back(nextNumber);
		i++;
	}
}

void PmergeMe::insertDequeLosers()
{
	_deque.clear();

	//push just the winners to the _deque chain
	for (std::deque<std::pair<int, int> >::iterator it = _dequePairs.begin(); it != _dequePairs.end(); ++it)
		_deque.push_back(it->first);

	//insert the first looser (guaranteed it is the lowest number)
	std::deque<std::pair<int, int > >::iterator pairsIt = _dequePairs.begin();
	// std::deque<int>::iterator dequeIt = _deque.begin();
	// _deque.insert(dequeIt, pairsIt->second);

	std::vector<int>::iterator jacobIt = _jacob.begin();

	//loop to pick the next looser
	for (pairsIt = _dequePairs.begin() + 1; pairsIt != _dequePairs.end(); ++pairsIt)
	{
		int indexToSearchLooser = *jacobIt;
		int lastIndexToSearchLooser = 0;
		while (indexToSearchLooser > lastIndexToSearchLooser)
		{
			int looserToInsert = _dequePairs[indexToSearchLooser].second;
			//loop to find the position of the winner that belongs to the looser
			int winnerToFind = _dequePairs[indexToSearchLooser].first;
			for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it)
			{
				if (*it == winnerToFind)
				{
					//insertion search will now be made until this boundary
					_deque.insert(std::lower_bound(_deque.begin(), it), looserToInsert);
					break ;
				}
			}
			indexToSearchLooser--;
		}

	}
}
