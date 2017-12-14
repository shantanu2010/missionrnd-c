/*
OVERVIEW: Given a string, Return the substring of the main string from i index to j index
Indexes start from 0,ith letter and jth letter are included
E.g.: Input: "get_sub_string("abcdefgh",2,5) , Output: "cdef"

INPUTS: A string.

OUTPUT: return substring from [i,j]

INPUT2: I will Code for Mission RnD , 2,10
OUTPUT2:will Code

NOTES: Check Null Strings ,Include stddef for NULL if needed.Create a New string and return it ,dont modfiy
original String
*/

#include <stddef.h>
#include <stdlib.h>



int length(char* string){
	
	int i = 0;

	while (string[i] != '\0')
		i++;


	return i;

}
char * get_sub_string(char *str, int i, int j){
	
	
	if (str==NULL)
		return NULL;

		
	int len = length(str);

	if (j > len)
		return NULL;
	if (i > j)
		return NULL;

	int k = 0;
	char* string = (char*)calloc((j+1-i), sizeof(char));

	while (i < j+1){

		string[k++] = str[i++];
	}

	string[k] = '\0';

	return string;

}
