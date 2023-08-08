#include "SortingAlgorithms.h"


#include <iostream>

void SortingAlgorithms::Sort(std::vector<Element>& array, SortingAlgorithm algorithm)
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



void MergeElements(std::vector<Element>& arr, int32_t left, int32_t mid, int32_t right)
{
	int32_t n1 = mid - left + 1;
	int32_t n2 = right - mid;

	std::vector<int32_t> leftArr(n1);
	std::vector<int32_t> rightArr(n2);

	// Copy data to temporary arrays
	for (int32_t i = 0; i < n1; ++i)
	{
		leftArr[i] = arr[left + i].GetValue();
	}
	for (int32_t j = 0; j < n2; ++j)
	{

		rightArr[j] = arr[mid + 1 + j].GetValue();
	}

	int32_t i = 0, j = 0, k = left;

	// Merge the two arrays
	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k].SetValue(leftArr[i]);
			++i;
		}
		else
		{
			arr[k].SetValue(rightArr[j]);
			++j;
		}
		++k;
	}

	// Copy remaining elements of leftArr, if any
	while (i < n1)
	{
		arr[k].SetValue(leftArr[i]);
		++i;
		++k;
	}

	// Copy remaining elements of rightArr, if any
	while (j < n2)
	{
		arr[k].SetValue(rightArr[j]);
		++j;
		++k;
	}
}

void SortingAlgorithms::MergeSort(std::vector<Element>& array, int32_t left, int32_t right)
{
	if (left < right)
	{
		int32_t mid = left + (right - left) / 2;

		// Recursively sort both halves
		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);

		// Merge the sorted halves
		MergeElements(array, left, mid, right);
	}
}

void SortingAlgorithms::SelectionSort(std::vector<Element>& array)
{
	int32_t n = (int32_t)array.size();

	for (int32_t i = 0; i < n - 1; ++i)
	{
		int32_t minIndex = i;
		for (int32_t j = i + 1; j < n; ++j)
		{
			if (array[j].GetValue() < array[minIndex].GetValue())
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


void SortingAlgorithms::BubbleSort(std::vector<Element>& array, int32_t& numComparisons)
{
	int32_t n = (int32_t)array.size();

	for (int32_t i = 0; i < n - 1; ++i) 
	{
		for (int32_t j = 0; j < n - i - 1; ++j) 
		{
			numComparisons++;
			if (array[j].GetValue() > array[j + 1].GetValue())
			{
				// Swap elements if they're out of order
				std::swap(array[j], array[j + 1]);
			}
		}
	}

};


// Helper function to find the maximum value in an array
int getMax(std::vector<Element>& array) {
	int32_t max = array[0].GetValue();
	for (int32_t i = 1; i < array.size(); ++i) 
	{
		if (array[i].GetValue() > max)
		{
			max = array[i].GetValue();
		}
	}
	return max;
}



void SortingAlgorithms :: RadixSort(std::vector<Element>& array)
{
	int32_t max = getMax(array);
	int32_t exp = 1; // Current digit being considered

	while (max / exp > 0) 
	{
		int32_t n = (int32_t)array.size();
		std::vector<int32_t> output(n);
		std::vector<int32_t> count(10, 0);

		// Count occurrences of each digit
		for (int32_t i = 0; i < n; ++i) 
		{
			count[(array[i].GetValue() / exp) % 10]++;
		}

		// Update count[i] to store the actual position of this digit in output[]
		for (int32_t i = 1; i < 10; ++i) 
		{
			count[i] += count[i - 1];
		}

		// Build the output array
		for (int32_t i = n - 1; i >= 0; --i) 
		{
			output[count[(array[i].GetValue() / exp) % 10] - 1] = array[i].GetValue();
			count[(array[i].GetValue() / exp) % 10]--;
		}

		// Copy the output array back to the original array
		for (int32_t i = 0; i < n; ++i) 
		{
			array[i].SetValue(output[i]);
		}

		exp *= 10; // Move to the next digit
	}

}


void SortingAlgorithms::ShellSort(std::vector <Element>& array, bool useKnuth) 
{
	int32_t n = (int32_t)array.size();

	int32_t gap;
	if (useKnuth) 
	{
		gap = 1;
		while (gap < n / 3) 
		{
			gap = 3 * gap + 1;
		}
	}
	else 
	{
		// Use a default gap sequence (e.g., gap = n / 2)
		gap = n / 2;
	}

	// Start with the chosen gap and reduce it on each iteration
	while (gap >= 1) 
	{
		for (int32_t i = gap; i < n; ++i) 
		{
			int32_t temp = array[i].GetValue();
			int32_t j;
			for (j = i; j >= gap && array[j - gap].GetValue() > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j].SetValue(temp);
		}
		if (useKnuth) 
		{
			gap /= 3;  // Reduce the gap according to the Knuth sequence
		}
		else 
		{
			gap /= 2;  // Reduce the gap using the default sequence
		}
	}

}


int32_t partition(std::vector<Element>& array, int32_t low, int32_t high) {
	int32_t pivot = array[high].GetValue();
	int32_t i = (low - 1);

	for (int32_t j = low; j <= high - 1; ++j) 
	{
		if (array[j].GetValue() < pivot) 
		{
			++i;
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i + 1], array[high]);
	return (i + 1);
}

void quickSortHelper(std::vector<Element>& array, int32_t low, int32_t high) {
	if (low < high) 
	{
		int32_t pi = partition(array, low, high);

		quickSortHelper(array, low, pi - 1);
		quickSortHelper(array, pi + 1, high);
	}
}

void SortingAlgorithms::QuickSort(std::vector<Element>& array)
{
	int32_t n = (int32_t)array.size();
	quickSortHelper(array, 0, n - 1);

}


void heapify(std::vector<Element>& array, int32_t n, int32_t i) 
{
	int32_t largest = i;
	int32_t left = 2 * i + 1;
	int32_t right = 2 * i + 2;

	if (left < n && array[left].GetValue() > array[largest].GetValue())
	{
		largest = left;
	}

	if (right < n && array[right].GetValue() > array[largest].GetValue())
	{
		largest = right;
	}

	if (largest != i) 
	{
		std::swap(array[i], array[largest]);
		heapify(array, n, largest);
	}
}

void SortingAlgorithms::HeapSort(std::vector<Element>& array)
{
	int32_t n = (int32_t)array.size();

	// Build max-heap
	for (int32_t i = n / 2 - 1; i >= 0; --i) 
	{
		heapify(array, n, i);
	}

	// Extract elements from heap one by one
	for (int32_t i = n - 1; i > 0; --i) 
	{
		std::swap(array[0], array[i]);
		heapify(array, i, 0);
	}

}

void SortingAlgorithms::BogoSort(std::vector<Element>& array) 
{
	



}

