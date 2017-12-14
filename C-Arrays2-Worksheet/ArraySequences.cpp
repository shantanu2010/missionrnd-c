/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int getAp(int startIndex, int* array, int* resultArray, int length, int k){

	
	int diff = abs((array[startIndex + 1] - array[startIndex]));

	int i = startIndex + 1;
	for (i; i < length; i++){
	
		if (abs(array[i - 1] - array[i]) == diff)
			continue;

		else{

			break;
		}



	}

	if (array[i - 1] <= 0 && array[i - 1] >= 0)
		return i - 2;

	return i - 1;


}

int getGp(int startIndex, int*array, int length){

	int i = startIndex;

	while ((array[i] * array[i]) == (array[i - 1] * array[i + 1])){
		i++;
	}

	return i;

}


int * find_sequences(int *arr, int len){

	if (len<3 || arr == NULL)
		return NULL;


	int* resultArray = (int*)malloc(8 * sizeof(int));
	int i;

	bool apFlag1 = false;
	bool apFlag2 = false;
	bool gpFlag = false;
	bool check = false;
	int temp;
	int inc = 0;
	for (i = 0; i <= len - 3; i++){

		if (!apFlag1 && arr[i] + arr[i + 2] == 2 * arr[i + 1]){


			apFlag1 = true;
			apFlag2 = true;
			check = true;
			resultArray[0] = i;
			temp = getAp(i, arr, resultArray, len, 1);
			resultArray[1] = temp;
			i = temp - 1;
		}

		else if (apFlag2 && check && arr[i] + arr[i + 2] == 2 * arr[i + 1]){

			check = false;
			resultArray[2] = i;
			temp = getAp(i, arr, resultArray, len, 3);
			resultArray[3] = temp;
			break;
		}


	}

	for (i = 1; i + 1 < len; i++){

		if (arr[i] * arr[i] == arr[i - 1] * arr[i + 1]){

			resultArray[4] = i - 1;
			inc = getGp(i + 1, arr, len);
			resultArray[5] = inc;
		}

	}

	return resultArray;
}
