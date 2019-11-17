#include <stdio.h>
#include <stdlib.h>

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

bool checkSort(int* array, int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			return false;
		}
	}
	return true;
}

int finderOfMostFrequentElement(int* array, int arraySize)
{
	int counter = 1;
	int mostFrequentElement = 0;
	int maxQuantity = 0;

	if (arraySize < 3)
	{
		return array[0];
	}

	quickSort(array, 0, arraySize - 1);

	if (!checkSort(array, arraySize))
	{
		return -1;
	}
	for (int i = 0; i < arraySize - 1; i++)
	{
		if (array[i] == array[i + 1])
		{
			counter++;
		}
		else
		{
			if (counter > maxQuantity)
			{
				maxQuantity = counter;
				mostFrequentElement = array[i];
			}
			counter = 1;
		}
		if (i == arraySize - 2 && counter > maxQuantity)
		{
			mostFrequentElement = array[i];
		}
	}
	return mostFrequentElement;
}

bool programTest()
{
	const int arraySize = 10;
	int array1[arraySize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int array2[arraySize] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 4 };
	int array3[arraySize] = { 1, 3, 3, 6, 12, 13, 13, 13, 24, 30 };
	int array4[arraySize] = { 2, 2, 3, 4, 5, 6, 7, 9, 9, 9 };
	int array5[1] = { 13 };
	int mostFrequentElement1 = 1;
	int mostFrequentElement2 = 1;
	int mostFrequentElement3 = 13;
	int mostFrequentElement4 = 9;
	if (finderOfMostFrequentElement(array1, arraySize) != mostFrequentElement1)
	{
		return false;
	}
	if (finderOfMostFrequentElement(array2, arraySize) != mostFrequentElement2)
	{
		return false;
	}
	if (finderOfMostFrequentElement(array3, arraySize) != mostFrequentElement3)
	{
		return false;
	}
	if (finderOfMostFrequentElement(array4, arraySize) != mostFrequentElement4)
	{
		return false;
	}
	if (finderOfMostFrequentElement(array5, 1) != 13)
	{
		return false;
	}
	return true;
}

void outputArray(int* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%i\n", array[i]);
	}
}

int rndFromRange(int rangeBegin = 5, int rangeEnd = 15)
{
	return rand() % (rangeEnd - rangeBegin + 1) + rangeBegin;
}


void fillByRand(int* array, int arraySize, int rangeBegin = 5, int rangeEnd = 15)
{
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rndFromRange(rangeBegin, rangeEnd);
	}
}

int main()
{
	int arraySize = 0;

	if (!programTest())
	{
		return -1;
	}
	printf("Input array size: ");
	scanf_s("%i", &arraySize);
	int* array = new int[arraySize];
	fillByRand(array, arraySize, 13, 18 + arraySize);
	printf("Most frequent element is %i\n", finderOfMostFrequentElement(array, arraySize));
	printf("Sorted array: \n");
	outputArray(array, arraySize);
	delete[] array;
	return 0;
}