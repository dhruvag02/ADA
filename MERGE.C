#include<stdio.h>
#include<conio.h>
#define S 10
void merge(int low,int mid,int high,int arr[S]);
void mergesort(int low,int high,int arr[S]);
int main()
{
int n,arr[S],i;
int mid,low,high;
clrscr();
printf("Enter the size of array\n");
scanf("%d",&n);
printf("Enter the elements in the array\n");
for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
low=0;
high=n-1;
mergesort(low,high,arr);
printf("Sorted array is displayed\n");
for(i=0;i<n;i++)
	printf("%d\n",arr[i]);
getch();
return 0;
}

void mergesort(int low,int high,int arr[S])
{
int mid;
if(low<high)
{
	mid=low+(high-low)/2;
	mergesort(low,mid,arr);
	mergesort(mid+1,high,arr);
	merge(low,mid,high,arr);
}
}
void merge(int low,int mid,int high,int arr[S])
{
int i,j,k;
int a[S];
i=low;
j=mid+1;
k=low;
while(i<=mid && j<=high)
{
	if(arr[i]<arr[j])
	{
		a[k]=arr[i];
		k=k+1;
		i=i+1;
	}
	else
	{
		a[k]=arr[j];
		k=k+1;
		j=j+1;
	}
}
while(i<=mid)
{
	a[k]=arr[i];
	k=k+1;
	i=i+1;
}
while(j<=high)
{
	a[k]=arr[j];
	k=k+1;
	j=j+1;
}
for(i=low;i<=high;i++)
	arr[i]=a[i];
}

OUTPUT

Enter the size of array
8
Enter the elements in the array
38
27
43
3
9
82
10
12
Sorted array is displayed
3
9
10
12
27
38
43
82
