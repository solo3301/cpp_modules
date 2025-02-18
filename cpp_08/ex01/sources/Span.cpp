#include "../includes/Span.hpp"

Span::Span() : _maxSize(0)
{ }

Span::Span(unsigned int N) : _maxSize(N)
{ }

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize)
{ }

Span& Span::operator=(const Span& other)
{
    if (this != &other) 
	{
		_numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span()
{ }

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::overflow_error("Span is full");
	_numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _maxSize)
		throw std::overflow_error("Not enough space to add these numbers!");
	_numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span.");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; i++)
	{
		int diff = sorted[i + 1] - sorted[i];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span.");

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
	return maxVal - minVal;
}

void Span::printNumbers() const
{
	std::cout << "Numbers: ";
	for (size_t i = 0; i < _numbers.size(); i++)
		std::cout << _numbers[i] << " ";
	std::cout << std::endl;
}
