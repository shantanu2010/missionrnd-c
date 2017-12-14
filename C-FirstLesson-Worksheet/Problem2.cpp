#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

int length(char* string){


	int i = 0;

	while (string[i] != '\0'){

		i++;
	}

	return i;

}

void stringCopy(char* source, char* target){

	int i = 0;
	while (source[i] != '\0'){

		target[i] = source[i];
		i++;
	}
	target[i] = '\0';
}

void removeSymbol(char *string){

	int i = 0;
	int j = 1;
	int len = length(string);
	while (string[i] != '\0' && j<len){
		string[i] = string[j];
		i++;
		j++;

	}

	string[i] = '\0';

}

// this function is used to compare only digits and return which number is greater from left to right
// it doesnot care about sign
int DetermineGretestNumber(char* string1, char* string2, int start1, int start2, int length1, int length2){


	int i = start1;
	int j = start2;
	int temp1;
	int temp2;
	//printf("\nstart : %d : %d",start1,start2);
	//printf("\nlengths : %d : %d",length1,length2);

	while (i<length1){

		temp1 = (int)(string1[i] - '0');
		temp2 = (int)(string2[j] - '0');


		if (temp1>temp2)
			return 1;

		if (temp1<temp2)
			return 2;


		//printf("\ni : %d j : %d",i,j);
		i++;
		j++;


	}


	return 1;



}


// function whic adds two numbers
char* add(char* string1, char* string2, int start, int length, bool flag){

	//int temp;
	int temp1;
	int temp2;
	int result;
	int carry = 0;
	int i;
	int j = 0;
	char* final = (char*)malloc((length + 2)*sizeof(char));



	for (i = length - 1; i >= start; i--){


		temp1 = (int)(string1[i] - '0');
		temp2 = (int)(string2[i] - '0');
		result = temp1 + carry + temp2;

		//printf("\nTemps : %d :%d :carry : %d",temp1,temp2,carry);
		if (result >= 10){

			carry = 1;
			result = result % 10;
			final[j] = (char)(result + '0');


		}

		else{

			carry = 0;
			final[j] = (char)(result + '0');


		}
		j++;


	}
	//printf("%d",carry);
	if (carry != 0){

		final[j] = (char)(carry + '0');
		j++;
	}
	//printf("%s",final);
	if (flag){

		final[j++] = '-';


	}

	final[j] = '\0';

	return final;


}



char* subtraction(char* string1, char* string2, int start1, int start2, int length1, int length2, bool flag){


	int temp1;
	int temp2;
	int result;
	int i;
	int j;
	int k;

	int len;
	length1 = length(string1);
	length2 = length(string2);

	if (length1>length2)
		len = length1;

	else
		len = length2;



	char* final = (char *)calloc(len + 2, sizeof(char));
	j = 0;
	//printf("\nlen : %d",len);
	for (i = len - 1; i >= 0; i--){


		temp1 = (int)(string1[i] - '0');
		temp2 = (int)(string2[i] - '0');

		result = temp1 - temp2;
		//printf("Strings : %s :%s",string1,string2);
		//	printf("\ntemps : %d : %d : %d",temp1,temp2,result);
		if (result >= 0){

			final[j++] = (char)(result + '0');

		}

		else{


			k = i - 1;
			while (string1[k] == '0'){

				string1[k] = '9';
				k--;

			}
			string1[k] = string1[k] - 1;
			final[j++] = (char)(((string1[i] - '0') - (string2[i] - '0') + 10) + '0');
		}
		//printf("\n%c",final[j-1]);			
	}

	if (flag)
		final[j++] = '-';

	final[j] = '\0';
	return final;

}







bool checkLengthSign(char* string1, char* string2){



	int l1 = length(string1);
	int l2 = length(string2);


	if (l1 == l2){

		if (string1[0] == '+' && string2[0] == '+')
			return true;
		else if (string1[0] == '-' && string2[0] == '-')
			return true;

		return false;


	}
	else

		return false;




}



void reverse(char* string){


	int i = 0;
	int j = length(string) - 1;
	char temp;

	while (i < j) {
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
		i++;
		j--;
	}



}

void stripingZeros(char* string){

	int k = 0;
	int start = 0;
	int l = length(string);


	if (string[0] == '+' || string[0] == '-'){

		k = 1;
		start = 1;
	}

	while (string[k] == '0'  && string[k] != '\0'){

		k++;
	}

	if (k + start == l){

		string[0] = '0';
		string[1] = '\0';

	}

	else{

		while (string[k] != '\0'){


			string[start++] = string[k++];


		}
		string[start] = '\0';

	}


}


