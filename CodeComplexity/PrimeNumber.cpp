/*
Problem Code : ISPRIME

In this lesson you will write 3 ways of how to find a prime number and then note down its performances.

Question : Given a number return 1 if its a prime number ,0 otherwise.

Dont try to over optimize soultion unless asked. Write bad code its okay. The purpose of this lesson is to learn
how bad code effects the time taken for running.

Observations: (Write down what you observed here):

Way 1 : Checking the given number from 2 to given number-1 requires lot of time.

Way 2 : Time reduces when we restrict our loop from 2 to squareroot of given number.

Way 3 :In the Third method we can even restrict the loop by preliminary examinations where we can decide whether given 
       number is not Prime Number by following examiniations-

	   if(number % 2 == 0 || number % 3 == 0 || number % 5 == 0 || number % 7 == 0)
			return false

	   Since Even Numbers are not Prime Numbers.

	   if the given number is odd Number i.e (number %2 ==1) then it is implicitly known that the number wont be divided by 
	   "2". so we start out loop by 3 and increment our loop by (i+=2)

		
Conclusion : We can Find Prime Numbers in Way-3 which is much faster than above methods 
*/

#include <stdio.h>
#include <math.h>

/*
Divide the number with all elements from  1 to number and check whether its prime number or not.
Dont do any optimizations. Just write the brute force code.
*/
int isPrimeBruteForce(int number){

		int primeFlag = 1;
		int count;
		
		for (count = 2; count < number; ++count)
			if (number%count == 0){
				primeFlag = 0;
				break;
			}
		return primeFlag;

}

/*
Is checking division till number neccesary? 

You can do it just till half of number or even better just square root of n.

Divide the number with all elements from  1 to sqrt(number) and check whether its prime number or not.
Dont do any more optimizations.

Think why is it sufficient to do it till just square root of number.
*/
int isPrimeSquareRoot(int number){

	int primeFlag = 1;
	int count;

	for (count = 2; count <= sqrt((double)number); ++count)
		if (number%count == 0){
			primeFlag = 0;
			break;
		}
	return primeFlag;
}

/*
Add more optimizations you like, 
Like if a number is odd number you need not divide it with even numbers. etc.
*/
int isPrimeOptimized(int number){

	int primeFlag = 1;
	int count = 2;
	int incrementer = 1;


	if (number == 2 || number == 3 || number == 5 || number == 7)
		return primeFlag;

	if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0 || number % 7 == 0)
		return 0;

	if (number % 2 == 1){

		count = 3;
		incrementer = 2;
	}


	for (count; count <=sqrt((double)number); count+=incrementer)
		if (number%count == 0){
			primeFlag = 0;
			break;
		}
	return primeFlag;
	
}


