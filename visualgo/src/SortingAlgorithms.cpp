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



void MergeElements(std::vector<int32_t>& arr, int left, int mid, int right)
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
		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);

		// Merge the sorted halves
		MergeElements(array, left, mid, right);
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


void SortingAlgorithms::BubbleSort(std::vector<int32_t>& array)
{
	int n = (int32_t)array.size();

	for (int i = 0; i < n - 1; ++i) 
	{
		for (int j = 0; j < n - i - 1; ++j) 
		{
			if (array[j] > array[j + 1]) 
			{
				// Swap elements if they're out of order
				std::swap(array[j], array[j + 1]);
			}
		}
	}

};


// Helper function to find the maximum value in an array
int getMax(const std::vector<int32_t>& array) {
	int max = array[0];
	for (int i = 1; i < array.size(); ++i) 
	{
		if (array[i] > max) 
		{
			max = array[i];
		}
	}
	return max;
}



void SortingAlgorithms :: RadixSort(std::vector<int32_t>& array)
{
	int max = getMax(array);
	int exp = 1; // Current digit being considered

	while (max / exp > 0) 
	{
		int n = (int32_t)array.size();
		std::vector<int32_t> output(n);
		std::vector<int32_t> count(10, 0);

		// Count occurrences of each digit
		for (int i = 0; i < n; ++i) 
		{
			count[(array[i] / exp) % 10]++;
		}

		// Update count[i] to store the actual position of this digit in output[]
		for (int i = 1; i < 10; ++i) 
		{
			count[i] += count[i - 1];
		}

		// Build the output array
		for (int i = n - 1; i >= 0; --i) 
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}

		// Copy the output array back to the original array
		for (int i = 0; i < n; ++i) 
		{
			array[i] = output[i];
		}

		exp *= 10; // Move to the next digit
	}

}


void SortingAlgorithms::ShellSort(std::vector <int32_t>& array, bool useKnuth) 
{
	int n = (int32_t)array.size();

	int gap;
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
		for (int i = gap; i < n; ++i) 
		{
			int temp = array[i];
			int j;
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap) 
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
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


int partition(std::vector<int32_t>& array, int low, int high) {
	int pivot = array[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; ++j) 
	{
		if (array[j] < pivot) 
		{
			++i;
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i + 1], array[high]);
	return (i + 1);
}

void quickSortHelper(std::vector<int32_t>& array, int low, int high) {
	if (low < high) 
	{
		int pi = partition(array, low, high);

		quickSortHelper(array, low, pi - 1);
		quickSortHelper(array, pi + 1, high);
	}
}

void SortingAlgorithms::QuickSort(std::vector<int32_t>& array)
{
	int n = array.size();
	quickSortHelper(array, 0, n - 1);

}


void heapify(std::vector<int32_t>& array, int n, int i) 
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest]) 
	{
		largest = left;
	}

	if (right < n && array[right] > array[largest]) 
	{
		largest = right;
	}

	if (largest != i) 
	{
		std::swap(array[i], array[largest]);
		heapify(array, n, largest);
	}
}

void SortingAlgorithms::HeapSort(std::vector<int32_t>& array)
{
	int n = (int32_t)array.size();

	// Build max-heap
	for (int i = n / 2 - 1; i >= 0; --i) 
	{
		heapify(array, n, i);
	}

	// Extract elements from heap one by one
	for (int i = n - 1; i > 0; --i) 
	{
		std::swap(array[0], array[i]);
		heapify(array, i, 0);
	}

}