// Main function .....this is as given by mrnd

char* addNumberStrings(char* str1, char* str2){

	// i am checking both length and both signs are equal
	// only numbers with corresponding "sign" and both signs should be same
	// eg- +123,-111....123,-999 arre not possible

	if (str1 != NULL && str2 == NULL)
		return str1;

	if (str2 != NULL && str1 == NULL)
		return str2;

	if (str1 == NULL && str2 == NULL)
		return NULL;


	char* string1 = (char*)malloc(length(str1)*sizeof(char));
	char* string2 = (char*)malloc(length(str2)*sizeof(char));

	stringCopy(str1, string1);
	stringCopy(str2, string2);

	bool check = checkLengthSign(string1, string2);

	char* finalResult = NULL;


	if (check){

		//if both are negative .....
		if (string1[0] == '-'){


			finalResult = add(string1, string2, 1, length(string1), true);
			reverse(finalResult);


		}


		// if both numbers are positive
		else{

			finalResult = add(string1, string2, 1, length(string1), false);
			reverse(finalResult);


		}
		stripingZeros(finalResult);
		return finalResult;

	}


	else{


		int l1 = length(string1);
		int l2 = length(string2);
		int great;
		bool sign = false;



		if (l1 == l2){

			if (string1[0] != '+' && string1[0] != '-' && string2[0] != '+' && string2[0] != '-'){

				//printf("\nIn My case");
				finalResult = add(string1, string2, 0, l1, false);
				reverse(finalResult);
				stripingZeros(finalResult);
				return finalResult;
			}

			if (string1[0] == '-' && string2[0] == '+'){

				great = DetermineGretestNumber(string1, string2, 1, 1, l1, l2);
				if (great == 1){
					sign = true;
					removeSymbol(string1);
					removeSymbol(string2);

					finalResult = subtraction(string1, string2, 0, 0, l1, l2, sign);
					//printf("%s",finalResult);
					reverse(finalResult);
				}
				else if (great == 2){
					sign = false;
					removeSymbol(string1);
					removeSymbol(string2);

					finalResult = subtraction(string2, string1, 0, 0, l1, l2, sign);
					//printf("%s",finalResult);
					reverse(finalResult);

				}
			}

			if (string1[0] == '+' && string2[0] == '-'){

				great = DetermineGretestNumber(string1, string2, 1, 1, l1, l2);
				if (great == 1){

					sign = false;
					removeSymbol(string1);
					removeSymbol(string2);

					finalResult = subtraction(string1, string2, 0, 0, l1, l2, sign);
					//printf("%s",finalResult);
					reverse(finalResult);
				}
				else{
					sign = true;
					removeSymbol(string1);
					removeSymbol(string2);

					finalResult = subtraction(string2, string1, 0, 0, l1, l2, sign);
					//	printf("%s",finalResult);
					reverse(finalResult);

				}

			}

			stripingZeros(finalResult);
			return finalResult;
		}


		else{


			if (l1>l2){
				if (string1[0] == '+'){

					removeSymbol(string1);
					finalResult = add(string1, string2, 0, l2, false);
					reverse(finalResult);

				}
				else if (string1[0] == '-'){
					removeSymbol(string1);
					//printf("\n%s : %s",string1,string2);
					great = DetermineGretestNumber(string1, string2, 0, 0, l2, l2);
					//printf("%d",great);
					if (great == 1){
						finalResult = subtraction(string1, string2, 0, 0, l2, l2, true);
						reverse(finalResult);
						//printf("\nfr : %s",finalResult);
					}
					else{
						finalResult = subtraction(string2, string1, 0, 0, l2, l2, false);
						reverse(finalResult);
					}


				}


				stripingZeros(finalResult);
				return finalResult;

			}


			else{

				if (string2[0] == '+'){

					removeSymbol(string2);
					finalResult = add(string1, string2, 0, l1, false);
					reverse(finalResult);
				}
				else if (string2[0] == '-'){
					removeSymbol(string2);

					great = DetermineGretestNumber(string1, string2, 0, 0, l1, l1);
					if (great == 1){
						finalResult = subtraction(string1, string2, 0, 0, l1, l1, false);
						reverse(finalResult);
						stripingZeros(finalResult);
					}
					else{
						finalResult = subtraction(string2, string1, 0, 0, l1, l1, true);
						reverse(finalResult);
						stripingZeros(finalResult);
					}
				}


				stripingZeros(finalResult);
				return finalResult;

			}

		}


	}


}

