/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>

int stringLength(char* line){
	int index;

	for (index = 0; line[index] != '\0'; ++index)
		;

	return index;
}
void reverse(char* line){
	int index;
	int length;
	char temp;

	length = stringLength(line);

	for (index = 0; index<length / 2; ++index){

		temp = line[index];
		line[index] = line[length - 1 - index];
		line[length - 1 - index] = temp;
	}

}



int stringToInt(char* array){


	int number = 0;
	int i = 0;

	while (array[i] != '\0'){


		number *= 10;
		number += (int)(array[i] - '0');

		i++;
	}

	return number;

}

int decimalToOctal(int number){


	if (number <= 0)
		return 0;

	char* array = (char*)calloc(20, sizeof(char));
	int temp;
	int i = 0;
	char c;
	int finalNumber;

	while (number != 0){

		temp = number % 8;
		c = temp + '0';
		array[i++] = c;
		number /= 8;

	}

	array[i] = '\0';

	reverse(array);
	finalNumber = stringToInt(array);

	return finalNumber;
}


float decimalToOctalFraction(float number){

	int integerPart;
	float floatPart;
	int tempResult;
	float finalResult;
	float ftemp;
	int itemp;
	int i = 5;

	integerPart = (int)(number);
	floatPart = number - integerPart;

	tempResult = decimalToOctal(integerPart);
	ftemp = floatPart;


	while (i>0){

		ftemp = ftemp * 8;
		itemp = (int)(ftemp);

		if (ftemp == itemp){

			ftemp = ftemp - (float)itemp;
			return ftemp;

		}

		if (ftemp>1){

			ftemp = ftemp - (float)itemp;

		}

		i--;

	}

	finalResult = (float)tempResult + ftemp;


	return finalResult;

}
