#include "SortingAlgorithms.h"

#include <iostream>

void SortingAlgorithms::Sort(std::vector<int32_t> array, SortingAlgorithm algorithm)
{

	switch (algorithm)
	{
	case Bubble:
		break;

	case Merge:
		break;

	case Selection:
		break;

	case Radix:
		break;

	case Shell:
		break;

	case Quick:
		break;

	case Heap:
		break;
	}
}



void Merge(std::vector<int32_t>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int32_t> leftArr(n1);
	std::vector<int32_t> rightArr(n2);

	// Copy data to temporary arrays
	for (int i = 0; i < n1; ++i)
	{
		leftArr[i] = arr[left + i];
	}
	for (int j = 0; j < n2; ++j)
	{

		rightArr[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = left;

	// Merge the two arrays
	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			++i;
		}
		else
		{
			arr[k] = rightArr[j];
			++j;
		}
		++k;
	}

	// Copy remaining elements of leftArr, if any
	while (i < n1)
	{
		arr[k] = leftArr[i];
		++i;
		++k;
	}

	// Copy remaining elements of rightArr, if any
	while (j < n2)
	{
		arr[k] = rightArr[j];
		++j;
		++k;
	}
}

void SortingAlgorithms::MergeSort(std::vector<int32_t>& array, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		// Recursively sort both halves
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// Merge the sorted halves
		Merge(arr, left, mid, right);
	}
}

void SortingAlgorithms::SelectionSort(std::vector<int32_t>& array)
{
	int n = (int32_t)array.size();

	for (int i = 0; i < n - 1; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			std::swap(array[i], array[minIndex]);
		}
	}
};

