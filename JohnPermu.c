/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// CPP program to print all permutations using 
// Johnson and Trotter algorithm. 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void swap(int *,int *);
bool LEFT_TO_RIGHT = true; 
bool RIGHT_TO_LEFT = false; 

// Utility functions for finding the 
// position of largest mobile integer in a[]. 
int searchArr(int a[], int n, int mobile) 
{ 
    int i;
	for (i = 0; i < n; i++) 
		if (a[i] == mobile) 
		return i + 1; 
} 

// To carry out step 1 of the algorithm i.e. 
// to find the largest mobile integer. 
int getMobile(int a[], bool dir[], int n) 
{ 
	int mobile_prev = 0, mobile = 0;
	int i;
	for (i = 0; i < n; i++) 
	{ 
		// direction 0 represents RIGHT TO LEFT. 
		if (dir[a[i]-1] == RIGHT_TO_LEFT && i!=0) 
		{ 
			if (a[i] > a[i-1] && a[i] > mobile_prev) 
			{ 
				mobile = a[i]; 
				mobile_prev = mobile; 
			} 
		} 

		// direction 1 represents LEFT TO RIGHT. 
		if (dir[a[i]-1] == LEFT_TO_RIGHT && i!=n-1) 
		{ 
			if (a[i] > a[i+1] && a[i] > mobile_prev) 
			{ 
				mobile = a[i]; 
				mobile_prev = mobile; 
			} 
		} 
	} 

	if (mobile == 0 && mobile_prev == 0) 
		return 0; 
	else
		return mobile; 
} 

// Prints a single permutation 
int printOnePerm(int a[], bool dir[], int n) 
{ 
	int mobile = getMobile(a, dir, n); 
	int pos = searchArr(a, n, mobile); 
    int i;
	// swapping the elements according to the 
	// direction i.e. dir[]. 
	if (dir[a[pos - 1] - 1] == RIGHT_TO_LEFT) 
	swap(&a[pos-1], &a[pos-2]); 

	else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT) 
	swap(&a[pos], &a[pos-1]); 

	// changing the directions for elements 
	// greater than largest mobile integer. 
	for (i = 0; i < n; i++) 
	{ 
		if (a[i] > mobile) 
		{ 
			if (dir[a[i] - 1] == LEFT_TO_RIGHT) 
				dir[a[i] - 1] = RIGHT_TO_LEFT; 
			else if (dir[a[i] - 1] == RIGHT_TO_LEFT) 
				dir[a[i] - 1] = LEFT_TO_RIGHT; 
		} 
	} 

	for (i = 0; i < n; i++) 
		printf("%d",a[i]); 
	printf(" "); 
} 

// To end the algorithm for efficiency it ends 
// at the factorial of n because number of 
// permutations possible is just n!. 
int fact(int n) 
{ 
	int res = 1;
	int i;
	for (i = 1; i <= n; i++) 
		res = res * i; 
	return res; 
} 

// This function mainly calls printOnePerm() 
// one by one to print all permutations. 
void printPermutation(int n) 
{ 
    int i;
	// To store current permutation 
	int a[n]; 

	// To store current directions 
	bool dir[n]; 

	// storing the elements from 1 to n and 
	// printing first permutation. 
	for (i = 0; i < n; i++) 
	{ 
		a[i] = i + 1; 
		printf("%d",a[i]); 
	} 
	printf("\n"); 

	// initially all directions are set 
	// to RIGHT TO LEFT i.e. 0. 
	for (i = 0; i < n; i++) 
		dir[i] = RIGHT_TO_LEFT; 

	// for generating permutations in the order. 
	for (i = 1; i < fact(n); i++) 
		printOnePerm(a, dir, n); 
} 

// Driver code 
int main() 
{ 
	int n = 4; 
	printPermutation(n); 
	return 0; 
} 
void swap(int *num1,int *num2)
{
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}

OUTPUT

Enter number
4
1234
1 2 4 3
1 4 2 3
4 1 2 3
4 1 3 2
1 4 3 2
1 3 4 2
1 3 2 4
3 1 2 4
3 1 4 2
3 4 1 2
4 3 1 2
4 3 2 1
3 4 2 1
3 2 4 1
3 2 1 4
2 3 1 4
2 3 4 1
2 4 3 1
4 2 3 1
4 2 1 3
2 4 1 3
2 1 4 3
2 1 3 4
