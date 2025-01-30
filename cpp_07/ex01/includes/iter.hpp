#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, size_t len, void (*func)(T&))
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
void print(T& value)
{
	std::cout << value << " ";
}

template <typename T>
void increment(T& value)
{
	value++;
}

void makeUppercase(char& c)
{
	if (std::islower(c))
		c = std::toupper(c);
}

#endif
