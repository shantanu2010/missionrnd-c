/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

//Use this function , Dont create any new function with name createNode or createList
struct node * createNodeDummy(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	
	if (head == NULL)
		return NULL;

	if (K<=0)
		return NULL;

	
	//struct node *curr;
	struct node *newNode;

	//if (K == 1 || K == 0)
		//return NULL;

	int index = 1;

	struct node* curr = head;

	while (curr != NULL){
		
		if ((index) % K == 0){

			struct node* newNode = createNodeDummy(K);
			newNode->next = curr->next;
			curr->next = newNode;
			curr = curr->next;
		}
		index++;
		curr = curr->next;
	}

	return head;

}
