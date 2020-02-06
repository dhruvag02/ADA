#include<stdio.h>
#include<stdlib.h>
void sort(int arr[10],int s);
void search(int arr[10],int l,int u,int x);
int main()
{
int arr[10],i,x,l=0,u=9;
printf("Enter 10 elements in the array");
for(i=0;i<10;i++)
{
scanf("%d",&arr[i]);
}
sort(arr,9);
for(i=0;i<10;i++)
{
printf("%d\n",arr[i]);
}
printf("Enter the number to be searched\n");
scanf("%d",&x);
search(arr,l,u,x);
return 0;
}

void sort(int arr[10],int s)
{
int p=0,q;
int temp;
	while(p!=s-1)
	{
	q=p+1;
		while(q!=s)
		{
			if(arr[p]>arr[q])
			{
			temp=arr[p];
			arr[p]=arr[q];
			arr[q]=temp;
			}
		q++;
		}
	p++;
	}
}

void search(int arr[10],int l,int u,int x)
{
int rem;
while(l<=u)
{
	rem=(l+u)/2;
	if(arr[rem]==x)
	{
	printf("Key found at position %d\n",rem);
	return;
	}
	else if(arr[rem]<x)
	{
	l=rem+1;
	}
	else
	u=rem-1;
}
printf("Key not found\n");
return;
}



