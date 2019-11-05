#include <stdio.h>
#include <math.h>

bool isPrime(int n)
{
	int sqr = (int)sqrt(n);
	int i = 2;

	if (n == 2)
	{
		return 1;
	}
	for (i = 2; i <= sqr; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return true;
}

int main()
{
	int n = 0;
	int i = 0;

	printf("Put number: ");
	scanf_s("%i", &n);
	printf("Prime numbers, that not bigger then %i: ", n);
	for (i = 2; i <= n; i++)
	{
		if (isPrime(i))
		{
			printf("%i ", i);
		}
	}
	return 0;
}