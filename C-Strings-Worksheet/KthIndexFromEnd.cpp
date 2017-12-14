/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/


int lenString(char* string){

	int i = 0;

	while (string[i] != '\0')
		i++;


	return i;
}




#include<stdio.h>

char KthIndexFromEnd(char *str, int K) {

	if (K < 0)
		return '\0';

	if (str == NULL)
		return '\0';

	int len = lenString(str);

	if (K >= len)
		return '\0';

	return str[len - K - 1];
}