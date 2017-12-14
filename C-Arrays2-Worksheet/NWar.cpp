/*
Problem Code :NWAR

There is a war going among numbers ,on who should be considered as a Leader and finally they have reached a conclusion .
For those numbers when breaked into digits and Individual squares are added ,and if the sum is not 1 ,the process is repeated for the sum and so on.
When doing this if any any time ,Sum reaches 1 , that number can be called as Leader Number , other wise not .

Ex: 1000 => (1^2 + 0^2 + 0^2 + 0^2) ==> 1 .1000 is a leader number
Ex: 44 => (16+16) => 32 => (9+4) ==> 13 => (1+9) ==> 10 ==> (1+0) ==> 1. 44 is a leader number .
Ex: 67 => (36+49) ==> 85 => By Doing Dividing and Squaring and Summing we get this series
89 => 145 => 42 => 20 => 4 => 16 => 37 => 58 => 89 , As 89 is already generated No matter how many times we do this process We can never reach 1 .So its not a leader Element .

Given an Array of Numbers ,You need to return the array of Leader Elements .You should also copy the Number of Leader Elements Found in *leadersArraLen variable .
Order should be maintained in the Result Array .

Ex Input : [

Constraints :
0<= A[i]< 1000000
0<len<10000

Note : Returns Array Length will not be greater than 10001 . And If the leader number occured 2 or more times in the original array include those many times in answer
Note : Return NULL for Invalid Inputs
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int compute(int number){

	int result = 0;
	int temp;

	while (number!=0){

		temp = (number % 10);
		result += temp*temp;
		number/= 10;
	}
	return result;
}

bool checkLeaderNumber(int number){
	
	int check1 = number;
	int check2 = number;
	int check3 = number;


	for (;;){
	
		check1 = compute(check1);

		check2 = compute(compute(check2));

		check3 = compute(compute(compute(check3)));

		if (check1 == 4 || check2 == 4 || check3 == 4)
			return false;

		if (check1 == 1 || check2 == 1 || check3 == 1)
			return true;

		if (check1 == check2 || check2 == check3 || check3 == check1)
			break;

	} 

	return check1 == 1 ? true : false;
}

int* getSquareLeaderArray(int *arr, int len, int *leadersArrayLen){


	if (arr == NULL || len <= 0)
		return NULL;

	int* result = (int*)malloc((len)*sizeof(int));
	int i = 0;
	int j = 0;
	int temp;

	while(i<len){

		if (checkLeaderNumber(arr[i]))
			result[j++] = arr[i];

		i++;
		
	}

	(*leadersArrayLen) = j;
	return result;


}
