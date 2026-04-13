#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _dequeLeftover(-1), _listLeftover(-1) {}

PmergeMe::PmergeMe(const PmergeMe& copy) :
_deque(copy._deque), _list(copy._list), _dequePairs(copy._dequePairs), _listPairs(copy._listPairs),
_dequeLeftover(copy._dequeLeftover), _listLeftover(copy._listLeftover), _jacobDeque(copy._jacobDeque),
_jacobList(copy._jacobList), _startTimeDeque(copy._startTimeDeque),
_endTimeDeque(copy._endTimeDeque), _endTimeList(copy._endTimeList), _startTimeList(copy._startTimeList) {}
	
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
		_jacobDeque = copy._jacobDeque;
		_jacobList = copy._jacobList;
		_startTimeDeque = copy._startTimeDeque;
		_endTimeDeque = copy._endTimeDeque;
		_endTimeList = copy._endTimeList;
		_startTimeList = copy._startTimeList;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArgsDeque(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string arg = av[i];

		//check empty string
		if (arg.empty())
			throw NotANumberException();

		//check if it is digit
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!std::isdigit(arg[j]) && arg[j] != '+' && arg[j] != '-')
				throw NotANumberException();
			if ((arg[j] == '+' && j != 0) || (arg[j] == '+' && arg.length() == 1))
				throw NotANumberException();
			if ((arg[j] == '-' && j != 0) || (arg[j] == '-' && arg.length() == 1))
				throw NotANumberException();
		}

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

		_deque.push_back(number);
	}
}

void PmergeMe::parseArgsList(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string arg = av[i];

		//check empty string
		if (arg.empty())
			throw NotANumberException();

		//check if it is digit
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!std::isdigit(arg[j]) && arg[j] != '+' && arg[j] != '-')
				throw NotANumberException();
			if ((arg[j] == '+' && j != 0) || (arg[j] == '+' && arg.length() == 1))
				throw NotANumberException();
			if ((arg[j] == '-' && j != 0) || (arg[j] == '-' && arg.length() == 1))
				throw NotANumberException();
		}

		//check positive integer limits
		long number = std::atol(av[i]);
		if (number < 0)
			throw NegativeNumberException();
		if (number > INT_MAX)
			throw MaxNumberException();

		//check if it is a duplicate
		for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
		{
			if (*it == number)
				throw DuplicateNumberException();
		}

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

void PmergeMe::processAlgorithm(int ac, char **av)
{
	//algorithm with deque
	_startTimeDeque = getCurrentTime();
	parseArgsDeque(ac, av);
	printNumbers("Before: ");
	groupPairsDeque();
	orderDequeWinners(_dequePairs);
	generateJacobsthalNumbersDeque();
	if (_jacobDeque.empty())
		return;
	insertDequeLosers();
	_endTimeDeque = getCurrentTime();
	
	//algorithm with list
	_startTimeList = getCurrentTime();
	parseArgsList(ac, av);
	groupPairsList();
	orderListWinners(_listPairs);
	generateJacobsthalNumbersList();
	if (_jacobList.empty())
		return;
	insertListLosers();
	printNumbers("After: ");
	_endTimeList = getCurrentTime();

	printTimeIntervals();
}

void PmergeMe::groupPairsDeque()
{
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
}


