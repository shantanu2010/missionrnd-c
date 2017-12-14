/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

void swap(struct node* number1, struct node* number2){

	int temp = number2->num;
	number2->num = number1->num;
	number1->num = temp;
}

struct node * sortLinkedList(struct node *head) {
	
	if (head == NULL)
		return NULL;
	
	if (head->next == NULL && head!=NULL)
		return head;


	struct node * curr = head;
	struct node *temp = head;
	bool check = true;

	while (curr != NULL){

		temp = head;

		while (temp->next != NULL){

			if (temp->num > temp->next->num){

				swap(temp, temp->next);
				check = false;
			}
			temp = temp->next;
		}

		curr = curr->next;
		check = true;
	}
	
	return head;
}