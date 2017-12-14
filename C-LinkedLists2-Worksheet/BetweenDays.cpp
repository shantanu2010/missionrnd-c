/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

struct Date{

	int day;
	int month;
	int year;
};

int getLeapCount(Date* d){

	int totalYears = d->year;

	if (d->month <= 2)
		totalYears--;

	int years = (totalYears / 4)+(totalYears/400);

	years -= (totalYears / 100);

	return years ;
}

int compute(Date* dt1, Date* dt2){

	int daysInAMonth[12] = { 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31 };

	long long int days1 = dt1->year * 365 + dt1->day - 1;
	long long int days2 = dt2->year * 365 + dt2->day - 1;
	int i = 0;

	while (i < dt1->month - 1){

		days1 += daysInAMonth[i];
		i++;

	}

	i = 0;

	while (i < dt2->month - 1){

		days2 += daysInAMonth[i];
		i++;

	}

	days1 += getLeapCount(dt1);
	days2 += getLeapCount(dt2);

	return (days1 - days2);
}



int between_days(struct node *date1head, struct node *date2head){
	

	if (date1head == NULL || date2head == NULL)
		return -1;



	struct node* d1 = date1head;
	struct node* d2 = date2head;

	Date* date1 = (Date*)malloc(sizeof(Date));
	Date* date2 = (Date*)malloc(sizeof(Date));

	date1->day = ((d1->data) * 10 + (d1->next->data));
	date1->month = ((d1->next->next->data) * 10 + (d1->next->next->next->data));
	date1->year = ((d1->next->next->next->next->data) * 1000 + (d1->next->next->next->next->next->data) * 100 + (d1->next->next->next->next->next->next->data) * 10 + (d1->next->next->next->next->next->next->next->data));

	date2->day = ((d2->data) * 10 + (d2->next->data));
	date2->month = ((d2->next->next->data) * 10 + (d2->next->next->next->data));
	date2->year = ((d2->next->next->next->next->data) * 1000 + (d2->next->next->next->next->next->data) * 100 + (d2->next->next->next->next->next->next->data) * 10 + (d2->next->next->next->next->next->next->next->data));

	
	if (date1->day == date2->day && date1->month == date2->month && date1->year == date2->year)
		return 0;

	int result = compute(date1, date2);

	if (result < 0)
		result *= -1;

	return result-1;

}