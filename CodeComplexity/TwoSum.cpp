/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 : Loop Count: 100k Size of array: 1000 time taken: 1.9s
        Time Complixity - O(n*n)

Way 2 : Loop Count: 100k Size of array: 1000 time taken: 1.56s
        Time Complexitiy - O(n*logn)

Way 3:  Loop Count : 100k Size of array: 1000 time taken :0.6s
         Time Complexity - O(n)

Conclusion : Way 3 was Faster And more Efficicent in case of less Numbers by using Extra Array
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? __________
*/
int* sumoftwoBF(int *nums, int target, int len){

	if (nums == NULL)
		return NULL;

	if (len <= 0)
		return NULL;

	int* returnArray = (int*)calloc(2, sizeof(int));
	int i = 0;
	int j;
	int lowPosition = -1;
	int highPosition = -1;
	int temp;

	for (i = 0; i < len; i++){
		for (j = i + 1; j < len; j++){
			
			temp = nums[i] + nums[j];

			if (temp == target){

				if (nums[j] < nums[i]){

					lowPosition = nums[j];
					highPosition = nums[i];

				}

				else{

					lowPosition = nums[i];
					highPosition = nums[j];
				}

			}

		}
	}

	if (lowPosition == -1 && highPosition == -1)
		return NULL;

	else{
		
		returnArray[0] = lowPosition;
		returnArray[1] = highPosition;

		return returnArray;
	}

}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint: 
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11. 

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add 
so that total sum will become less. 

What is the complexity of this method ? O(n*logn)
*/

void quickSort(int* A, int left, int right) {
	
	int temp;

	if (right <= left) 
		return;

	if (A[right] < A[left]) {
		
		temp = A[right];
		A[right] = A[left];
		A[left] = temp;
	}

	int pLow = left + 1;
	int pHigh = right - 1;
	int i = left + 1;

	while (i <= pHigh) {
		
		if (A[i] < A[left]) {
			
			temp = A[i];
			A[i++] = A[pLow];
			A[pLow++] = temp;
		}
		else if (A[right] < A[i]) {
			temp = A[i];
			A[i] = A[pHigh]; 
			A[pHigh--] = temp;
		}
		else i++;
	}

	temp = A[left];
	A[left] = A[--pLow];
	A[pLow] = temp;
	
	temp = A[right];
	A[right] = A[++pHigh];
	A[pHigh] = temp;

	quickSort(A, left, pLow - 1);
	
	if (A[pLow] < A[pHigh]) 
		quickSort(A, pLow + 1, pHigh - 1);
	
	quickSort(A, pHigh + 1, right);
}



int* sumoftwoSortAndSearch(int *nums, int target, int len){
	//Sort the array

	if (nums == NULL)
		return NULL;

	if (len <= 0)
		return NULL;

	quickSort(nums, 0, len - 1);



	int i = 0;
	int j = len - 1;
	int flag = 0;
	int temp;

	int* resultArray = (int*)calloc(2, sizeof(int));

	while (i < j && flag != 1){

		temp = nums[i] + nums[j];

		if (temp == target){
			
			flag = 1;
			resultArray[0] = nums[i];
			resultArray[1] = nums[j];

		}
		else if (temp > target){

			j--;
		}
		else{

			i++;
			j = len - 1;

		}
	}

	if (flag == 0)
		return NULL;

	return resultArray;

}

/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to 
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/
int* sumoftwoExtraArray(int *nums, int target, int len) {
	//Initialise the array
	//Do the task

	int i = 0;
	int j = len - 1;
	int flag = 0;

	int tempValuesArray[101] = {0};
	int* resultArray = (int*)calloc(2, sizeof(int));
	//int curr = nums[i] + nums[j];
	int temp;
	int requiredValue;

	for (i; i<len; i++){

		temp = nums[i];

		//printf("\nValue of Temp : %d",temp);

		requiredValue = target - temp;

		//printf("\nValue of requiredValue : %d",requiredValue);

		if (requiredValue <= 0)
			continue;

		else{

			if (tempValuesArray[requiredValue] == 1){

				flag = 1;
				resultArray[0] = temp;
				resultArray[1] = requiredValue;
				break;
			}
			else{

				tempValuesArray[temp] = 1;
			}

		}

	}


	return flag ? resultArray : NULL;
	
}


