/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>




int octalToDecimal(long int number){

	int decimal = 0;
	int count = 1;
	int temp;

	while (number != 0){

		temp = number % 10;
		decimal += temp*count;
		count *= 8;
		number /= 10;


	}
	return decimal;
}

int getstringLength(char* array){


	int i;
	for (i = 0; array[i] != '\0'; i++)
		;

	return i;

}

void reverseString(char* line){
	int index;
	int length;
	char temp;

	length = getstringLength(line);

	for (index = 0; index<length / 2; ++index){

		temp = line[index];
		line[index] = line[length - 1 - index];
		line[length - 1 - index] = temp;
	}
	return;
}

int power(int base, int exponent){


	int temp = exponent;
	int result = 1;

	while (exponent != 0){

		result *= base;
		--exponent;
	}

	return result;
}

int StringToInt(char* array){

	int i = 0;
	int j;
	char c;
	int temp;
	int l;

	for (j = getstringLength(array) - 1, l = 0; j >= 0; j--, l++){

		c = array[j];
		temp = c - 48;
		i += temp*power(10, l);

	}

	return i;

}






char* decimalToHexa(int number){


	char* array = (char*)calloc(20, sizeof(char));
	int temp;
	int i = 0;
	//char c;

	while (number != 0){

		temp = number % 16;

		if (temp < 10)

			temp = temp + 48;
		else

			temp = temp + 55;

		array[i++] = temp;
		number /= 16;

	}

	array[i] = '\0';

	reverseString(array);

	return array;

}


int octalToHexadecimal(long int num){

	if (num <= 0)
		return 0;


	int temp = octalToDecimal(num);

	char* arr = decimalToHexa(temp);

	int answer = StringToInt(arr);

	return answer;

	
}

float octalToHexadecimalFraction(float num)
{
	return 0.0;
}
