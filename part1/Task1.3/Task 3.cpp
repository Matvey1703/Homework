#include <stdio.h>

int* arrayFlip(int* array, int firstElement, int lastElement)
{
	for (int i = firstElement; i < (firstElement + lastElement + 1) / 2; ++i)
	{
		int tmp = array[i];
		array[i] = array[lastElement + firstElement - i];
		array[lastElement + firstElement - i] = tmp;
	}
	return array;
}

int main()
{
	const int m = 3;
	const int n = 5;
	const int arraySize = m + n;
	int a[arraySize] = {};

	printf("put into array %i elements: \n", arraySize);
	for (int i = 0; i < m + n; ++i)
	{
		scanf_s("%i", &a[i]);
	}
	arrayFlip(a, 0, m - 1);
	arrayFlip(a, m, m + n - 1);
	arrayFlip(a, 0, m + n - 1);
	for (int i = 0; i < arraySize; ++i)
	{
		printf("%i ", a[i]);
	}
	return 0;
}