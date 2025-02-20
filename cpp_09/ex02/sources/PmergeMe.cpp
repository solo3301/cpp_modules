/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:17:14 by yadereve          #+#    #+#             */
/*   Updated: 2025/02/20 16:29:07 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() : _durationVec(0.0), _durationDeq(0.0)
{ }

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{ }

void PmergeMe::sortAndMeasure(std::vector<int>& vec)
{
	clock_t start = clock();
	mergeInsertionSort(vec);
	clock_t end = clock();
	_durationVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e3;
}

void PmergeMe::sortAndMeasure(std::deque<int>& deq)
{
	clock_t start = clock();
	mergeInsertionSort(deq);
	clock_t end = clock();
	_durationDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e3;
}

void PmergeMe::printDurations(std::vector<int>& vec, std::deque<int>& deq)
{
	std::cout << "Time to process " << vec.size() 
		<< " elements with std::vector:\t" << _durationVec << " ms\n";
	std::cout << "Time to process " << deq.size() 
		<< " elements with std::deque:\t" << _durationDeq << " ms\n";
}

void PmergeMe::mergeInsertionSort(std::vector<int>& vec)
{
	mergeInsertionSortHelper(vec, 0, vec.size() - 1);
}

void PmergeMe::mergeInsertionSort(std::deque<int>& deq)
{
	mergeInsertionSortHelper(deq, 0, deq.size() - 1);
}

template <typename T>
void PmergeMe::mergeInsertionSortHelper(T& container, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeInsertionSortHelper(container, left, mid);
	mergeInsertionSortHelper(container, mid + 1, right);
	merge(container, left, mid, right);
}

template <typename T>
void PmergeMe::merge(T& container, int left, int mid, int right)
{
	int leftSize = mid - left + 1;
	int rightSize = right - mid;
	T leftArr(leftSize);
	T rightArr(rightSize);
	for (int i = 0; i < leftSize; i++)
		leftArr[i] = container[left + i];
	for (int i = 0; i < rightSize; i++)
		rightArr[i] = container[mid + 1 + i];
	int i = 0, j = 0, k = left;
	while (i < leftSize && j < rightSize)
	{
		if (leftArr[i] <= rightArr[j])
		{
			container[k] = leftArr[i];
			i++;
		}
		else
		{
			container[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < leftSize)
	{
		container[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < rightSize)
	{
		container[k] = rightArr[j];
		j++;
		k++;
	}
}
