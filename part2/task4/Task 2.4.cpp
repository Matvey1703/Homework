#include <stdio.h>
#include <stdlib.h>

int rndFromRange(int rangeBegin = 5, int rangeEnd = 15)
{
	return rand() % (rangeEnd - rangeBegin + 1) + rangeBegin;
}

void swap(int* A, int* B)
{
	int tmp = *A;

	*A = *B; 
	*B = tmp;
}

void outputArray(int* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%i ", array[i]);
	}
	printf("\n");
}

bool checkProcess(int* array, int arraySize, int firstElement)
{
	int i = 0;

	while (array[i] != firstElement)
	{
		if (array[i] > firstElement)
		{
			return false;
		}
		i++;
	}
	while (i < arraySize)
	{
		if (array[i] < firstElement)
		{
			return false;
		}
		i++;
	}
	return true;
}

void arrayProcessing(int* array, int arraySize)
{
	int lo = 1;
	int hi = arraySize - 1;

	if (!checkProcess(array, arraySize, array[0]) && arraySize > 1)
	{
		if (arraySize == 2)
		{
			if (array[0] <= array[1])
			{
				return;
			}
			else
			{
				swap(&array[0], &array[1]);
				return;
			}
		}
		while (hi >= lo)
		{
			while (array[hi] >= array[0] && hi >= lo && hi > 0)
			{
				hi--;
			}
			while (array[lo] < array[0] && lo <= hi && lo < arraySize)
			{
				lo++;
			}
			if (hi == 0 || lo == arraySize - 1)
			{
				break;
			}
			if (hi < lo)
			{
				break;
			}
			swap(&array[hi], &array[lo]);
			hi--;
			lo++;
		}
		if (array[hi] < array[0])
		{
			swap(&array[0], &array[hi]);
		}
		else
		{
			swap(&array[0], &array[lo]);
		}
	}
}


bool programTesting()
{
	int array1[13] = { 8, 13, 2, 1, 5, 3, 11, 7, 9, 4, 12, 6, 10 };
	int array2[13] = { 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int array3[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	int array4[13] = { 8, 13, 2, 1, 5, 8, 11, 7, 9, 4, 8, 6, 10 };
	int array5[13] = { 12, 1, 2, 3, 4, 5, 6, 7, 13, 8, 9, 10, 11 };
	int firstElement1 = array1[0];
	int firstElement2 = array2[0];
	int firstElement3 = array3[0];
	int firstElement4 = array4[0];
	int firstElement5 = array5[0];
	int arraySize = 13;

	arrayProcessing(array1, arraySize);
	arrayProcessing(array2, arraySize);
	arrayProcessing(array3, arraySize);
	arrayProcessing(array4, arraySize);
	arrayProcessing(array5, arraySize);
	if (!checkProcess(array1, arraySize, firstElement1))
	{
		return false;
	}
	if (!checkProcess(array2, arraySize, firstElement2))
	{
		return false;
	}
	if (!checkProcess(array3, arraySize, firstElement3))
	{
		return false;
	}
	if (!checkProcess(array4, arraySize, firstElement4))
	{
		return false;
	}
	if (!checkProcess(array5, arraySize, firstElement5))
	{
		return false;
	}
	return true;
}

void fillByRand(int* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rndFromRange(4, 54);
	}
}

int main()
{
	const int arraySize = 13;
	int array[arraySize] = {};
	int firstElement = 0;

	fillByRand(array, arraySize);
	firstElement = array[0];
	printf("Array before process:\n");
	outputArray(array, arraySize);
	arrayProcessing(array, arraySize);
	if (programTesting())
	{
		if (checkProcess(array, arraySize, firstElement))
		{
			printf("Processed array:\n");
			outputArray(array, arraySize);
		}
		else
		{
			printf("Array processed uncorrectly.");
		}
	}
	else
	{
		printf("Program work uncorrectly");
	}
	return 0;
}