#include<stdio.h>
#define S 100
#include<time.h>
void selectsort(int arr[S],int n);
void swap(int *xp,int *yp);
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
selectsort(arr,n);
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

void selectsort(int arr[S],int n)
{
int i,j,temp,min_ind,small;
for(i=0;i<n-1;i++)
{
min_ind=i;
small=arr[i];
for(j=i+1;j<n;j++)
{
if(arr[j]<small)
{
small=arr[j];
min_ind=j;
}
}
swap(&arr[min_ind],&arr[i]);
}
}

void swap(int *xp,int *yp)
{
int temp;
temp=*xp;
*xp=*yp;
*yp=temp;
}

Enter number of elements to be inserted in array
5
Enter the elements
5
4
3
2
1
Time required to complete bubble sort:0.000002 seconds
Elements in sorted order
1
2
3
4
5
Enter number 'k' to view k largest elements
2
*******
5
4



