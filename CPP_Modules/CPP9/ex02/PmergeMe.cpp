#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &o) { *this = o; }
PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->vector = rhs.vector;
		this->list = rhs.list;
		this->start = rhs.start;
		this->end = rhs.end;
	}
	return *this;
}

bool isPositiveNumber(char *n)
{
	for (int i = 0; n[i]; i++)
	{
		if (i == 0 && n[i] == '+' && n[i + 1] != '\0')
			continue;
		if (!isdigit(n[i]))
			return false;
	}
	return true;
}

// Binary search insertion
void insertVector(std::vector<int> &v, int element)
{
	int left = 0;
	int right = v.size();

	while (left < right)
	{
		int mid = (left + right) / 2;
		if (v[mid] > element)
			right = mid;
		else
			left = mid + 1;
	}
	v.insert(v.begin() + left, element);
}

void insertList(std::list<int> &l, int element)
{
	std::list<int>::iterator it = l.begin();
	while (it != l.end() && *it < element)
		++it;
	l.insert(it, element);
}

std::vector<size_t> jacobsthalSequence(size_t size)
{
	std::vector<size_t> sequence;
	if (size <= 1)
		return sequence;
	sequence.push_back(1); // Always insert position 1 first
	size_t curr = 3;	   // Start with 3 (next Jacobsthal number)
	size_t prev = 1;	   // Previous Jacobsthal number

	while (curr < size)
	{
		// Add current Jacobsthal number
		sequence.push_back(curr);
		// Add intermediate values in reverse order
		for (size_t i = curr - 1; i > prev; i--)
			sequence.push_back(i);
		// Calculate next Jacobsthal number
		size_t next = curr * 2 - prev;
		prev = curr;
		curr = next;
	}
	// Add any remaining positions
	for (size_t i = curr - 1; i < size; ++i)
		if (i > prev)
			sequence.push_back(i);
	return sequence;
}

void PmergeMe::sortV(std::vector<int> &v)
{
	if (v.size() <= 1)
		return;

	std::vector<int> main, pend;
	int unsorted = -1;

	for (size_t i = 0; i < v.size() - 1; i += 2)
	{
		if (v[i] > v[i + 1])
		{
			main.push_back(v[i]);
			pend.push_back(v[i + 1]);
		}
		else
		{
			main.push_back(v[i + 1]);
			pend.push_back(v[i]);
		}
	}

	if (v.size() % 2)
		unsorted = v.back();

	sortV(main);
	v = main;
	if (!pend.empty())
	{
		insertVector(v, pend[0]);
		std::vector<size_t> seq = jacobsthalSequence(pend.size());
		for (size_t i = 0; i < seq.size(); i++)
			insertVector(v, pend[seq[i]]);
	}
	if (unsorted != -1)
		insertVector(v, unsorted);
}

void PmergeMe::sortL(std::list<int> &lst)
{
	if (lst.size() <= 1)
		return;
	std::list<int> main, pend;
	int first, second;
	int unsorted = -1;
	while (lst.size() >= 2)
	{
		first = lst.front();
		lst.pop_front();
		second = lst.front();
		lst.pop_front();

		if (first > second)
		{
			main.push_back(first);
			pend.push_back(second);
		}
		else
		{
			main.push_back(second);
			pend.push_back(first);
		}
	}
	if (!lst.empty())
	{
		unsorted = lst.front();
		lst.pop_front();
	}
	sortL(main);
	lst = main;
	if (!pend.empty())
	{
		std::vector<int> pend_vec(pend.begin(), pend.end());
		insertList(lst, pend_vec[0]);
		std::vector<size_t> seq = jacobsthalSequence(pend_vec.size());
		for (size_t i = 0; i < seq.size(); i++)
			insertList(lst, pend_vec[seq[i]]);
	}
	if (unsorted != -1)
		insertList(lst, unsorted);
}

void PmergeMe::init(char **values, int size)
{
	for (int i = 1; i < size; i++)
	{
		if (!isPositiveNumber(values[i]))
			throw std::runtime_error("Error: invalid input");
		vector.push_back(std::atoi(values[i]));
		list.push_back(std::atoi(values[i]));
	}

	std::cout << "Before: ";
	show(vector);

	start = clock();
	std::cout << std::endl
			  << "DEBUG: sort vector: " << vector.size() << std::endl;
	sortV(vector);
	// return;
	std::cout << std::endl
			  << "DEBUG: sort vector: " << vector.size() << std::endl;
	end = clock();

	std::cout << "After:  ";
	show(vector);
	double v_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << v_time << " ms" << std::endl;
	std::cout << "Before: ";
	show(list);

	start = clock();
	std::cout << std::endl
			  << "DEBUG: sort list: " << list.size() << std::endl;
	sortL(list);
	end = clock();

	std::cout << std::endl
			  << "DEBUG: sort list: " << list.size() << std::endl;
	std::cout << "After:  ";
	show(list);
	double l_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << l_time << " ms" << std::endl;
}

void PmergeMe::check()
{
	if (!std::is_sorted(vector.begin(), vector.end()))
		throw std::runtime_error("Vector is not sorted correctly");
	if (!std::is_sorted(list.begin(), list.end()))
		throw std::runtime_error("List is not sorted correctly");
	std::cout << "----->OK<-----" << std::endl;
}