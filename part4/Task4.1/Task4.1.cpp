#include <stdio.h>
#include <locale.h>

const int numberSize = 11;

void printBinNumber(bool* binNumber)
{
	int i = 0;

	while (i < numberSize - 1 && !binNumber[i])
	{
		i++;
	}
	while (i < numberSize)
	{
		if (binNumber[i])
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
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
		(number & bit) ? binNumber[i] = true : binNumber[i] = false;
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
	bool binNumber1[numberSize] = { false, false, false, false, false, true, false, true, true, false, true };
	bool binNumber2[numberSize] = { false, false, true, false, true, false, false, true, true, true, true };
	bool binNumber3[numberSize] = { false, true, true, true, true, true, true, true, true, true, true };
	bool binNumber4[numberSize] = {};
	int decNumber1 = 45;
	int decNumber2 = 335;
	int decNumber3 = 1023;
	int decNumber4 = 0;
	bool binNumberArray1[numberSize] = {};
	bool binNumberArray2[numberSize] = {};
	bool binNumberArray3[numberSize] = {};
	bool binNumberArray4[numberSize] = {};
	bool binSum12[numberSize] = {};
	bool binSum14[numberSize] = {};
	bool binSum23[numberSize] = {};
	int decSum12 = 380;
	int decSum14 = 45;
	int decSum23 = 1358;

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

<<<<<<< HEAD
    bool binNumber1[numberSize] = {};
=======
	bool binNumber1[numberSize] = {};
>>>>>>> 3c52b197cf83faca3878ade6dc81adcc3c7057cb
	bool binNumber2[numberSize] = {};
	bool binSum[numberSize] = {};
	int firstNumber = 0;
	int secondNumber = 0;

	printf("Введите первое число (меньше 1024): ");
	scanf_s("%i", &firstNumber);
	printf("Введите второе число (меньше 1024): ");
	scanf_s("%i", &secondNumber);
	if (firstNumber > 1023 || secondNumber > 1023)
	{
		printf("Введите числа не больше 1023!!!");
	}

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