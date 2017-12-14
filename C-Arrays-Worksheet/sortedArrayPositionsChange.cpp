/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>


void swap(int* Arr, int i, int j){

	int temp = Arr[i];
	Arr[i] = Arr[j];
	Arr[j] = temp;

}


void * sortedArrayPositionsChange(int *Arr, int len){
	

	if (Arr == NULL)
		return NULL;

	if (len <= 0)
		return NULL;

	int i = 0;
	int j = len - 1;
	
	while (Arr[i + 1] > Arr[i] && (i + 1) < len){

		i++;
	}

	if (i == len){

		return Arr;

	}


	else{

		while (Arr[j] > Arr[j - 1] && (j - 1) >= 0){

			j--;
		}

		swap(Arr,i,j);


	}

	return Arr;
}