void PmergeMe::groupPairsList()
{
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

void PmergeMe::generateJacobsthalNumbersDeque()
{
	_jacobDeque.clear();
	int _loosersSize = 0;

	if (_dequeLeftover >= 0)
		_loosersSize = 1;
	_loosersSize += (int)_dequePairs.size();

	//push the first two jacobsthal numbers
	_jacobDeque.push_back(0);
	_jacobDeque.push_back(1);

	int i = 2;
	while (_jacobDeque.back() < _loosersSize)
	{
		int nextNumber = _jacobDeque[i - 1] + 2 * (_jacobDeque[i - 2]);
		_jacobDeque.push_back(nextNumber);
		i++;
	}
}

void PmergeMe::generateJacobsthalNumbersList()
{
	_jacobList.clear();
	int _loosersSize = 0;

	if (_listLeftover >= 0)
		_loosersSize = 1;
	_loosersSize += (int)_listPairs.size();

	//push the first two jacobsthal numbers
	_jacobList.push_back(0);
	_jacobList.push_back(1);

	int i = 2;
	while (_jacobList.back() < _loosersSize)
	{
		int nextNumber = _jacobList[i - 1] + 2 * (_jacobList[i - 2]);
		_jacobList.push_back(nextNumber);
		i++;
	}
}

void PmergeMe::insertDequeLosers()
{
	_deque.clear();

	//if the input is only 1 number, dequePairs would be empty:
	if (_dequePairs.empty())
	{
		if (_dequeLeftover != -1)
			_deque.push_back(_dequeLeftover);
		return;
	}

	//push just the winners to the _deque chain
	for (std::deque<std::pair<int, int> >::iterator it = _dequePairs.begin(); it != _dequePairs.end(); ++it)
		_deque.push_back(it->first);

	//insert the first looser (guaranteed it is the lowest number, so we reduce the number of comparisons by doing this)
	_deque.insert(_deque.begin(), _dequePairs[0].second);

	std::vector<int>::iterator jacobIt = _jacobDeque.begin();
	//jump until *jacobIt > 1 because we already handled the index 0
	while (jacobIt != _jacobDeque.end() && *jacobIt <= 1)
		jacobIt++;
	
	//loop to insert the loosers
	int lastIndexToSearchLooser = 1;
	while (jacobIt != _jacobDeque.end())
	{
		int indexToSearchLooser = *jacobIt;

		//defining the startIndex for the loosers insertion
		int startIndex = indexToSearchLooser - 1; //because indexes start at 0
		if (startIndex >= (int)_dequePairs.size()) //if startIndex goes out of bounds of the loosers
			startIndex = (int)_dequePairs.size() - 1;

		while (startIndex >= lastIndexToSearchLooser)
		{
			int looserToInsert = _dequePairs[startIndex].second;
			int winnerToFind = _dequePairs[startIndex].first;
			//to find the position of the winner that belongs to the looser
			std::deque<int>::iterator limit = std::find(_deque.begin(), _deque.end(), winnerToFind);
			//insertion search will now be made until this boundary
			_deque.insert(std::lower_bound(_deque.begin(), limit, looserToInsert), looserToInsert);
			startIndex--;
		}
		jacobIt++;
		lastIndexToSearchLooser = indexToSearchLooser;
	}

//if the numbers were odd numbered, we insert here that last saved number
if (_dequeLeftover != -1)
	_deque.insert(std::lower_bound(_deque.begin(), _deque.end(), _dequeLeftover), _dequeLeftover);
}

void PmergeMe::insertListLosers()
{
	_list.clear();

	if (_listPairs.empty())
	{
		if (_listLeftover != -1)
			_list.push_back(_listLeftover);
		return;
	}

	//push just the winners to the _deque chain
	for (std::list<std::pair<int, int> >::iterator it = _listPairs.begin(); it != _listPairs.end(); ++it)
		_list.push_back(it->first);

	//insert the first looser (guaranteed it is the lowest number, so we reduce the number of comparisons by doing this)
	std::list<std::pair<int, int> >::iterator pairIt = _listPairs.begin();
	_list.insert(_list.begin(), pairIt->second);

	std::vector<int>::iterator jacobIt = _jacobList.begin();
	//jump until *jacobIt > 1 because we already handled the index 0
	while (jacobIt != _jacobList.end() && *jacobIt <= 1)
		jacobIt++;
	
	//loop to insert the loosers
	int lastIndexToSearchLooser = 1;
	while (jacobIt != _jacobList.end())
	{
		int indexToSearchLooser = *jacobIt;

		//defining the startIndex for the loosers insertion
		int startIndex = indexToSearchLooser - 1; //because indexes start at 0
		if (startIndex >= (int)_listPairs.size()) //if startIndex goes out of bounds of the loosers
			startIndex = (int)_listPairs.size() - 1;

		while (startIndex >= lastIndexToSearchLooser)
		{
			//move the pairIt to the beginning so it can advance to the right index next
			pairIt = _listPairs.begin();
			std::advance(pairIt, startIndex);
			int looserToInsert = pairIt->second;
			int winnerToFind = pairIt->first;
			//to find the position of the winner that belongs to the looser
			std::list<int>::iterator limit = std::find(_list.begin(), _list.end(), winnerToFind);
			//insertion search will now be made until this boundary
			_list.insert(std::lower_bound(_list.begin(), limit, looserToInsert), looserToInsert);
			startIndex--;
		}
		jacobIt++;
		lastIndexToSearchLooser = indexToSearchLooser;
	}

//if the numbers were odd numbered, we insert here that last saved number
	if (_listLeftover != -1)
		_list.insert(std::lower_bound(_list.begin(), _list.end(), _listLeftover), _listLeftover);
}

long long PmergeMe::getCurrentTime() const
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (static_cast<long long>(tv.tv_sec) * 1000000) + tv.tv_usec; //this will give the time in microseconds
}

void PmergeMe::printTimeIntervals() const
{
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : "
	<< _endTimeDeque - _startTimeDeque << " us" << std::endl;

	std::cout << "Time to process a range of " << _list.size() << " elements with std::list : "
	<< _endTimeList - _startTimeList << " us" << std::endl;
}

