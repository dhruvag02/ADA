#include<stdio.h>
#include<stdlib.h>
#define S 10
void inversion(int arr[],int n);
int main()
{
	int n,arr[S],i;
	scanf("%d",&n);
	printf("Enter elements in the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	inversion(arr,n);
	return 0;
}
void inversion(int arr[],int n)
{
	int i,j,count=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
				count=count+1;
		}
	}
	printf("Total inversion in array= %d\n",count);
}
OUTPUT
5                                                                                                                                    
Enter elements in the array                                                                                                          
1 20 6 4 5                                                                                                                           
Total inversion in array= 5
