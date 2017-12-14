
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

void merge(int* numbers, int* temp, int left, int mid, int right){

	int leftEnd = mid - 1;
	int leftHold = left;
	int tempIndex = left;

	while (left <= leftEnd && mid <= right)

		if (numbers[left] <= numbers[mid])
			temp[tempIndex++] = numbers[left++];

		else
			temp[tempIndex++] = numbers[mid++];

	while (left <= leftEnd)
		temp[tempIndex++] = numbers[left++];

	while (mid <= right)
		temp[tempIndex++] = numbers[mid++];


	for (tempIndex = right; tempIndex >= leftHold; --tempIndex)
		numbers[tempIndex] = temp[tempIndex];

	return;
}
void mSort(int* numbers, int* temp, int left, int right){
	int mid;

	if (left<right){

		mid = (left + right) / 2;

		mSort(numbers, temp, left, mid);
		mSort(numbers, temp, mid + 1, right);

		merge(numbers, temp, left, mid + 1, right);
	}
	return;
}



int maxPosNegSum(int* input, int length){

	if (input == NULL)
		return 0;

	if (length <= 0)
		return 0;


	int* temp;
	int highest = 0;
	int lowest = 0;
	int i = 0;

	temp = (int*)calloc(length, sizeof(int));

	mSort(input, temp, 0, length - 1);
	highest = temp[length - 1];


	while (temp[i]<0){
		i++;
	}


	if (i == 0)
		lowest = 0;
	else
		lowest = temp[i - 1];
	
	if (highest < 0 || lowest == 0)
		return 0;

	return highest + lowest;

}
