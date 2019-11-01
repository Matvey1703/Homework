#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
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

bool arrayComparison(int* array1, int* array2, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (array1[i] != array2[i])
		{
			return false;
		}
	}
	return true;
}

bool programTest()
{
	int unsortedArray1[10] = { -2, 6, 3, 7, 4, -10, 9, 8, 1, 5 };
	int unsortedArray2[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int unsortedArray3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int singletoneArray[1] = { -213 };
	int singletoneArrayValue = singletoneArray[0];
	int sortedArray1[10] = { -10, -2, 1, 3, 4, 5, 6, 7, 8, 9 };
	int sortedArray23[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arraySize = 10;

	quickSort(singletoneArray, 0, 0);
	quickSort(unsortedArray1, 0, arraySize - 1);                  
	quickSort(unsortedArray2, 0, arraySize - 1);
	quickSort(unsortedArray3, 0, arraySize - 1);
	if (!(arrayComparison(unsortedArray1, sortedArray1, arraySize) && arrayComparison(unsortedArray2, sortedArray23, arraySize) && arrayComparison(unsortedArray3, sortedArray23, arraySize)))
	{
		return false;
	}
	return (singletoneArray[0] == singletoneArrayValue);
}

void outputArray(int* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%i\n", array[i]);
	}
}

void fillByRand(int* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		int rnd = (int)rand();
		array[i] = rnd - 10000;
	}
}

int main()
{
	srand(time(nullptr));
	int arraySize = 0;

	if (!programTest())
	{
		printf("Error in the algorithm. Correct your code and try again.");
		return -1;
	}

	printf("Ipput attay's size: ");
	scanf_s("%i", &arraySize);
	int* array = new int[arraySize];
	fillByRand(array, arraySize);
	printf("Array before sotring:\n");
	outputArray(array, arraySize);
	quickSort(array, 0, arraySize - 1);
	printf("Array sorted by quick sort:\n");
	if (checkSort(array, arraySize))
	{
		outputArray(array, arraySize);
	}
	else
	{
		printf("array sorted incorrectly");
	}
	delete[] array;
	return 0;
}