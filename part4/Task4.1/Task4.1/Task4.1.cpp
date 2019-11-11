#include <stdio.h>
#include <locale.h>

bool programmTest()
{
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

	int first_number = 0;
	int second_number = 0;

	printf("Ввведите первое число: ");
	scanf_s("%i", &first_number);
	printf("Введите второе число: ");
	scanf_s("%i", &second_number);

	printf("Первое число в дополнительном коде: ");
	printBinNumber();

	return 0;
}