#include<stdio.h>
#define S 100

void rotatebyone(int arr[S],int n);
void rotate(int arr[S],int d,int n);
int binary(int arr[S],int,int,int);
int findpivot(int arr[S],int,int);
int pivotbinary(int arr[S],int n,int key);

int pivotbinary(int arr[S],int n,int key)
{
int pivot=findpivot(arr,0,n-1);
if(pivot==-1)
return binary(arr,0,n-1,key);
if(arr[pivot]==key)
return pivot;
if(arr[0]<=key)
return binary(arr,0,pivot-1,key);
return binary(arr,pivot+1,n-1,key);
}
int findpivot(int arr[S],int low,int high)
{
int mid;
if(high<low)
return -1;
if(high==low)
{
return low;
}
mid=(low+high)/2;
if(mid<high && arr[mid]>arr[mid+1])
return mid;
if(mid>low && arr[mid]<arr[mid-1])
return (mid-1);
if(arr[low]>=arr[mid])
return findpivot(arr,low,mid-1);
return findpivot(arr,mid+1,high);
}
int binary(int arr[S],int low,int high,int key)
{
int mid;
if(high<low)
return -1;
mid=(low+high)/2;
if (key==arr[mid])
return mid;
if(key>arr[mid])
return binary(arr,(mid+1),high,key );
return binary(arr,low,(mid-1),key);
}

void rotate(int arr[S],int d,int n)
{
int i;
for(i=0;i<d;i++)
rotatebyone(arr,n);
}
void rotatebyone(int arr[S],int n)
{
int temp=arr[0],i;
for(i=0;i<n-1;i++)
arr[i]=arr[i+1];
arr[i]=temp;
}

int main()
{
int arr[S],i,p,key,n;
clrscr();
printf("Enter size of array\n");
scanf("%d",&n);
printf("Enter elements in array\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter num to rotate\n");
scanf("%d",&p);
printf("Enter the element to be searched\n");
scanf("%d",&key);
rotate(arr,p,n);
printf("Element found at position %d\n",pivotbinary(arr,n,key));
printf("************\n");
for(i=0;i<n;i++)
{
printf("%d\n",arr[i]);
}

getch();
return 0;
}
