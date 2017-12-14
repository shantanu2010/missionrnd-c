/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};



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

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	
	if (Arr == NULL)
		return -1;
	
	if (len <= 0)
		return -1;

	int index = 0;
	while (date[index++] != '\0');

	if (index != 11)
		return -1;

	int day;
	int month;
	int year;
	int tempDay;
	int tempMonth;
	int tempYear;

	int count = 0;
	
	year = calcYear(date);
	month = calcMonth(date);

	index = len-1;
	
	if (month == -1)
		return -1;

	day = calcDay(date, month);
	
	while (index >= 0){

		tempYear = calcYear(Arr[index].date);
		tempMonth = calcMonth(Arr[index].date);
		tempDay = calcDay(Arr[index].date, tempMonth);

		if (year < tempYear){
			count++;
			index--;
			continue;
		}
		else if (year > tempYear){
			index--;
			continue;

		}
		else if (year == tempYear){

			if (month < tempMonth){
				count++;
				index--;
				continue;
			}
			else if (month > tempMonth){
				index--;
				continue;

			}
			else if (month == tempMonth){


				if (day < tempDay){
					count++;
					index--;
					continue;
				}
				else if (day > tempDay){

					index--;
					continue;
				}
				else if (day == tempDay){

					index--;
					continue;

				}
			}



		}

	}
	
	return count;
}
