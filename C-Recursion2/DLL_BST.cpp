/*
Given a Sorted Doubly Linked List and a Binary Search Tree , 
Check if they are identical or not .
The DLL will have nodes of type node_dll

Note :
	A DLL can be represented as a BST in many forms ,
	And if a dll and any one of the forms is given as input you
	need to return 1 otherwise 0.

	->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

	Example 0:
	
	DLL:1->5->8

	BST(All 3 return 1):

	  5         8      1
	 / \       /        \
    1   8     5          5
               \
                8

		Returns 1


Example 1:
	
		DLL : 1->5
		
		BST :
			5
			 \
			  10
		
		Returns 0

Example 2:

	DLL:1->3->5-9->11
	
		BST:
		
		 5
		/ \
	   1   11
		\  /
		3 9

	Returns 1


Example 3:
	
	DLL: 1->5->7->10->12->15->20
		
		BST:
		
		  10
		 /   \
	    5    15
	   / \   / \
	  1  7  12 20
Returns 1

Note 2 :
	Unequal Length BST and DLL should return 0;
	Return -1 for NULL inputs

*/

#include<stdio.h>
#include<stdlib.h>



struct node_dll {
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};

struct node_bst {
	int data;
	struct node_bst *left;
	struct node_bst *right;
};


int check(struct node_bst* root, int data){


	if (root == NULL)
		return 0;

	if (root->data == data)
		return 1;

	else if (root->data > data)
		return check(root->left, data);

	else if (root->data < data)
		return check(root->right, data);


}


int identical(struct node_dll* head, struct node_bst*root){

	while (head != NULL){

		int c = check(root, head->data);

		if (c == 1){

			head = head->next;
			continue;

		}

		else
			return 0;
	}

	return 1;
}







int getLengthDll(struct node_dll* temp, int* lowest, int* highest,bool* duplicate){

	int count = 1;
	
	while (temp->next != NULL){

		if (temp->data == temp->next->data)
			*duplicate = true;

		count++;

		if (temp->data < *lowest)
			*lowest = temp->data;

		else if (temp->data>*highest)
			*highest = temp->data;

		temp = temp->next;
	}

	return count;

}




int find(struct node_bst* bst, struct node_dll* dll, int* lowest, int* highest){

	if (bst->data == dll->data)
		return 1;

	if (bst->data<*lowest || bst->data>*highest)
		return 0;

	struct node_dll* temp = dll;

	/*
	while (temp->data != bst->data && temp != NULL){


	if (bst->data > temp->prev->data && bst->data < temp->next->data && temp->data!=bst->data)
	return 0;

	if (temp->data < bst->data)
	temp = temp->next;

	else
	temp = temp->prev;

	}

	return 0;
	*/


	if (dll->data<bst->data){

		while (temp->data < bst->data && temp != NULL){

			temp = temp->next;
		}

		if (bst->data == temp->data)
			return 1;

		else
			return 0;

	}

	else{

		while (temp->data > bst->data && temp != NULL){

			temp = temp->prev;
		}

		if (bst->data == temp->data)
			return 1;
		else
			return 0;


	}

	return 0;


}


void printInorder(struct node_bst* bst, struct node_dll* dll, int* temp, bool* flag, int* lowest, int* highest){

	if (bst->left != NULL && *flag){

		if (dll->prev != NULL)
			printInorder(bst->left, dll->prev, temp, flag, lowest, highest);

		else
			printInorder(bst->left, dll, temp, flag, lowest, highest);
	}


	*temp = find(bst, dll, lowest, highest);

	if (*temp == 0){

		*flag = false;
		return;
	}

	if (bst->right != NULL && *flag){

		if (dll->next != NULL)
			printInorder(bst->left, dll->next, temp, flag, lowest, highest);

		else
			printInorder(bst->left, dll, temp, flag, lowest, highest);

	}

}



/*

void printInorder(struct node_dll* dll, struct node_bst* bst,int* count,bool* flag){


if (bst->left != NULL){

printInorder(dll, bst->left,count,flag);

}

if (bst->data == dll->data){

*count = *count + 1;
*dll = *(dll)->next;
}
else{

*flag = false;
return;
}


if (bst->right != NULL)
printInorder(dll, bst->right, count, flag);


}

*/


int is_identical(struct node_dll *head, struct node_bst *root) {

	if (head == NULL || root == NULL)
		return -1;

	struct node_dll* temp = head;

	int lowest = INT_MAX;
	int highest = INT_MIN;

	bool duplicate = false;

	int len = getLengthDll(temp, &lowest, &highest,&duplicate);

	if (duplicate)
		return 0;

	int i = 1;

	struct node_dll* dll = head;
	struct node_bst* bst = root;

	struct node_dll* temp2 = head;
	struct node_bst* temp3 = root;

	int kcheck = identical(temp2, temp3);

	if (kcheck == 0)
		return 0;

	//globalNode = head;
	bool flag = true;

	while (dll->data < bst->data && dll != NULL){

		dll = dll->next;
	}

	if (dll == NULL)
		return 0;

	if (bst->data > dll->data || bst->data != dll->data)
		return 0;

	if (dll->data = bst->data)
		printInorder(bst, dll, &i, &flag, &lowest, &highest);

	else
		return 0;

	if (flag == true)
		return 1;

	return 0;
}

