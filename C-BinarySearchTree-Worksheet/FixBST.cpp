/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};


int getMaxiF1(int* number1, int number2){

	if (*number1 >= number2)
		return *number1;

	return number2;

}

int powerF1(int num, int power){

	int i = 0;
	int result = 1;

	for (i = 0; i < power; i++)
		result = result * num;

	return result;
}

void getHeightRecF1(struct node* root, int* length, int count){

	if (root == NULL)
		return;


	if (root->left == NULL && root->right == NULL)
		return;


	count++;

	*length = getMaxiF1(length, count);

	getHeightRecF1(root->left, length, count);
	getHeightRecF1(root->right, length, count);



}


int get_heightFunc1(struct node *root){

	if (root == NULL)
		return -1;

	int length = 0;
	int count = 0;

	getHeightRecF1(root, &length, count);

	return length + 1;
}


void swapNodes(int i1,int i2,int* arr){

	int temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;

}


void inorderTrav(struct node* root, int* arr, int* i){

	if (root == NULL)
		return;

	inorderTrav(root->left, arr, i);
	arr[*i] = root->data;
	*i = *i + 1;
	inorderTrav(root->right, arr, i);


}

int getBlackSheepLeft(int* arr,int len){

	int i = 0;

	for (i; i < len - 1; i++){
		
		if (arr[i] > arr[i + 1])
			
			return i;
	}
	
	return -1;

}

int getBlackSheepRight(int* arr, int len){

	int i = len-1;

	for (i; i > 0; i--){
		
		if (arr[i] < arr[i - 1])
			return i;
	}
	return -1;

}

void getAddresses(struct node* root,int* arr,int* i){

	if (root == NULL)
		return;

	getAddresses(root->left, arr, i);
	if (arr[*i] == root->data){
		
		*i = *i + 1;
	}
	else{

		root->data = arr[*i];
		*i = *i + 1;

	}
	
	getAddresses(root->right, arr, i);

}

void fix_bst(struct node *root){
	
	if (root == NULL)
		return;

	int h = get_heightFunc1(root);
	int getSize = powerF1(2, h);

	int* arr = (int*)calloc(getSize-1 , sizeof(int));

	int i = 0;
	int j = 0;
	inorderTrav(root, arr, &i);

	int temp1 = getBlackSheepLeft(arr,i);
	int temp2 = getBlackSheepRight(arr,i);

	if (temp1 != -1 && temp2 != -1){
		swapNodes(temp1,temp2,arr);
		getAddresses(root, arr, &j);
		
	}



}


