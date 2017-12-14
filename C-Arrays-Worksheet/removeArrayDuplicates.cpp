/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>



void sortArrayDup(int* numbers, int left, int right){

	int leftHold;
	int rightHold;
	int pivot;

	pivot = numbers[left];
	leftHold = left;
	rightHold = right;

	while (left < right){

		while (numbers[right] >= pivot && left < right)
			--right;

		if (left != right)
			numbers[left++] = numbers[right];


		while (numbers[left] <= pivot && left < right)
			++left;


		if (left != right)
			numbers[right--] = numbers[left];
	}


	numbers[left] = pivot;
	pivot = left;

	left = leftHold;
	right = rightHold;

	if (left < pivot)
		sortArrayDup(numbers, left, pivot - 1);


	if (right > pivot)
		sortArrayDup(numbers, pivot + 1, right);
}


int removeArrayDup(int *Arr, int len){

	int i = 0;
	int j = 0;
	int DupValues = 0;

	for (i; i < len - 1; i++){

		if (Arr[i] == Arr[i + 1]){
			DupValues++;
			Arr[j] = Arr[i];
			i++;
			j++;

		}
		else{
			Arr[j] = Arr[i];
			j++;
		}

	}
	Arr[j] = Arr[i];

	return DupValues;

}

int removeArrayDuplicates(int *Arr, int len){

	int duplicateLength;
	int finalLength;

	if (len <= 0)
		return -1;

	if (Arr == NULL)
		return -1;


	sortArrayDup(Arr, 0, len - 1);

	duplicateLength = removeArrayDup(Arr, len);

	finalLength = len - duplicateLength;


	return finalLength;


}