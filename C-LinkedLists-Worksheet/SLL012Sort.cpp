/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){
	
	if (*head == NULL || (*head)->next == NULL)
		return;


	int zeros = 0;
	int ones = 0;
	int twos = 0;
	int count = 0;

	struct node* curr = *head;

	while (curr != NULL){

		if ((curr->data) == 0)
			zeros++;

		else if ((curr->data) == 1)
			ones++;

		else
			twos++;

		count++;
	}

	while (count != 0){


		if (zeros != 0){

			(*head)->data = 0;
			(*head) = (*head)->next;
		}

		else if (ones != 0){

			(*head)->data = 1;
			(*head) = (*head)->next;

		}

		else{

			(*head)->data = 2;
			(*head) = (*head)->next;
		}

		count--;

	}

}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head){

	if ((*head) == NULL)
		return;

	int i = 0;
	int count = 1;

	node *next = *head;
	node *prev = *head;
	node* last = *head;
	node* temp = next;

	while (last->next!= NULL){

		last = last->next;
		count++;
	}

	node *tail = last;
	
	while(i<count){

		temp = next;
		next = next->next;
		
		if (temp->data == 0){

			if (prev != temp){

				temp->next = *head;
				*head = temp;
				prev->next = next;
			}
		}
		else if (temp->data == 2){

			tail->next = temp;
			temp->next = NULL;
			tail = temp;

			if (prev == temp)
				*head = prev = next;
			else
				prev->next = next;
		}

		else{
			if (prev != temp)
				prev = prev->next;
		}
		i++;
	}
}
