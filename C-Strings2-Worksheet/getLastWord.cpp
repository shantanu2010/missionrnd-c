/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>
#include <stdio.h>



int getLength(char* string){

	int i = -1;

	while (string[++i] != '\0')
		

	return i;
}


int getLastSpaces(char* string){

	int i = -1;
	int lastSpace = 0;
	while (string[++i] != '\0'){

		if (string[i] == ' ')
			lastSpace = i;

	}

	return lastSpace;

}

char * get_last_word(char * str){
	

	if (str == NULL)
		return NULL;
	
	char* result = (char*)calloc(30, sizeof(char));

	int len = getLength(str);
	int lastSpace = getLastSpaces(str);
	int i = 0;

	while (++lastSpace <= len){
		result[i] = str[lastSpace];
		i++;

	}
	return result;

}
