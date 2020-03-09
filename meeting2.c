#include<stdio.h>
#define S 100
void selectsort(int arr1[S],int arr2[S],int n);
void print(int arr[S],int n);
int main()
{
	int c=0,st[S],ft[S],rs[S],rf[S],n,i,m[S];
	int f=0,s=0;
	printf("Enter number of meetings scheduled\n");
	scanf("%d",&n);
	printf("Enter Start time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&st[i]);
	}
	printf("Enter Finish time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ft[i]);	
	}
	selectsort(ft,st,n);
	//print(st,n);
	//print(ft,n);
	
	rs[0]=st[0];
	rf[0]=ft[0];
	f=0;
	s=0;
	m[0]=1;
	
	for(i=1;i<n;i++)
	{
		if(rf[f]<=st[i])
		{
			rs[++s]=st[i];
			rf[++f]=ft[i];
			m[s]=i+1;	
		}
	}
	printf("Total number of meetings=%d\n",s+1);
	printf("*******\n");
	printf("The meeting numbers after sorting\n");
	for(i=0;i<=s;i++)
	{
		printf("%d\n",m[i]);
	}
	for(i=0;i<=s;i++)
	{
		printf("%d  %d\n",rs[i],rf[i]);
	}
	return 0;
}

void selectsort(int arr1[S],int arr2[S],int n)
{
	int bele,i,j,small,temp,tempb,pos;
	for(i=0;i<n-1;i++)
	{
		bele=arr2[i];
		small=arr1[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(arr1[j]<small)
			{
				bele=arr2[j];
				small=arr1[j];
				pos=j;
			}
		}
		temp=arr1[i];
		arr1[i]=arr1[pos];
		arr1[pos]=temp;
		tempb=arr2[i];
		arr2[i]=arr2[pos];
		arr2[pos]=tempb;
	}
}
void print(int arr[S],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
