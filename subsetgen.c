/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// CPP program to print all permutations using 
// Johnson and Trotter algorithm. 

#include <stdio.h> 
#include <math.h>
#define S 10

void printPowerSet(int *set, int set_size) 
{ 
	/*set_size of power set of a set with set_size 
	n is (2**n -1)*/
	unsigned int pow_set_size = pow(2, set_size); 
	int counter, j; 

	/*Run from counter 000..0 to 111..1*/
	for(counter = 0; counter < pow_set_size; counter++) 
	{ 
	for(j = 0; j < set_size; j++) 
	{ 
		/* Check if jth bit in the counter is set 
			If set then print jth element from set */
		if(counter & (1<<j)) 
			printf("%d", set[j]); 
	} 
	printf("\n"); 
	} 
} 

/*Driver program to test printPowerSet*/
int main() 
{ 
	//int set[] = {1, 2, 3};
	int n,set[S],i;
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	    scanf("%d",&set[i]);
	printPowerSet(set, n); 
	return 0; 
} 

OUTPUT
2                                                                                                                                      
Enter the elements                                                                                                                     
1 2                                                                                                                                    
                                                                                                                                       
1                                                                                                                                      
2                                                                                                                                      
12
