/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: 
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int calcyear(char *dob){

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

int calcmonth(char *dob){

	int month;
	int i = 3;

	month = (int)dob[i] - 48;

	month = month * 10 + (int)dob[i + 1] - '0';

	if (month < 0 || month >12)

		return -1;

	else
		return month;

}

int calcday(char *dob, int month){

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








struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	
	int l;

	if (ALen > BLen)
		l = ALen;

	else
		l = BLen;

	struct transaction* resultArr = (struct transaction *)calloc(l, sizeof(struct transaction));

	if (A == NULL || B ==NULL)
		return NULL;

	if (ALen <= 0 || BLen <=0)
		return NULL;

	
	int day1;
	int month1;
	int year1;
	int day2;
	int month2;
	int year2;

	int i = 0;
	int j = 0;
	int k = 0;
	
	while (i<ALen && j<BLen){

		year1 = calcyear(A[i].date);
		month1 = calcmonth(A[i].date);
		day1 = calcday(A[i].date, month1);

		year2 = calcyear(B[j].date);
		month2 = calcmonth(B[j].date);
		day2 = calcday(B[j].date, month2);


		if (year1==year2 && month1 == month2 && day1 == day2){
			
			resultArr[k++] = A[i];
			i++;
			j++;

			

		}

		else if (year1 == year2){

			if (month1 < month2)
				i++;

			else if (month1 > month2)
				j++;

			else{
				
				if (month1 == month2){

					if (day1 > day2){
						j++;
					}
					else
						i++;
				}

			}

		}
		else{

			i++;
			j++;
		}
		
	}

	if (k>0)
		return resultArr;

	return NULL;

}