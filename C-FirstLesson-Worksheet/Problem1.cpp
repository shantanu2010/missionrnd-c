/*
	Question-1: Given an 32-bit signed integer. 
		(i) Return the reverse of the number.
		(ii) Return 0 if the reversed number overflows and for other invalid cases

	Example: 
		(i) INPUT: 123, OUTPUT: 321
		(ii) INPUT: -123, OUTPUT: -321

*/
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>



int reverseNumber(int x){

	if (x > 999999999)
		return 0;


	int temp = x;
	int remainder = 0;
	int reverse = 0;
	int counter = 1;
	bool check = false;

	if (x < 0){

		temp *= -1;
		check = true;

	}


	while (temp != 0){

		remainder = temp % 10;
		reverse = reverse * 10 + remainder;
		temp /= 10;

	}

	if (check)
		return reverse*-1;

	else

		return reverse;



	return 0;
}
