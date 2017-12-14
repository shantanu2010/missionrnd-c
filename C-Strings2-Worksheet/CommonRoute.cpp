/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any
number of times.
Output :
Return a Common Route String which covers maxiumum Islands

Example 1 :
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ"
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation :
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost )
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdio.h>

int cost1(char *str, int i, int len){
	
	int cost;
	for (int j = i; j < len; j++){
		
		cost = 0;
		while (str[j] != ' '){
			
			cost = cost + str[j] - 64;
			j++;
		}
		return cost;
	}

}
char * find_common_route(char * hacklist, char *codelist, int *cost){

	char* str = (char*)malloc(10000 * sizeof(char));
	int len1 = 0, len2 = 0, len = 0, c = 0, i, cos; *cost = 0;
	
	if (hacklist == NULL&&codelist == NULL){
		*cost = 0;
		return NULL;
	}
	if (codelist == NULL&&hacklist == NULL)
		return 0;
	while (hacklist[len1] != '\0')
		len1++;
	while (codelist[len2] != '\0')
		len2++;
	for (i = 0; i < len1; i++){
		
		for (int j = 0; j < len2; j++){
			
			int count = 0;
			if (hacklist[i] == codelist[j]){
				
				while (hacklist[i + count] == codelist[j]){
					
					if (hacklist[i + count] == '\0')
						break;

					if (hacklist[i + count] == codelist[j]){

						str[len] = codelist[j];
						len++;
						j++;
						count++;

					}
					else
						break;

				}
				if (count > c)
					c = count;
				if (c > count)
					len = len - count;
				str[len] = ' ';
				len++;
			}

		}
		if (c >= len1 - 1)
			break;
	}
	str[len] = '\0';
	if (c == 0)
		return NULL;
	int count = 0, q = 0;
	for (i = 0; i < len; i++){
		
		if (str[i] == ' '){
			
			if (c == count){
				
				cos = cost1(str, i - count, len);
				q++;
				if (q == 1){
				
					if (cos > *cost)
						*cost = cos;
				}
				if (cos < *cost)
					*cost = cos;
				count = 0;
			}
			count = 0;
			continue;
		}
		count++;
		continue;
	}
	int l = 0; count = 0;
	for (i = 0; i < len; i++){
		
		if (*cost == cost1(str, i - count, len)){
			i = i - count;
			while (str[i] != ' '){
				
				str[l] = str[i];
				l++;
				i++;
			}
			break;
		}

	}
	str[l] = '\0';
	return str;
}




/*

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int le(char* string){

	int i = 0;

	while (string[i] != '\0'){
		i++;

	}

	return i;
}

int getIndex(char** res, int* arr, int l){

	int max = 0;
	int index = 0;
	int temp = 0;
	char t1;
	char t2;
	int n1;
	int n2;

	int i;

	for (i = 0; i<l; i++){

		if (arr[i]<max){

			max = arr[i];
			index = i;
		}

		else if (arr[i] == max){

			t1 = res[i][0];
			t2 = res[index][0];

			n1 = t1 - '0';
			n2 = t2 - '0';

			if (n1<n2)
				index = i;

			break;


		}

	}

	return index;



}

int getCost(char* string){

	int temp;
	char a;
	int result = 0;
	int i = 0;


	while (string[i] != '\0'){

		a = string[i];
		temp = a - 64;
		result += temp;
		i++;

	}


	return result;

}

void copyString(char* dest, char*source){


	int i = 0;

	while (source[i] != '\0'){

		dest[i] = source[i];
		i++;

	}

	dest[i] = '\0';


}


char* longestCommonSubstrings(char* s, char* t, int len1, int len2, int len, int* cost){


	int longest = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;

	int te;


	int** table = (int**)calloc((len + 20), sizeof(int*));
	char** result = (char**)calloc(((len+20)),sizeof(char*));
	int a = 0;

	for (a = 0; a<(len + 20); a++){

		table[a] = (int*)calloc((len + 20),sizeof(int));
		result[a] = (char*)calloc((len + 20),sizeof(char));
		
	}




	
	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {

			if (s[i] != t[j]) {
				continue;
			}

			table[i][j] = (i == 0 || j == 0) ? 1 : 1 + table[i - 1][j - 1];

			if (table[i][j] > longest) {
				longest = table[i][j];
				k = 0;
				l = 0;
			}
			if (table[i][j] == longest) {

				for (te = (i - longest + 1); te<(i + 1); te++){

					result[k][l++] = s[te];
				}

				result[k][l] = '\0';
				k++;
				l = 0;

			}

		}
	}

	int* valueArray = (int*)malloc(k*sizeof(int));
	char* finalResult = (char*)malloc(26 * sizeof(char));

	i = 0;
	j = 0;

	for (i = 0; i<k; i++){

		valueArray[i] = getCost(result[i]);
	}

	if (k == 0){

		(*cost) = 0;
		return NULL;
	}


	if (k>1){


		j = getIndex(result, valueArray, k);
		copyString(finalResult, result[j]);
		(*cost) = valueArray[j];
	}

	else{

		copyString(finalResult, result[0]);
		(*cost) = valueArray[0];
	}

	return finalResult;

}



char * find_common_route(char * hacklist, char *codelist, int* cost){


	if (hacklist == NULL || codelist == NULL){

		(*cost) = 0;
		return NULL;
	}

	int len;
	int len1 = le(hacklist);
	int len2 = le(codelist);

	if (len1<len2)
		len = len2;

	else
		len = len1;

	int temp = 0;
	char* result = longestCommonSubstrings(hacklist, codelist, len1, len2, len, cost);

	return result;

}

*/

