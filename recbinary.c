#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define S 100
int binary(int arr[S],int low,int high,int x);
int main()
{
int res,n,i,x,arr[S];
clock_t time;
printf("Enter size of array\n");
scanf("%d",&n);
int low=0,high=n-1;
printf("Enter elements in array\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter element to be searched\n");
scanf("%d",&x);
time=clock();
res=binary(arr,low,high,x);
time=clock()-time;
printf("Result of search: %d\n",res);
printf("Time required to complete Binay Search:%f seconds\n",(float)time/CLOCKS_PER_SEC);
return 0;
}
int binary(int arr[S],int low,int high,int x)
{
int mid;
if(low>high)
return -1;

mid=(low+high)/2;
if(x==arr[mid])
{
return mid;
}
else if(x<arr[mid])
{
return binary(arr,low,mid-1,x);
}
else
{
return binary(arr,mid+1,high,x);
}
}
