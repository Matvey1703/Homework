#include <stdio.h>

int main()
{
	const int arraySize = 13;
	int array[arraySize] = {1, 5, 7, 0, 2, 0, 14, 56, 0, 0, 43, 9, 0};
	int counter = 0;

	for (int i = 0; i < arraySize; ++i)
	{
		if (array[i] == 0)
		{
			counter++;
		}
	}
	printf("Quantity of zero-elements is %i", counter);
	return 0;
}