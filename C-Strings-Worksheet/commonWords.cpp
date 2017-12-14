/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.

*/

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>




int getWords(char* str1){

	int i = 0;
	int count = 0;

	while (str1[i] != '\0'){

		if (str1[i] == ' ')
			count++;

		i++;

	}

	return count;

}

bool findStr(char *string, char *pattern){

	int patternL = 0;
	int stringL = 0;


	while (pattern[patternL] != '\0')
		patternL++;

	while (string[stringL] != '\0')
		stringL++;

	if (patternL == 0)
		return false;

	char* temp1 = string;
	char* temp2 = pattern;
	char* temp3;

	bool flag = 0;

	int i, j;

	for (i = 0; i<stringL; i++){

		if (*temp1 == *temp2){

			temp3 = temp1;
			for (j = 0; j<patternL; j++){

				if (*temp3 == *temp2){

					temp3++; temp2++;

				}
				else
					break;
			}
			
			temp2 = pattern;
			
			if (j == patternL){

				flag = true;

			}
		}
		temp1++;
	}


	if (flag == true)
		return true;


	return false;
}


void copyStrings(char** source, char** destination, int max, int* arr){


	int i = 0;
	int j = 0;
	int temp;
	int destinationIndex = 0;

	while (j < max){

		temp = arr[j];

		for (i = 0; source[temp][i] != '\0'; i++){

			destination[destinationIndex][i] = source[temp][i];

		}
		destination[destinationIndex][i] = '\0';
		destinationIndex++;

		j++;


	}

}


char ** commonWords(char *str1, char *str2) {


	if (str1 == NULL || str2 == NULL)
		return NULL;


	int i = 0;
	int j = 0;
	int k = 0;
	int commonWords = 0;


	int noOfWordsInString1 = getWords(str1);

	char** wordsInString1 = (char**)calloc((noOfWordsInString1 + 1), sizeof(char*));
	char** finalWords = (char**)calloc((noOfWordsInString1 + 1), sizeof(char*));

	int* arr = (int*)calloc(noOfWordsInString1 + 1, sizeof(int));

	for (i = 0; i <= noOfWordsInString1; i++){
		wordsInString1[i] = (char*)calloc(100, sizeof(char));
		finalWords[i] = (char*)calloc(100, sizeof(char));
		finalWords[i][0] = '\0';

	}

	bool boolFlag = false;
	i = 0;
	while (str1[i] != '\0' && j <= noOfWordsInString1){


		if (str1[i] == ' '){

			wordsInString1[j][k] = '\0';
			j++;
			k = 0;
		}

		else{

			wordsInString1[j][k] = str1[i];
			k++;
		}

		i++;

	}

	wordsInString1[j][k] = '\0';
	j++;
	k = 0;



	for (i = 0; i <j; i++){

		boolFlag = findStr(str2, wordsInString1[i]);

		if (boolFlag){
			arr[k++] = i;
			commonWords++;
		}
	}


	copyStrings(wordsInString1, finalWords, k, arr);

	if (k > 0)
		return finalWords;
	else
		return NULL;

}
