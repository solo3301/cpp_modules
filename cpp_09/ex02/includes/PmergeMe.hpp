#ifndef PmergeMe_hpp
#define PmergeMe_hpp

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <exception>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void sortAndMeasure(std::vector<int>& vec);
	void sortAndMeasure(std::deque<int>& deq);
	void printDurations(std::vector<int>& vec, std::deque<int>& deq);

private:
	double _durationVec;
	double _durationDeq;
	void mergeInsertionSort(std::vector<int>& vec);
	void mergeInsertionSort(std::deque<int>& deq);
	template <typename T>
	void mergeInsertionSortHelper(T& container, int left, int right);
	template <typename T>
	void merge(T& container, int left, int mid, int right);
};

#endif
