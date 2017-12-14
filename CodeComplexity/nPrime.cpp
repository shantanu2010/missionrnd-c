/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 : LoopCount : 10k  Number value : 100  time taken: 0.39s

Way 2 : LoopCount : 10k  Number value : 100  time taken: 0.36s

Way 3 : LoopCount : 10k  Number value = 100  time taken: 0.031s

Conclusion : Way 2 was not much effieient compared to way 1 ...But Way 3 Is much Efficient
*/

#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include<stdbool.h>


/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/

bool isPrimeBrute(int number){
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

int* nPrimeBruteForce(int N){

		if (N <= 0)
			return NULL;

		int* arr = (int*)malloc(N/2 * sizeof(int));

		int number = N;
		int index = 0;
		for (number = 2; number <=N; ++number){

			if (isPrimeBrute(number)){
				arr[index++] = number;

			}

		}

		return arr;

}

/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/


bool isPrime(int number){
	
	bool primeFlag = true;
	int count;
	int factors = 0;

	for (count = 3; count<number; count=count+2)
		if (number%count == 0){
			primeFlag = false;
			break;
		}
	return primeFlag;
}



int* nPrimeEvenRemoved(int N){

	if (N <= 0)
		return NULL;

	int* arr = (int*)malloc(N/2 * sizeof(int));
	arr[0] = 2;
	int number = N;
	int index = 1;

	for (number = 3; number <= N; number=number+2){

		if (isPrime(number)){
			arr[index++] = number;

			
		}

	}

	return arr;
	
}

/*
Do all optimizations you can think of.

Hint : 
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/


bool isPrimeOptimized(int number, int* arr, int i){

	int count;


	for (count = 0; count<i; count++)
		if (number%arr[count] == 0){
			return false;
		}

	return true;
}
int* nPrimeOptimized(int N){

	if (N <= 0)
		return NULL;
	
	int* arr = (int*)malloc(N/2*sizeof(int));
	arr[0] = 2;
	
	int number;
	int index = 1;

	for (number = 3;number<=N;number = number + 2){

		if (isPrimeOptimized(number, arr, index)){
			arr[index++] = number;
		}
			
		
	}

	return arr;
}