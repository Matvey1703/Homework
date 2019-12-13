#include <stdio.h>

#include "counter.h"

bool test()
{
	return counter(1, 1) == 1 && counter(5, 9) == 8 && counter(4, 15) == 13 && counter(7, 6) == 5;
}

int main()
{
	if (!test())
	{
		printf("Prodramm work incorrectly");
		return -1;
	}

	int n = 0;
	int m = 0;

	printf("input n: ");
	scanf_s("%i", &n);
	printf("input m: ");
	scanf_s("%i", &m); 

	printf("position k of the remaining warrior is %i", counter(m, n));

	return 0;
}