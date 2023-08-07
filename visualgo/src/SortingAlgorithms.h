#pragma once

#include <vector>

enum SortingAlgorithm
{
	Merge,
	Bubble,
	Radix,
	Selection,
	Shell,
	Quick,
	Heap
};

class SortingAlgorithms
{
public:
	static void Sort(std::vector<int32_t> array, SortingAlgorithm algorithm);
	static void MergeSort(std::vector<int32_t>& array);
	static void BubbleSort(std::vector<int32_t> array);
	static void RadixSort(std::vector<int32_t> array);
	static void SelectionSort(std::vector<int32_t>& array);
	static void ShellSort(std::vector<int32_t> array);
	static void QuickSort(std::vector<int32_t> array);
	static void HeapSort(std::vector<int32_t> array);
};