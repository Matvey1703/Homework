#include <stdio.h>

int findingFibonachiByRecursion(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return findingFibonachiByRecursion(n - 1) + findingFibonachiByRecursion(n - 2);
	}
}

int findingFibonachiByIteration(int n)
{
	int f[3] = {};

	f[0] = 1;
	f[1] = 1;
	for (int i = 0; i < n - 2; ++i)
	{
		f[2] = f[0] + f[1];
		f[0] = f[1];
		f[1] = f[2];
	}
	return f[2];
}


int main()
{
	int n = 0;
	int rec = 0;
	int iter = 0;

	printf("Put number of fibonachi: ");
	scanf_s("%i", &n);
	rec = findingFibonachiByRecursion(n);
	iter = findingFibonachiByIteration(n);
	printf("By recursion: %i\n", rec);
	printf("By iterative: %i\n", iter);
	return 0;
}