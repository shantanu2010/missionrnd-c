/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search :
				Loop Count : 1k Size of array: 100k time taken: 0.29 sec
				Loop Count : 10k Size of array: 100k time taken: 3.1 sec

				Time Complexity - O(n)
				Best Case - O(1)

Binary Search : 

				Loop Count : 1k Size of array: 100k time taken: 0.01 sec
				Loop Count : 10k Size of array: 100k time taken: 0.05 sec
				Time Complexity - O(logn)
				Best Case - O(1)

Conclusion :Use Binary search if the values are sorted .... else go for linear search
*/

#include<stdio.h>

int linearSearch(int *arr, int len, int key) {

	if (arr == NULL)
		return -1;

	if (len <= 0)
		return -1;

	int i = 0;
	
	for (i; i < len; i++){

		if (arr[i] == key)
			return i;
	}


	return -1;
}



int binarySearch(int *arr, int len, int key) {
	//Use this function as wrapper function,if you are implementing bs recursively.

	int left = 0;
	int right = len - 1;
	int mid;
	int isLocated = 0;

	while (!isLocated && left <= right) {

		mid = (left + right) / 2;

		if (key == arr[mid])
			isLocated = 1;

		else if (key < arr[mid])
			right = mid - 1;

		else
			left = mid + 1;
	}

	return isLocated ? mid : -1;

}