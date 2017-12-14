/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>

int lenFunDef(char* string){

	int i = 0;

	while (string[i] != '\0'){
		i++;

	}

	return i;

}


int* getString(char* string, int initial, int required){

	int i = 0;
	int j = required - initial;
	int temp;
	int index = 0;

	int* number = (int*)malloc(100 * sizeof(int));

	if (j > 0){
		
		while (j != 0){
			number[i++] = 0;
			j--;
		}

	}

	while (string[index] != '\0'){
			
		temp = string[index] - '0';
		number[i++] = temp;
		index++;
	}

	return number;
	

}
int stringCompare(char* str1, char* str2){

	int i = 0;

	while (str1[i] == str2[i]) {
		if (str1[i] == '\0' || str2[i] == '\0')
			break;
		i++;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
		return 0;
	else
		return -1;
}



char* compute(int* number1, int* number2, int len, char* op){


	char* result = (char*)malloc(100*sizeof(char));
	int i = 0;
	int temp1;
	int temp2;
	int res;
	char t;

	if (stringCompare(op,"OR") == 0){

		while (i < len){

			temp1 = number1[i];
			temp2 = number2[i];

			res = temp1 | temp2;
			t = res + '0';
			result[i] = t;
			i++;
		}
		result[i] = '\0';

		return result;

	}

	else if (stringCompare(op, "AND") == 0){

		while (i < len){

			temp1 = number1[i];
			temp2 = number2[i];

			res = temp1 & temp2;
			t = res + '0';
			result[i] = t;
			i++;
		}
		result[i] = '\0';

		return result;

	}

	else if (stringCompare(op, "XOR") == 0){
		

		while (i < len){

			temp1 = number1[i];
			temp2 = number2[i];

			res = temp1 ^ temp2;
			t = res + '0';
			result[i] = t;
			i++;
		}
		result[i] = '\0';

		return result;

	}

	else if (stringCompare(op, "NOR") == 0){

		while (i < len){

			temp1 = number1[i];
			temp2 = number2[i];

			res = !(temp1 | temp2);
			t = res + '0';
			result[i] = t;
			i++;
		}
		result[i] = '\0';

		return result;

	}
	
	return NULL;


}


char *performOperation(char *str1, char *str2, char *operation){


	if (str1 == NULL || str2 == NULL || operation == NULL)
		return NULL;

	int len1 = lenFunDef(str1);
	int len2 = lenFunDef(str2);
	int len;

	if (len1 < len2)
		
		len = len2;
	
	else
		
		len = len1;


	int* number1 = getString(str1, len1, len);
	int* number2 = getString(str2, len2, len);
	char* result = compute(number1, number2, len, operation);
	
	return result;
}

