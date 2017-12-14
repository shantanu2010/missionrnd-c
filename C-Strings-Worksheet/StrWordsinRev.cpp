/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include<stdio.h>


void reverseStringFromToSpecificPosition(char* string, int start, int end){

	char c;

	while (start<end){

		c = string[start];
		string[start] = string[end];
		string[end] = c;

		start++;
		end--;

	}

}


void str_words_in_rev(char *input, int len){


	reverseStringFromToSpecificPosition(input, 0, len - 1);

	int i = 0;
	int locationOfWordStart;

	while (i<len){

		if (input[i] != ' '){

			locationOfWordStart = i;

			while (input[i] != ' ' && i<len){
				i++;
			}
			reverseStringFromToSpecificPosition(input, locationOfWordStart, i - 1);
		}
		i++;
	}

}

