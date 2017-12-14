/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include<stdio.h>
#include<stdlib.h>


int powF(int base, int exponent){


	int temp = exponent;
	int result = 1;

	while (exponent != 0){

		result *= base;
		--exponent;
	}

	return result;
}

int getLenght(char* string){

	int i = 0;

	while (string[i] != '\0')
		i++;


	return i;
}

void reverse(char* line,int length){
	int index;
	
	char temp;

	
	for (index = 0; index<length / 2; ++index){

		temp = line[index];
		line[index] = line[length - 1 - index];
		line[length - 1 - index] = temp;
	}

}



void getString(int integer, char* string, int decimalCount){

		int i = 0;
		while (integer != 0){
		
			string[i] = (integer % 10) + 48;
			i++;
			integer = integer / 10;
		}

		while (i < decimalCount)
			string[i++] = '0';

		reverse(string, i);
		string[i] = '\0';
		
	}




void decimalgetString(float floatingPart, char* string, int afterdecimal,int tempLength){
	
	string[tempLength] = '.';

	floatingPart = floatingPart * powF(10, afterdecimal);

	getString((int)floatingPart, string + tempLength + 1, afterdecimal);


}


void number_to_str(float number, char *string,int afterdecimal){


	int integerPart;
	float floatingPart;
	int tempLength;


	if (number < 0){

		integerPart = (int)(number)*-1;
		floatingPart = (number*-1) - integerPart;
		string[0] = '-';


		getString(integerPart, string + 1, 0);
		tempLength = getLenght(string);

		if (afterdecimal> 0){

			decimalgetString(floatingPart, string, afterdecimal, tempLength);
		}


	}


	else{


		integerPart = (int)(number);
		floatingPart = number - integerPart;


		getString(integerPart, string, 0);
		tempLength = getLenght(string);

		if (afterdecimal> 0){

			decimalgetString(floatingPart, string, afterdecimal, tempLength);
		}
	}

	
}
