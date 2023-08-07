#pragma once

#include "SortingAlgorithms.h"
#include <iostream>

class Settings
{
private:
	int32_t m_NumberOfElements;

	SortingAlgorithm m_CurrentSortingAlgorithm;

public:

	Settings(int32_t numberOfElements, SortingAlgorithm algorithm);
	~Settings();

	int32_t GetNumberOfElements();

	SortingAlgorithm GetCurrentAlgorithm();

	void SetNumberOfElements(int32_t n);

	void SetAlgorithm(SortingAlgorithm algorithm);
};