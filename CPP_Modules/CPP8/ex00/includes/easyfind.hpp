#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void easyfind(T &c, int find)
{
	if (std::find(c.begin(), c.end(), find) != c.end())
	{
		std::cout << "Found " << find << " in given container" << std::endl;
		return;
	}
	throw std::runtime_error("Element not found in given container");
}
#endif