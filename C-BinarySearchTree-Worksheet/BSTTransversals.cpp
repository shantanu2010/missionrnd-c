/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder_rec(struct node* root, int* arr, int* i){

	if (root == NULL)
		return;

	inorder_rec(root->left, arr,i);
	arr[*i] = root->data;
	*i = *i + 1;
	inorder_rec(root->right, arr,i);


}

void preorder_rec(struct node* root, int* arr, int* i){

	if (root == NULL)
		return;

	arr[*i] = root->data;
	*i = *i + 1;
	preorder_rec(root->left, arr, i);
	preorder_rec(root->right, arr, i);


}

void postorder_rec(struct node* root, int* arr, int* i){

	if (root == NULL)
		return;

	postorder_rec(root->left, arr, i);
	postorder_rec(root->right, arr, i);
	arr[*i] = root->data;
	*i = *i + 1;

}


void inorder(struct node *root, int *arr){

	
	if (root == NULL || arr == NULL)
		return;

	int i = 0;
	inorder_rec(root, arr, &i);
	
	
}
void preorder(struct node *root, int *arr){


	if (root == NULL || arr == NULL)
		return;

	int i = 0;
	preorder_rec(root, arr, &i);
	
}
void postorder(struct node *root, int *arr){
	

	if (root == NULL || arr == NULL)
		return;

	int i = 0;
	postorder_rec(root, arr, &i);
}

