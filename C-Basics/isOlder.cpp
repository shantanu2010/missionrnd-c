/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/


#include<stdio.h>

int calcYear(char *dob){

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

int calcMonth(char *dob){

	int month;
	int i = 3;

	month = (int)dob[i] - 48;

	month = month * 10 + (int)dob[i + 1] - '0';

	if (month < 0 || month >12)
		
		return -1;
	
	else
		return month;

}

int calcDay(char *dob, int month){

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


int isOlder(char *dob1, char *dob2) {
	
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

	year1 = calcYear(dob1);
	year2 = calcYear(dob2);

	month1 = calcMonth(dob1);
	month2 = calcMonth(dob2);


	if (month1 == -1 || month2 == -1)
		return -1;

	day1 = calcDay(dob1, month1);
	day2 = calcDay(dob2, month2);

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
