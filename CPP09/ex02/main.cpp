#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: not enough arguments." << std::endl;
		return 1;
	}
	try
	{
		PmergeMe p;
		p.parseArgs(ac, av);
		p.processAlgorithm();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}