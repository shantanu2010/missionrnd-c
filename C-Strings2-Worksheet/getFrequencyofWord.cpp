/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
int getLen(char* string){

	int i = 0;

	while (string[i] != '\0')
		i++;

	return i;

}
int count_word_in_str_way_1(char *str, char *word){


	int i = 0;
	int j = 0;
	int count = 0;
	
	int strLen = getLen(str);
	int wordLen = getLen(word);

	for (i = 0; i <= (strLen - wordLen); i++){

		j = 0;
		
		while (j<wordLen && i + j<strLen && str[i + j] == word[j]){

			j = j + 1;
			if (j == wordLen){
				count++;
			}

		}
		
	}

	return count;
}

//int count_word_int_str_way_2_recursion(char *str, char *word){
//return 0;
//}
