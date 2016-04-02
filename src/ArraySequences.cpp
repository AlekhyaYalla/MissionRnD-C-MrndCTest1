/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int* check_ap(int *, int *, int, int *, int *, int *, int);
int* check_gp(int *, int *, int, int *, int *, int *);
int* check_ap(int *, int *b, int n, int *p, int *q, int *r, int j)
{
	int i = 0, f = 0, k;
	while (i<n - 2)
	{
		k = i;
		while (*q - *p == *r - *q&&j<4)
		{
			p++;
			q++;
			r++;
			i++;
			f++;
		}
		if (f>0 && j<4)
		{
			f = 0;
			b[j++] = k;
			b[j++] = i + 1;
		}
		else
		{
			p++;
			q++;
			r++;
			i++;
		}
	}
	return b;
}
int* check_gp(int *a, int *b, int n, int *p, int *q, int *r)
{
	int i = 0, f = 0, k;
	while (i<n - 2)
	{
		k = i;
		while ((float)*q / (*p) == (float)*r / (*q))
		{
			p++;
			q++;
			r++;
			i++;
			f++;
		}
		if (f>0)
		{
			f = 0;
			b[4] = k;
			b[5] = i + 1;
		}
		else
		{
			p++;
			q++;
			r++;
			i++;
		}
	}
	return b;
}
int * find_sequences(int *arr, int len){
	int *p, *q, *r, *b, i = 0, j = 0;
	if (arr == NULL||len<3)
		return NULL;
	b = (int*)malloc(sizeof(int) * 6);
	p = &arr[0];
	q = &arr[1];
	r = &arr[2];
	while (i<2)
	{
		b = check_ap(arr, b, len, p, q, r, j);
		i++;
	}
	p = &arr[0];
	q = &arr[1];
	r = &arr[2];
	b = check_gp(arr, b, len, p, q, r);
	return b;
}