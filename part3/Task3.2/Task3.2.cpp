#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

bool isFound(int* array, int lo, int hi, int number)
{
	if (number < array[lo] || number > array[hi])
	{
		return false;
	}
	int middleElement = (lo + hi) / 2;
	int begin = lo;
	int tail = hi;

	if (hi == lo)
	{
		return (array[lo] == number);
	}
	if (hi - lo == 1)
	{
		return (number == array[lo] || number == array[hi]);
	}
	if (number == array[middleElement])
	{
		return true;
	}
	else if (number < array[middleElement])
	{
		isFound(array, lo, middleElement - 1, number);
	}
	else if (number > array[middleElement])
	{
		isFound(array, middleElement + 1, hi, number);
	}
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
	const int sizeArray3 = 10;
	int array1[1] = { 13 };
	int array2[2] = { 13, 25 };
	int array3[sizeArray3] = { 1, 3, 4, 6, 12, 13, 17, 22, 24, 30 };
	int number1 = 13;
	int number2 = 30;
	int number3 = 25;

	if (isFound(array1, 0, 0, number2) || (!isFound(array1, 0, 0, number1)))
	{
		return false;
	}
	if (isFound(array2, 0, 1, number2) || (!isFound(array2, 0, 1, number1)))
	{
		return false;
	}
	if ((!isFound(array3, 0, sizeArray3 - 1, number1)) || isFound(array3, 0, sizeArray3 - 1, number3))
	{
		return false;
	}
	if (!isFound(array3, 0, sizeArray3 - 1, number2))
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
	srand(time(nullptr));

	int n = 0;
	int k = 0;

	if (!programTest())
	{
		printf("Error in the algorithm. Correct your code and try again.");
		return -1;
	}
	printf("Input n: ");
	scanf_s("%i", &n);
	int* array = new int[n];
	fillByRand(array, n, 13, 43);
	printf("Input k: ");
	scanf_s("%i", &k);
	quickSort(array, 0, n - 1);
	if (!checkSort(array, n))
	{
		printf("Error in array sorting");
		return -1;
	}
	printf("Generated and sorted array of %i elements:\n", n);
	outputArray(array, n);
	printf("\n");
	for (int i = 0; i < k; i++)
	{
		int rndNumber = rndFromRange(13, 43);
		printf((isFound(array, 0, n - 1, rndNumber)) ? "%i contained in the array\n" : "%i not contained in the array\n", rndNumber);
	}
	delete[] array;

	return 0;
}