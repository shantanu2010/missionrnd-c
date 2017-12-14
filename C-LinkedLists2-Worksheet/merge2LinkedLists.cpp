/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	
	
	if (head1 == NULL)
		return head2;

	if (head2 == NULL)
		return head1;

	if (head1 == NULL && head2 == NULL)
		return NULL;



	struct node* curr1 = head1;
	struct node* curr2 = head2;
	struct node* result = NULL;
	struct node* curr = NULL;

	while (curr1 != NULL && curr2 != NULL){


		if (curr1->num < curr2->num){


			if (result == NULL){

				curr = result = curr1;

			}
			else{

				curr->next = curr1;
				curr = curr->next;

			}

			curr1 = curr1->next;

		}


		else if (curr1->num == curr2->num){


			if (result == NULL){

				curr = result = curr1;
				curr1 = curr1->next;
				curr->next = curr2;
				curr = curr->next;
				curr2 = curr2->next;

			}
			else{

				curr->next = curr1;
				curr = curr->next;
				curr1 = curr1->next;
				curr->next = curr2;
				curr = curr->next;
				curr2 = curr2->next;

			}

			

		}


		else{
		
			if (result == NULL){

				curr = result = curr2;

			}
			else{

				curr->next = curr2;
				curr = curr->next;

			}

			curr2 = curr2->next;

		}


	}

	while (curr1 != NULL){

		if(result == NULL){

			curr = result = curr1;

		}
		
		else{

		curr->next = curr1;
		curr = curr->next;

		}

	curr1 = curr1->next;

	}

	while (curr2 != NULL){

		if (result == NULL){

			curr = result = curr2;

		}

		else{

			curr->next = curr2;
			curr = curr->next;

		}

		curr2 = curr2->next;

	}



	curr->next = NULL;
	return result;




	
}
