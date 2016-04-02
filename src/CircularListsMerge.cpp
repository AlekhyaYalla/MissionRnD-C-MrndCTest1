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
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2){

	int i = 1;
	if (head1 == '\0'&&head2 == '\0')
		return -1;
	node **curr1, **curr2, **curr, **t;
	curr1 = head1;
	curr2 = head2;
	t = head2;
	curr = curr1;
	while (curr1 != '\0'&&curr2 != '\0')
	{
		while ((*curr1)->data<(*curr2)->data&&(*curr1)->next != '\0')
		{
			*curr = *curr1;
			*curr1 = (*curr1)->next;
			i++;
		}
		if ((*curr1)->data >= (*curr2)->data)
		{
			if (*curr1 == *head1)
				*head1 = *curr2;
			else
				(*curr)->next = *curr2;
			*t = (*curr2)->next;
			(*curr2)->next = *curr1;
			*curr = *curr2;
			i++;
		}
		else if ((*curr1)->next == '\0')
		{
			(*curr1)->next = *curr2;
			while ((*curr2)->next != *head2)
				i++;
			(*curr2)->next = *head1;
			return i;
		}
		(*curr2) = *t;
	}
	(*curr2)->next = *head1;
	return i;
}
