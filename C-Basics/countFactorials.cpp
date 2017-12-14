/*Problem - To find the number of factorials in a given range.

Description - You will be given an input array[l, h] which gives the range.Your job is to return the count of the number of factorials between 'l' and 'h' both included.

Example: input = [2, 10]
		 The factorails between 2 and 10 is '2' alone.Hence 1 must be returned.


Constraints :
1) The range should not be negative, i.e neither of l and h should be negative.If so, return -1.
2) l, h are both long integers.
3) The range should be non decreasing, i.e l <= h.It is not, return -1.

DONT CHANGE THE FUNCTION HEADERS.



*/

#include <stdio.h>


long fact(long number){

	long factorial = 1;
	long index;

	for (index = 1; index <= number; index++){

		factorial *= index;

	}
	return factorial;

}

int countFactorials(long low, long high){

	if (low < 0 || high < 0)
		return -1;

	if (high < low)
		return -1;


	long i;
	unsigned long temp = 0;
	int result = 0;

	for (i = 1; i <= high; i++){

		temp = fact(i);

		if (temp >= low && temp <= high)
			result++;

		if (temp > high)
			break;


	}

	return result;

}

