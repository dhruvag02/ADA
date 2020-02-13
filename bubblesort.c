#include<stdio.h>
#define S 100
#include<time.h>
void sort(int arr[S],int n);
int main()
{
int arr[S],i,j,n,k;
clock_t time;
printf("Enter number of elements to be inserted in array\n");
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
time=clock();
sort(arr,n);
time=clock()-time;
printf("Time required to complete bubble sort:%f seconds\n",(float)time/CLOCKS_PER_SEC);
printf("Elements in sorted order\n");
for(i=0;i<n;i++)
{
printf("%d\n",arr[i]);
}
printf("Enter number 'k' to view k largest elements\n");
scanf("%d",&k);
printf("*******\n");
for(j=n-1;k>0;j--)
{
printf("%d\n",arr[j]);
k--;
}
return 0;
}

void sort(int arr[S],int n)
{

int p=0,q;
int temp;
	while(p!=n-1)
	{
	q=p+1;
		while(q!=n)
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

