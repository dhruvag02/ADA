#include<stdio.h>
#include<stdlib.h>
#define S 10
void create_heap(int a[S],int n,int i);
void heapsort(int a[S],int n);
void print(int a[S],int n);
void swap(int *,int *);
int main()
{
    int n,a[S],i;
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    heapsort(a,n);
    print(a,n);
    return 0;
}
void heapsort(int a[S],int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        create_heap(a,n,i);
    }
    for(i=n-1;i>0;i--)
    {
        swap(&a[0],&a[i]);
        create_heap(a,i,0);
    }
}
void create_heap(int a[S],int n,int i)
{
    int largest,l,r;
    largest=i;
    l=2*i+1;
    r=2*i+2;
    if(l<n&&a[l]>a[largest])
        largest=l;
    if(r<n&&a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        create_heap(a,n,largest);
    }
}
void print(int a[],int n)
{
    int i;
    printf("*******\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
}
void swap(int *num1,int *num2)
{
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}
OUTPUT
7                                                                                                                                      
Enter elements                                                                                                                         
100 20 30 50 40 80 99                                                                                                                  
*******                                                                                                                                
20                                                                                                                                     
30                                                                                                                                     
40                                                                                                                                     
50                                                                                                                                     
80                                                                                                                                     
99                                                                                                                                     
100
