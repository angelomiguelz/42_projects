#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <ctime>
#include <iomanip>

template <typename T>
void show(T c)
{
	typename T::iterator it;
	for (it = c.begin(); it != c.end(); it++)
		std::cout << "[" << *it << "]";
	std::cout << std::endl;
}

class PmergeMe
{
private:
	clock_t start;
	clock_t end;
	std::vector<int> vector;
	std::list<int> list;

public:
	// OCF
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const &o);
	PmergeMe &operator=(PmergeMe const &rhs);
	// member functions
	void init(char **values, int size);
	void sortV(std::vector<int> &v);
	void sortL(std::list<int> &l);
	void insertSortedList(std::list<int> &l, int element);
	void check();
};
bool isPositiveNumber(char *n);

#endif