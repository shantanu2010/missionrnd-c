/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int getYear(char *dob){

	int i = 6;
	int year = 0;
	int digit;

	while (dob[i] != '\0'){

		digit = (int)dob[i] - '0';

		if (digit < 0 || digit > 9)
			return -1;

		year = year * 10 + digit;
		i++;
	}

	if (year < 1000)
		return -1;
	else
		return year;

}

int getMonth(char *dob){

	int month;
	int i = 3;

	month = (int)dob[i] - 48;

	month = month * 10 + (int)dob[i + 1] - '0';

	if (month < 0 || month >12)

		return -1;

	else
		return month;

}

int getDay(char *dob, int month){

	int day;

	day = (int)dob[0] - '0';

	day = day * 10 + (int)dob[1] - '0';

	if (day < 1 || day > 31)
		return -1;

	else if (!(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))

		if (day == 31)

			return -1;

		else
			return day;

	else
		return day;

}


int compareDates(char *dob1, char *dob2) {

	int day1;
	int day2;
	int month1;
	int month2;
	int year1;
	int year2;

	int index = 0;

	while (dob1[index++] != '\0');

	if (index != 11)
		return -1;

	index = 0;

	while (dob2[index++] != '\0');

	if (index != 11)
		return -1;

	year1 = getYear(dob1);
	year2 = getYear(dob2);

	month1 = getMonth(dob1);
	month2 = getMonth(dob2);


	if (month1 == -1 || month2 == -1)
		return -1;

	day1 = getDay(dob1, month1);
	day2 = getDay(dob2, month2);

	if (month1 == 2 && year1 % 2 != 0)

		if (day1 == 29)
			return -1;

	if (month2 == 2 && year2 % 2 != 0)
		if (day2 == 29)
			return -1;


	if (year1 == -1 || year2 == -1)
		return -1;

	else if (year1 < year2)
		return 1;

	else if (year2 < year1)
		return 2;

	else if (year1 == year2){

		if (month1 < month2)
			return 1;

		else if (month2 < month1)
			return 2;

		else if (month1 == month2){


			if (day1 < day2)
				return 1;

			else if (day2 < day1)
				return 2;

			else if (day1 == day2)
				return 0;

		}

	}
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
		return NULL;

	struct transaction *result = (struct transaction *)calloc((ALen + BLen) , sizeof(struct transaction));
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	while (i < ALen && j < BLen) {
		
		if (compareDates(A[i].date, B[j].date) == -1){

			return NULL;

		}
		else if (compareDates(A[i].date, B[j].date) == 1){

			result[k++] = A[i++];

		}
			
		else if (compareDates(A[i].date, B[j].date) == 2){

			result[k++] = B[j++];

		}
			

		else{
			result[k++] = A[i++];
			result[k++] = B[j++];
			
		}

		

	}
	while (i < ALen) {
		
		result[k++] = A[i++];
		
	}
	while (j < BLen) {
		
		result[k++] = B[j++];
	
	}



	return k ? result : NULL;







}