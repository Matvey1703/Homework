#include <stdio.h>

int main(void)
{
	float x, a;

	printf("input x: ");
	scanf_s("%f", &x);
	a = x * x;
	printf("formula value is %f", (a + 1) * (a + x) + 1);
	return 0;
}