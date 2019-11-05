#include <iostream>

int main()
{
	const int sizeStringS = 11;
	const int sizeStringS1 = 4;
	char S[] = "hgfyriwhgf";
	char S1[] = "hgf";
	bool isSimilar = true;
	int counter = 0;
	int simCounter = 0;

	for (int i = 0; i < sizeStringS - sizeStringS1 + 1; i++)
	{
		while (counter < sizeStringS1 - 1 && isSimilar)
		{
			if (S[i + counter] != S1[counter])
			{
				isSimilar = false;
			}
			counter++;
		}
		if (isSimilar)
		{
			simCounter++;
		}
		counter = 0;
		isSimilar = true;
	}
	printf("Number of entries of substring S1 in string S is %i", simCounter);
	return 0;
}