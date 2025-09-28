#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *array, int len, Func function)
{
	for (int i = 0; i < len; i++)
		function(array[i]);
}

// for testing
template <typename T>
void print(T *array, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << ", ";
}

#endif
