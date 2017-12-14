/*
ProblemCode : STRMATCH
Marks : 10
Difficulty :Easy.

A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re ,
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a3e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

int findLen(char* str){

	int i = 0;

	while (str[i] != '\0')
		i++;

	return i;
}


int compare(char* string1, char* string2){

	int i = 0;

	while (string1[i] != '\0'){


		if (string1[i] == string2[i]){
			i++;
			continue;
		}

		else if (string1[i] == '$'){

			i++;
			continue;
		}
		else if (string2[i] == '$'){

			i++;
			continue;
		}

		else{

			return 0;
		}

	}

	return 1;
}



char* getTotalChar(char* string){

	char* temp = (char*)malloc(1000 * sizeof(char));
	int i = 0;
	int j;
	int t;
	char a;
	bool check = false;
	int index = 0;


	while (string[i] != '\0'){

		if (string[i] >= 48 && string[i] <= 57){

			j = i + 1;
			a = string[i];
			t = a - '0';

			while (string[j] != '\0' && string[j] >= 48 && string[j] <= 57){

				t = t * 10;
				a = string[j];
				t += a - '0';

				if (string[j + 1] == '\0')
					check = true;

				j++;
				continue;
			}

			i = j;

			while (t != 0){

				temp[index++] = '$';
				t--;
			}

			if (check == true){

				temp[index] = '\0';
				return temp;
			}

			continue;

		}

		else{

			temp[index++] = string[i++];
		}

	}

	temp[index] = '\0';

	return temp;

}

int isSTRMatched(char *str1, char *str2){

	if (str1 == NULL || str2 == NULL)
		return 1;

	char* temp1 = getTotalChar(str1);
	char* temp2 = getTotalChar(str2);

	int len1 = findLen(temp1);
	int len2 = findLen(temp2);
	int result;
	
	if (len1 != len2)
		return 0;

	else

		result = compare(temp1, temp2);

	return result;

}
