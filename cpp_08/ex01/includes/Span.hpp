#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
public: 
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan() const;
	int longestSpan() const;
	void printNumbers() const;
	
private:
	std::vector<int> _numbers;
	unsigned int _maxSize;
};

#endif
