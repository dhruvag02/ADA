#include<stdio.h>
#include<conio.h>
#include<time.h>
#define S 20
void quicksort(int arr[S],int start,int end);
int partition(int arr[S],int start,int end);
int main()
{
int n,i,arr[S];
clock_t time;
clrscr();
printf("Enter the size of array\n");
scanf("%d",&n);
printf("Enter the elements to be sorted\n");
for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
time=clock();
quicksort(arr,0,n-1);
time=clock()-time;
printf("Sorted array is displayed\n");
for(i=0;i<n;i++)
	printf("%d\n",arr[i]);
printf("Time required: %f seconds\n",(float)time/CLOCKS_PER_SEC);
getch();
return 0;
}
void quicksort(int arr[S],int start,int end)
{
int Pindex;
if(start>=end)
	return;
Pindex=partition(arr,start,end);
quicksort(arr,start,Pindex-1);
quicksort(arr,Pindex+1,end);
}
int partition(int arr[S],int start,int end)
{
int i,pivot,Pindex,temp;
pivot=arr[end];
Pindex=start;
for(i=start;i<end;i++)
{
if(arr[i]<=pivot)
{
temp=arr[i];
arr[i]=arr[Pindex];
arr[Pindex]=temp;
Pindex=Pindex+1;
}
}
temp=arr[Pindex];
arr[Pindex]=arr[end];
arr[end]=temp;
return Pindex;
}
