/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>


int getPosition(int *Arr, int len, int num) {
	
	int low = 0;
	int high = len - 1;

	

	while (true) {
		
		int mid = (high + low) / 2;
		
		if (len == 0) {
			return mid = 0;
		}
		
		
		if (low == mid) {
			if (Arr[mid] > num) {
				return mid;
			}
		}
		
		if (Arr[mid] < num) {
			low = mid + 1;
			if (low > high) {
				return mid + 1;
			}
		}
		
		else if (low > high) {
			return mid;
		
		}
		
		else {
			high = mid - 1;

		}
	}
}


void makeNewArray(int *Arr, int len, int num, int location){

	int i = len;

	for (i = len; i > location; i--){
		Arr[i] = Arr[i - 1];

	}

	Arr[location] = num;
}



int * sortedArrayInsertNumber(int *Arr, int len, int num){


	int location;

	if (Arr == NULL)
		return NULL;

	if (len < 0)
		return NULL;

	else{

		location = getPosition(Arr, len, num);
		makeNewArray(Arr, len, num, location);
		return Arr;
	}
}
