/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	
	if (head == NULL)
		return NULL;

	if (K<0)
		return NULL;

	if (K == 1 || K == 0)
		return NULL;

	//int temp = K;
	int index = 1;
	
	struct node* curr = head;

	while (curr != NULL){

		if ((index+1)%K==0 && curr->next != NULL){
			
			curr->next = curr->next->next;
			index++;	
		}
		index++;
		curr = curr->next;
	}

	return head;

}