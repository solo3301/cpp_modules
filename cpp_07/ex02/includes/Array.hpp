#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <type_traits>

template <typename T>
class Array
{
public:
	Array();
	Array(size_t n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T& operator[](const size_t index);
	const T& operator[](const size_t index) const;
	size_t size() const;

private:
	T* _data;
	size_t _size;
};

#include "Array.tpp"

#endif


