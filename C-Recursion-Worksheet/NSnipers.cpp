/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include<stdlib.h>
#include "stdafx.h"

bool canBePlaced(int** battlefield, int row, int col, int N){
	int i, j;

	
	for (i = 0; i < col; i++)
		if (battlefield[row][i])
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (battlefield[i][j])
			return false;

	
	for (i = row, j = col; j >= 0 && i<N; i++, j--)
		if (battlefield[i][j])
			return false;

	return true;
}

bool solveNSnipersRecursion(int** battlefield, int col, int N){
	
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++){

		if (canBePlaced(battlefield, i, col, N)){

			battlefield[i][col] = 1;
			
			if (solveNSnipersRecursion(battlefield, col + 1, N))
				return true;

			battlefield[i][col] = 0;
		}
	}

	return false;
}

int solve_nsnipers(int *battlefield, int n){

	if (battlefield == NULL)
		return 0;

	if (n < 1)
		return 0;

	int i, j;
	int** tBoard = (int**)calloc(n,sizeof(int*));
	for (i = 0; i < n; i++)
		tBoard[i] = (int*)calloc(n,sizeof(int));

	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			*((battlefield + i*n) + j) = tBoard[i][j];


	if (solveNSnipersRecursion(tBoard, 0,n)== false){

		return 0;
	}

	
	return 1;

}
