#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Function to find the n x n matrix 
// that satisfies the given condition 
void findGrid(int n) 
{ 
	int arr[n][n],x; 
	int i,j,k,l;
	// Initialize x to 0 
	x = 0; 

	// Divide the n x n matrix into n / 4 matrices 
	// for each of the n / 4 rows where 
	// each matrix is of size 4 x 4 
	for ( i = 0; i < n / 4; i++) { 
		for ( j = 0; j < n / 4; j++) { 
			for ( k = 0; k < 4; k++) { 
				for ( l = 0; l < 4; l++) { 
					arr[i * 4 + k][j * 4 + l] = x; 
					x++; 
				} 
			} 
		} 
	} 

	// Print the generated matrix 
	for ( i = 0; i < n; i++) { 
		for ( j = 0; j < n; j++) { 
			printf("%d\t",arr[i][j]); 
		} 
		printf("\n"); 
	} 
} 

// Driver code 
int main() 
{ 
	int n = 4; 

	findGrid(n); 

	return 0; 
} 

