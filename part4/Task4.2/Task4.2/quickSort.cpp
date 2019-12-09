#include "quickSort.h"

void swap(int* firstElement, int* secondElement)
{
	int tmp = *firstElement;

	*firstElement = *secondElement;
	*secondElement = tmp;
}

void insertionSort(int* array, int lo, int hi)
{
	for (int i = lo; i <= hi; i++)
	{
		for (int j = i; j > lo && array[j - 1] > array[j]; j--)
		{
			swap(&array[j - 1], &array[j]);
		}
	}
}

void quickSort(int* array, int lo, int hi)
{
	int sizeOfSortingPart = hi + 1 - lo;
	int supportingElement = array[(lo + hi + 1) / 2];
	int tail = hi;
	int begin = lo;

	if (sizeOfSortingPart < 2)
	{
		return;
	}
	if (sizeOfSortingPart < 10)
	{
		insertionSort(array, lo, hi);
		return;
	}
	while (lo <= hi)
	{
		while (array[lo] < supportingElement)
		{
			lo++;
		}
		while (array[hi] > supportingElement)
		{
			hi--;
		}
		if (lo <= hi)
		{
			if (lo != hi)
			{
				swap(&array[lo], &array[hi]);
			}
			lo++;
			hi--;
		}
	}
	quickSort(array, lo, tail);
	quickSort(array, begin, hi);
}