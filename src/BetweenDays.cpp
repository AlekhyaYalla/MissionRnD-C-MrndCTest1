/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct node{
	int data;
	struct node *next;
};

int exp(int);
void get_int(node *temp1,node *temp2, int *x1, int *x2,int i)
{
	while (i >0)
	{
		*x1 = *x1 + (temp1->data) * exp(i);
		*x2 = *x2 + (temp2->data)* exp(i);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}
int between_days(struct node *head1, struct node *head2){

	int i = 0,d1=0,d2=0,m1=0,m2=0,y1=0,y2=0;
	if (head1 == NULL || head2 == NULL)
		return -1;
	node *temp1,*temp2;
	temp1 = head1;
	temp2 = head2;
	get_int(temp1, temp2, &d1, &d2, 1);
	get_int(temp1, temp2, &m1, &m2, 1);
	get_int(temp1, temp2, &y1, &y2, 3);
	if (d1 == d2&&m1 == m2&&y1 == y2)
		return 0;
	else
	{
		if (y1 == y2)
		{
			if (m1 == m2)
				return d2 - d1;
			else
			{
				while (m1 != m2)
				{
					if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)
					{
						i = (i + 31) - d1;
						m1++;
					}
				}
				if (m1 == m2)
					i = i + d2;
			}
		}
		else
		{
			while (y1 < y2)
			{
				if (y1 % 4 == 0)
					i = i + 1;
				i = i + 365;
				y1++;
			}
			if (y1 == y2)
			{
				while (m1 != m2)
				{
					if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)
					{
						i = (i + 31) - d1;
						m1++;
					}
				}
				if (m1 == m2)
					i = i + d2;
			}
		}

	}
}
int exp(int j)
{
	int s = 1;
	while (j>0)
	{
		s = s * 10;
		j--;
	}
	return s;
}
