/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int getMaxiF(int* number1, int number2){

	if (*number1 >= number2)
		return *number1;

	return number2;

}

void getHeightRecF(struct node* root, int* length, int count){

	if (root == NULL)
		return;


	if (root->left == NULL && root->right == NULL)
		return;


	count++;

	*length = getMaxiF(length, count);

	getHeightRecF(root->left, length, count);
	getHeightRecF(root->right, length, count);



}


int get_heightFunc(struct node *root){

	if (root == NULL)
		return -1;

	int length = 0;
	int count = 0;

	getHeightRecF(root, &length, count);

	return length + 1;
}



void compute(struct node* root, int *arr, int height,int *index){

	if (root == NULL)
		return;

	if (height == 0){

		arr[*index] = root->data;
		(*index)++; 
		return;
	}

	compute(root->right, arr, height - 1, index);
	compute(root->left , arr, height - 1, index);
	
}

void BSTRighttoLeftRec(struct node* root, int *arr, int *j){

	int height = get_heightFunc(root);

	int index = 0;

	for (index; index < height; index++)
		compute(root, arr, index,j);

}


int powerF(int num, int power){

	int i = 0;
	int result = 1;

	for (i = 0; i < power; i++)
		result = result * num;

	return result;
}

int* BSTRighttoLeftRows(struct node* root){

	if (root == NULL)
		return NULL;

	int height = get_heightFunc(root);
	int getSize = powerF(2, height);

	int j = 0;
	int *resArray = (int*)calloc(getSize-1,sizeof(int));

	BSTRighttoLeftRec(root, resArray, &j);

	return resArray;
}