/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
Problem Code :TK
*/

#include <iostream>
#include <malloc.h>

#include <malloc.h>

struct student {
	char *name;
	int score;
};




void sortingScoresQuickSort(struct student *students, int leftIndex, int rightIndex){


	int leftHold = leftIndex;
	int rightHold = rightIndex;

	int pivot = students[leftIndex].score;
	struct student pivotStructure = students[leftIndex];
	int pivotLocation;

	while (leftIndex < rightIndex){


		while (students[rightIndex].score <= pivot && leftIndex < rightIndex)
			--rightIndex;

		if (leftIndex != rightIndex)
			students[leftIndex++] = students[rightIndex];

		while (students[leftIndex].score >= pivot && leftIndex < rightIndex)
			++leftIndex;

		if (leftIndex != rightIndex)
			students[rightIndex--] = students[leftIndex];


	}

	students[leftIndex] = pivotStructure;
	pivotLocation = leftIndex;

	if (leftHold < pivotLocation)
		sortingScoresQuickSort(students, leftHold, pivotLocation - 1);

	if (rightHold> pivotLocation)
		sortingScoresQuickSort(students, pivotLocation + 1, rightHold);

}


struct student ** topKStudents(struct student *students, int len, int K) {

	if (K <= 0 )
		return NULL;

	if (len < 0)
		return NULL;
	
	if (students == NULL)
		return NULL;

	
	
	if(K!=1){

		int temp = K;

		if (K > len){

			temp = len;

		}
		struct student **topK = (struct student**)malloc(temp*sizeof(struct student));

		sortingScoresQuickSort(students, 0, len - 1);

		int i;

		for (i = 0; i < temp; i++)
			topK[i] = &students[i];

		return topK;

	}

	else{

		struct student *singleStudent = &students[0];
		int i = 0;
		int j;

		for (j = 1; j < len; j++){

			if (students[j].score >singleStudent->score){
				singleStudent = &students[j];
				i = j;
			}
		}

		struct student **topK = (struct student**)malloc(1*sizeof(struct student));
		topK[0] = &students[i];

		return  topK;

	}


}
