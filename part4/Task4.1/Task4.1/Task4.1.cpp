#include <stdio.h>
#include <locale.h>

const int numberSize = sizeof(int) * 8;

void printBinNumber(bool* binNumber)
{
	int i = 0;

	while (i < numberSize - 1 && !binNumber[i])
	{
		i++;
	}
	while (i < numberSize)
	{
		printf(binNumber[i] ? "1" : "0");
		i++;
	}
	printf("\n");
}

void binaryAddition(bool* binNumber1, bool* binNumber2, bool* binSum)
{
	bool balance = false;
	for (int i = numberSize - 1; i >= 0; i--)
	{
		if ((binNumber1[i] && binNumber2[i] && balance) || (binNumber1[i] && !binNumber2[i] && !balance) || (!binNumber1[i] && binNumber2[i] && !balance))
		{
			binSum[i] = true;
		}
		if ((binNumber1[i] && binNumber2[i] && !balance) || (binNumber1[i] && !binNumber2[i] && balance) || (!binNumber1[i] && binNumber2[i] && balance))
		{
			binSum[i] = false;
			balance = true;
		}
		if (!binNumber1[i] && !binNumber2[i] && balance)
		{
			binSum[i] = true;
			balance = false;
		}
	}
}

void binaryConversion(int number, bool* binNumber)
{
	int bit = 1;

	for (int i = numberSize - 1; i >= 0; i--)
	{
		binNumber[i] = number & bit;
		bit <<= 1;
	}
}

int decimalConversion(bool* binNumber)
{
	int decimalNumber = 0;
	int bit = 1;

	for (int i = numberSize - 1; i >= 0; i--)
	{
		if (binNumber[i])
		{
			decimalNumber += bit;
		}
		bit *= 2;
	}
	return decimalNumber;
}

bool arrayComparison(bool* array1, bool* array2, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (array1[i] ^ array2[i])
		{
			return false;
		}
	}
	return true;
}


bool programmTest()
{
	bool binNumber1[numberSize] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0 };
	bool binNumber2[numberSize] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1 };
	bool binNumber3[numberSize] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	bool binNumber4[numberSize] = {};
	int decNumber1 = -812;
	int decNumber2 = 1703;
	int decNumber3 = -1;
	int decNumber4 = 0;
	bool binNumberArray1[numberSize] = {};
	bool binNumberArray2[numberSize] = {};
	bool binNumberArray3[numberSize] = {};
	bool binNumberArray4[numberSize] = {};
	bool binSum12[numberSize] = {};
	bool binSum14[numberSize] = {};
	bool binSum23[numberSize] = {};
	int decSum12 = 891;
	int decSum14 = -812;
	int decSum23 = 1702;

	binaryConversion(decNumber1, binNumberArray1);
	binaryConversion(decNumber2, binNumberArray2);
	binaryConversion(decNumber3, binNumberArray3);
	binaryConversion(decNumber4, binNumberArray4);

	if (!arrayComparison(binNumber1, binNumberArray1, numberSize))
	{
		return false;
	}
	if (!arrayComparison(binNumber2, binNumberArray2, numberSize))
	{
		return false;
	}
	if (!arrayComparison(binNumber3, binNumberArray3, numberSize))
	{
		return false;
	}
	if (!arrayComparison(binNumber4, binNumberArray4, numberSize))
	{
		return false;
	}

	if (decimalConversion(binNumber1) != decNumber1)
	{
		return false;
	}
	if (decimalConversion(binNumber2) != decNumber2)
	{
		return false;
	}
	if (decimalConversion(binNumber3) != decNumber3)
	{
		return false;
	}
	if (decimalConversion(binNumber4) != decNumber4)
	{
		return false;
	}
	binaryAddition(binNumber1, binNumber2, binSum12);
	binaryAddition(binNumber1, binNumber4, binSum14);
	binaryAddition(binNumber2, binNumber3, binSum23);
	if (decimalConversion(binSum12) != decSum12)
	{
		return false;
	}
	if (decimalConversion(binSum14) != decSum14)
	{
		return false;
	}
	if (decimalConversion(binSum23) != decSum23)
	{
		return false;
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

    if (!programmTest())
	{
		printf("Ошибка в коде, программа не проходит тест");
		return -1;
	} 
	bool binNumber1[numberSize] = {};
	bool binNumber2[numberSize] = {};
	bool binSum[numberSize] = {};
	int firstNumber = 0;
	int secondNumber = 0;

	printf("Введите первое число: ");
	scanf_s("%i", &firstNumber);
	printf("Введите второе число: ");
	scanf_s("%i", &secondNumber);
	binaryConversion(firstNumber, binNumber1);
	binaryConversion(secondNumber, binNumber2);
	printf("Первое число в двоичном коде: ");
	printBinNumber(binNumber1);
	printf("\n");
	printf("Второе число в двоичном коде: ");
	printBinNumber(binNumber2);
	printf("\n");
	binaryAddition(binNumber1, binNumber2, binSum);
	printf("Сумма чисел в двоичном коде: ");
	printBinNumber(binSum);
	printf("\n");
	printf("Сумма чисел в десятичном виде: %i", decimalConversion(binSum));

	return 0;
}