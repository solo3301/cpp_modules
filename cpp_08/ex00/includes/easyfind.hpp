#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
public:
	const char* what() const throw()
	{
		return "Error: Value not found in the container";
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"

#endif
