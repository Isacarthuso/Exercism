#include "armstrong_numbers.h"
#include <stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define isArmtrongNumber( n, sum) (( sum == n ) ? 1 : 0)

struct ArmstrongNumbers
{
	int nalgorism;    //number of algorism in a given number
	int* ptrAlgorism; //pointer to a vector that contains the algorism
	int isArmstrong;  // when isArmstrong: -1 not calculed, 0 is not, 1 it is
};

void  ArmstrongHelper(int n, struct ArmstrongNumbers* an);
int   SumOfPower(struct ArmstrongNumbers an);

bool is_armstrong_number(int candidate)
{
	struct ArmstrongNumbers  NA = { 1, NULL, 0 };
	NA.ptrAlgorism = (int*)malloc(NA.nalgorism * sizeof(int));

	if (candidate < 10)
	{
		NA.ptrAlgorism[0] = candidate;
		NA.nalgorism = 1;
	}
		
	else
		ArmstrongHelper(candidate, &NA);

	NA.isArmstrong = isArmtrongNumber(candidate, SumOfPower(NA));
	free(NA.ptrAlgorism);

	return NA.isArmstrong;
}

void ArmstrongHelper(int n, struct ArmstrongNumbers* an)
{
	int div, resp;
	static int vecInt = 0;

	div = n / 10;
	resp = n % 10;

	an->ptrAlgorism[vecInt] = resp;

	if (div > 0)
	{
		vecInt++;
		an->nalgorism += 1;
		an->ptrAlgorism = (int*)realloc(an->ptrAlgorism, an->nalgorism * sizeof(int));
		ArmstrongHelper(div, an);
	}

	else {  /* do nothing*/ }
}

int SumOfPower(struct ArmstrongNumbers an)
{
	int sum = 0;

	for (int i = 0; i < an.nalgorism; i++)
	{
		sum += pow(an.ptrAlgorism[i], an.nalgorism);
	}

	return sum;
}