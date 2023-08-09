#pragma once

#include <vector>
#include "Element.h"
#include <random>
#include <algorithm>

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
	
	static void Sort(std::vector<Element>& array, SortingAlgorithm algorithm);
	static void MergeSort(std::vector<Element>& array, int32_t left, int32_t right);
	static void BubbleSort(std::vector<Element>& array, int32_t& numComparisons);
	static void RadixSort(std::vector<Element>& array);
	static void SelectionSort(std::vector<Element>& array);
	static void ShellSort(std::vector<Element>& array, bool useKnuth = true);
	static void QuickSort(std::vector<Element>& array);
	static void HeapSort(std::vector<Element>& array);
	static void BogoSort(std::vector<Element>& array);
};