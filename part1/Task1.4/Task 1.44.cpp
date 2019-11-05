#include <stdio.h>

int main()
{
	int sumsOfFigures[28] = {};
	int counter = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				sumsOfFigures[i + j + k]++;
			}
		}
	}
	for (int i = 0; i < 28; i++)
	{
		counter += sumsOfFigures[i] * sumsOfFigures[i];
	}
	printf("Quantity of happy tickets is %i", counter);
	return 0;
}