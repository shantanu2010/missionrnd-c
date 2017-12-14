
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include<stdlib.h>

bool isPrime(int number){
	bool primeFlag = true;
	int count;
	int factors = 0;

	for (count = 2; count<number; ++count)
		if (number%count == 0){
			primeFlag = false;
			break;
		}
	return primeFlag;
}

int* nPrime(int num){

	if (num <= 0)
		return NULL;

	int* arr = (int*)malloc(81 * sizeof(int));

	int number = num;
	int count = 0;
	int index = 0;
	for (number = 2; number !=0; ++number){

		if (isPrime(number)){
			arr[index++] = number;
			count++;

			if (count == num)
				break;
		}

	}

	return arr;

}

