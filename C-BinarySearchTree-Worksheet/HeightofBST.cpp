/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int getMaxi(int* number1, int number2){

	if (*number1 >= number2)
		return *number1;

	return number2;

}

void getHeightRec(struct node* root, int* length,int count){

	if (root == NULL)
		return;


	if (root->left == NULL && root->right == NULL)
		return;


	count++;

	*length = getMaxi(length,count);

	getHeightRec(root->left, length, count);
	getHeightRec(root->right, length, count);



}


int getSum(struct node* root){

	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return root->data;

	return root->data + getSum(root->left) + getSum(root->right);

}


int get_height(struct node *root){

	if (root == NULL)
		return -1;

	int length = 0;
	int count = 0;

	getHeightRec(root, &length,count);

	return length+1;
}

int get_left_subtree_sum(struct node *root){
	
	if (root == NULL)
		return -1;


	if (root->left == NULL)
		return 0;

	int length = getSum(root->left);

	return length;


}

int get_right_subtree_sum(struct node *root){
	
	if (root == NULL)
		return -1;


	if (root->right == NULL)
		return 0;

	int length = getSum(root->right);

	return length;
}

