// Insertion sort for even-positioned elements in ascending order and odd-positioned elements in descending order
#include<stdio.h>
#include<stdlib.h>
#define S 10
void insertionsort(int arr[],int n);
void print(int arr[],int n);
int main()
{
    int i;
    int n,arr[S];
    printf("Enter the size\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    insertionsort(arr,n);
    print(arr,n);
    return 0;
}
void insertionsort(int arr[],int n)
{
    int i,j,item;
    for(i=2;i<n;i++)
    {
        item=arr[i];
        j=i-2;
        if((i+1)&1==1)
        {
            while(j>=0 && arr[j]<item)
            {
                arr[j+2]=arr[j];
                j=j-2;
            }
            arr[j+2]=item;
        }
        else
        {
            while(j>=0 && arr[j]>item)
            {
                arr[j+2]=arr[j];
                j=j-2;
            }
            arr[j+2]=item;
        }
    }
}
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}

OUTPUT
Enter the size                                                                                                                         
9                                                                                                                                      
7 10 11 3 6 9 2 13 0                                                                                                                   
11 3 7 9 6 10 2 13 0 
