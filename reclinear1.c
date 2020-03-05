#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define S 100

int linear(int arr[S],int l,int r,int x);
int main()
{
int res,n,i,x,arr[S];
clock_t time;
printf("Enter size of array\n");
scanf("%d",&n);
printf("Enter elements in array\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter element to be searched\n");
scanf("%d",&x);
time=clock();
res=linear(arr,0,n-1,x);
time=clock()-time;
printf("Result of search: %d\n",res);
printf("Time required to complete Binay Search:%f seconds\n",(float)time/CLOCKS_PER_SEC);
return 0;
}

int linear(int arr[S],int l,int r,int x)
{
if(r<1)
return -1;
if(arr[l]==x)
return l;
if(arr[r]==x)
return r;
return linear(arr,l+1,r-1,x);
}
