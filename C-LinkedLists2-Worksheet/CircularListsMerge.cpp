/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

void swapping(struct node* number1, struct node* number2){

	int temp = number2->data;
	number2->data = number1->data;
	number1->data = temp;
}



int merge_circularlists(struct node **head1, struct node **head2){
	
	if (*head1 == NULL && *head2 == NULL)
		return -1;

	int count = 0;
	
	struct node* temp = *head1;
	struct node* curr = *head1;

	while (*head1 != temp->next){

		count++;
		temp = temp->next;

	}
	count++;
	temp->next = *head2;
	temp = *head2;
	count++;
	
	while (*head2 != temp->next){

		count++;
		temp = temp->next;

	}

	temp->next = *head1;

	while (curr->next != *head1){

		temp = curr->next;

		while (temp!= *head1){

			if (temp->data < curr->data)
				swapping(temp, curr);
				
			temp = temp->next;
		}

		curr = curr->next;		
	}

	return count;

}