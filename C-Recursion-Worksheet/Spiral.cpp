/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include <stdlib.h>




void spiralRecur(int rows, int columns, int* result, int** input_array,int walker,int resultIndex){

	int i;

	if (rows < 1 || columns < 1)
		return;

	
	if (rows == 1){
		for (i = 0; i < columns; i++)
			result[resultIndex++] = input_array[walker][walker + i];
		return;
	}

	if (columns == 1){
		for (i = 0; i < rows; i++)
			result[resultIndex++] = input_array[walker+i][walker];
		return;
	}

	
	for (i = 0; i < columns - 1; i++)
		result[resultIndex++] = input_array[walker][walker + i];
	
	for (i = 0; i < rows - 1; i++)
		result[resultIndex++] = input_array[walker+i][columns-1+walker];
	
	for (i = 0; i < columns - 1; i++)
		result[resultIndex++] = input_array[walker+rows-1][walker+columns-1-i];

	for (i = 0; i < rows - 1; i++)
		result[resultIndex++] = input_array[rows - 1 - i+walker][walker];

	spiralRecur(rows - 2, columns - 2, result, input_array, walker + 1, resultIndex);

}


int* spiral(int rows, int columns, int **input_array){
	

	if (rows < 1 || columns < 1)
		return NULL;


	if (input_array == NULL)
		return NULL;

	int* result = (int*)malloc(rows*columns*sizeof(int));


	spiralRecur(rows, columns, result, input_array,0,0);

	return result;




	return NULL;
}


