#include <stdio.h>
#include <stdlib.h>

void swap(int* A, int* B)
{
	int tmp = *A;

	*A = *B;
	*B = tmp;
}

int maxElement(int* array, int arraySize)
{
	int max = array[0];

	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

int minElement(int* array, int arraySize)
{
	int min = array[0];

	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

void bubbleSort(int* array, int arraySize)
{
	for (int j = 0; j < arraySize - 1; j++)
	{
		for (int i = 0; i < arraySize - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
			}
		}
	}
}

void countingSort(int* array, int arraySize)
{
	int rangeOfValues = maxElement(array, arraySize) - minElement(array, arraySize) + 1;
	int *valuesArray = new int[rangeOfValues]();
	int step = 0;
	int k = 0;
	
	if (minElement(array, arraySize) < 0)
	{
		step = abs(minElement(array, arraySize));
	}
	else
	{
		step = -minElement(array, arraySize);
	}
	for (int i = 0; i < arraySize; i++)
	{
		valuesArray[array[i] + step]++;
	}
	
	for (int i = 0; i < rangeOfValues; i++)
	{
		for (int j = 0; j < valuesArray[i]; j++)
		{
			array[k] = i - step;
			k++;
		}
	}
	delete[] valuesArray;
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
	int unsortedArray2[10] = { -2, 6, 3, 7, 4, -10, 9, 8, 1, 5 };
	int singletoneArray1[1] = { -213 };
	int singletoneArray2[1] = { -213 };
	int singletoneArrayValue = singletoneArray1[0];
	int sortedArray[10] = { -10, -2, 1, 3, 4, 5, 6, 7, 8, 9 };
	int arraySize = 10;

	bubbleSort(singletoneArray1, 1);
	countingSort(singletoneArray2, 1);
	bubbleSort(unsortedArray1, arraySize);
	countingSort(unsortedArray2, arraySize);
	if (!(arrayComparison(unsortedArray1, sortedArray, arraySize) && arrayComparison(unsortedArray2, sortedArray, arraySize)))
	{
		return false;
	}
	if (singletoneArray1[0] != singletoneArrayValue || singletoneArray2[0] != singletoneArrayValue)
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

void fillByRand(int* array1, int* array2, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		int rnd = (int)rand();
		array1[i] = rnd - 10000;
		array2[i] = rnd - 10000;
	}
}

int main()
{
	int arraySize = 0;

	if (!programTest())
	{
		printf("Error in the algorithm. Correct your code and try again.");
	}
	else
	{
		printf("Ipput attay's size: ");
		scanf_s("%i", &arraySize);
		int* array1 = new int[arraySize];
		int* array2 = new int[arraySize];

		fillByRand(array1, array2, arraySize);
		bubbleSort(array1, arraySize);
		printf("Array sorted by Bubble sort:\n");
		if (checkSort(array1, arraySize))
		{
			outputArray(array1, arraySize);
		}
		else
		{
			printf("array sorted uncorrectly");
		}
		countingSort(array2, arraySize);
		printf("Array sorted by Counting sort:\n");
	    if (checkSort(array2, arraySize))
		{
			outputArray(array2, arraySize);
		}
		else
		{
			printf("array sorted uncorrectly");
		}
		delete[] array1;
		delete[] array2;
	}
	return 0;
}