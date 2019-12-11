#include "test.h"

#include "postfixEvaluate.h"

bool toNumberTest()
{
	int arrayNumber1[5] = { 1, 9, 8, 9 };
	int arrayNumber2[1] = { 8 };
	int trueResult1 = 1989;
	int trueResult2 = 8;

	return !((toNumber(arrayNumber1, 4) != trueResult1 || toNumber(arrayNumber2, 1) != trueResult2));
}

bool evaluatorTest()
{
	char string1[14] = "9 6 - 1 2 + *";
	char string2[6] = "9 4 /";
	char string3[20] = "5 3 6 +  10 4 - * *";
	int trueResult1 = 9;
	int trueResult2 = 2;
	int trueResult3 = 270;

	return !(postfixExpressionEvaluator(string1) != trueResult1 
		|| postfixExpressionEvaluator(string2) != trueResult2 
		|| postfixExpressionEvaluator(string3) != trueResult3);
}

bool test()
{
	return evaluatorTest() && toNumberTest();
}