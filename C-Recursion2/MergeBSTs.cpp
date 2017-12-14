/*
Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.
	Example 1:

	Input :
	20        25
	/  \      /  \
	5    30   10   35
	Output :

	Bst 1 :
	20
	/   \
	5     30
	\   /  \
	10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,
Any 1 of those correct ways would be fine .

Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs
If an element of BST2 is already in BST 1, then BST2 node is ignored.

(Both r1 and r2 shouldnt be NULL at the time of Input)
Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.
You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard

*/
#include <stdlib.h>
#include <stdio.h>

struct BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;
};



void merging(struct BstNode** root1, struct BstNode* root2){


	if (root2->data == (*root1)->data)
		return;
	
	if (root2->data < (*root1)->data){

		if ((*root1)->left != NULL){
			//*root1 = (*root1)->left;
			root1 = &((*root1)->left);
			merging(root1, root2);
		}

		else{
			
			struct BstNode* tempe = root2;
			tempe->left = NULL;
			tempe->right = NULL;
			(*root1)->left = tempe;
			

		}
	}

	else{


		if ((*root1)->right != NULL){
			//*root1 = (*root1)->right;
			root1 = &((*root1)->right);
			merging(root1, root2);
		}

		else{
			
			struct BstNode* tempe = root2;
			tempe->left = NULL;
			tempe->right = NULL;
			(*root1)->right = tempe;
			
		}
	}

}

void mergeTwoBstRec(struct BstNode** root1, struct BstNode* root2){


	if (root2->left != NULL)

		mergeTwoBstRec(root1,root2->left);

	if (root2->right != NULL)

		mergeTwoBstRec(root1, root2->right);


	
	struct BstNode** temp = root1;

	merging(temp, root2);


	
	
}

void merge_two_bst(struct BstNode **root1, struct BstNode *root2) {


	if (root2 == NULL || root1 == NULL)
		return;


	if (*root1 == NULL){

		*root1 = root2;
		return;

	}
	else

		mergeTwoBstRec(root1, root2);

}