#include "Settings.h"

Settings::Settings(int32_t numberOfElements, SortingAlgorithm algorithm)
	:m_NumberOfElements(numberOfElements), m_CurrentSortingAlgorithm(algorithm) { }

Settings::~Settings() { }

int32_t Settings::GetNumberOfElements()
{
	return m_NumberOfElements;
}

SortingAlgorithm Settings::GetCurrentAlgorithm()
{
	return m_CurrentSortingAlgorithm;
}

void Settings::SetNumberOfElements(int32_t n)
{
	m_NumberOfElements = n;
}

void Settings::SetAlgorithm(SortingAlgorithm algorithm)
{
	m_CurrentSortingAlgorithm = algorithm;
}