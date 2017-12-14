/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int nthFibonacci(int n){

	if (n <= 0)
		return -1;


	if (n == 1 )
		return 0;

	if (n == 2)
		return 1;


	else{
		int count;
		int prev = 0;
		int curr = 1;
		int next = 0;

		for (count = 3; count <= n; ++count){

			next = prev + curr;
			prev = curr;
			curr = next;
		}
		return next;
	}
}

bool isPrime(int number){
	bool primeFlag = true;
	int count;
	int factors = 0;

	if (number == 2 || number == 3 || number == 5 || number == 7)
		return true;

	if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0 || number % 7 == 0)
		return false;

	for (count = 2; count<=(number/2); ++count)
		if (number%count == 0){
			primeFlag = false;
			break;
		}
	return primeFlag;
}

int nthPrime(int num){

	if (num <= 0)
		return -1;


	int number;
	int count = 0;
	for (number = 2; number != 0; ++number){


		if (isPrime(number)){
			count++;
			if (count == num)
				break;

		}
	}

	return number;


}
