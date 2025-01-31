#ifndef ARRAY_HPP
#define ARRAY_HPP


# include <iostream>		// For input and output stream
# include <string>			// For string class and functions
# include <cstring>			// For C-style string functions
# include <cmath>			// For common mathematical functions
# include <sstream>			// For string stream classes
# include <fstream>			// For file stream classes
# include <iomanip>			// For input/output manipulation
# include <exception>		// For standard exception classes
# include <stdexcept>		// For standard exception classes (runtime_error, etc.)
# include <limits>			// For numeric limits

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


