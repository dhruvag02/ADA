#include<stdio.h>
#include<stdlib.h>
#define S 10
int mergesort(int arr[],int n);
int _mergesort(int arr[],int temp[],int low,int high);
int merge(int arr[],int temp[],int low,int mid,int high);
int main()
{
    int n,i,arr[S],inv;
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    inv=mergesort(arr,n);
    printf("Total number of inversions are = %d\n",inv);
    return 0;
}
int mergesort(int arr[],int n)
{
    int *temp=(int *) malloc(n * sizeof(int));
    return _mergesort(arr,temp,0,n-1);
}
int _mergesort(int arr[],int temp[],int low,int high)
{
    int mid,inv=0;
    if(low<high)
    {
        mid=(low+high)/2;
        inv=inv+_mergesort(arr,temp,low,mid);
        inv=inv+_mergesort(arr,temp,mid+1,high);
        inv=inv+merge(arr,temp,low,mid+1,high);
    }
    return inv;
}
int merge(int arr[],int temp[],int low,int mid,int high)
{
    int i=low,j=mid,k=low;
    int inv=0;
    while((i<=mid-1)&&(j<=high))
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            inv=inv+(mid-1);
        }
    }
    while(i<=mid-1)
    {
        temp[k++]=arr[i++];
    }
    while(j<=high)
    {
        temp[k++]=arr[j++];
    }
    for(i=low;i<=high;i++)
        arr[i]=temp[i];
    return inv;
}

OUTPUT
5                                                                                                                                    
Enter the elements                                                                                                                   
1 20 6 4 5                                                                                                                           
Total number of inversions are = 5
