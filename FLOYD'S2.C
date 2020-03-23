#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 
int countOne(int n) 
{ 
	int count = 0; 
	while (n) { 
		n = n & (n - 1); 
		count++; 
	} 

	if (count % 2 == 0) 
		return 1; 
	else
		return 0; 
} 
 
int sumDigits(int n) 
{ 
	int sum = 0; 
	while (n != 0) { 
		sum += n % 10; 
		n /= 10; 
	} 

	return sum; 
} 
 
int main() 
{ 
	int arr[20],i,n;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);  
	int total_sum = 0; 
 
	for (int i = 0; i < n; i++) { 
		if (countOne(arr[i])) 
			total_sum += sumDigits(arr[i]); 
	} 

	printf("Sum=%d\n",total_sum);
	return 0; 
} 

