#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdbool.h>

bool LTR=true;
bool RTL=false;

int searchArr(int a[],int n,int mobile)
{
	int i;
	for(i=0;i<n;i++)
		if(a[i]==mobile)
			return i+1;
}

int getMobile(int a[],bool dir[],int n)
{
	int i;
	int mobile_prev=0,mobile=0;
	for(i=0;i<n;i++)
	{
		if(dir[a[i]-1] ==  RTL && i!=0)
		{
			if(a[i]>a[i-1] && a[i]>mobile_prev)
			{
				mobile=a[i];
				mobile_prev=mobile;
			}
		}
		if(dir[a[i]-1]==LTR && i!=n-1)
		{
			if(a[i]>a[i+1]&&a[i]>mobile_prev)
			{
				mobile=a[i];
				mobile_prev=mobile;
			}
		}
	}
	if(mobile==0&&mobile_prev==0)
		return 0;
	else
		return mobile;
}

int printOnepermu(int a[],bool dir[],int n)
{
	int i,mobile,temp,pos;
	mobile=getMobile(a,dir,n);
	pos=searchArr(a,n,mobile);
	
	if(dir[a[pos-1]-1]==RTL)
	{
		temp=a[pos-1];
		a[pos-1]=a[pos-2];
		a[pos-2]=temp;
	}
		//swap(a[pos-1],a[pos-2]);
		
	else if(dir[a[pos-1]-1]==LTR)
	{
		temp=a[pos];
		a[pos]=a[pos-1];
		a[pos-1]=temp;
	}
		//swap(a[pos],a[pos-1]);
		
	for(i=0;i<n;i++)
	{
		if(a[i]>mobile)
		{
			if(dir[a[i]-1]==LTR)
				dir[a[i]-1]=RTL;
			else if(dir[a[i]-1]==RTL)
				dir[a[i]-1]=LTR;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int fact(int n)
{
	int i,res=1;
	for(i=1;i<=n;i++)
		res=res*i;
	return res;
}

void printPermu(int n)
{
	int i;
	int a[n];
	bool dir[n];
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
		printf("%d",a[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
		dir[i]=RTL;
	for(i=1;i<fact(n);i++)
	{
		printOnepermu(a,dir,n);
	}
}

int main()
{
	int n;
	printf("Enter number\n");
	scanf("%d",&n);
	printPermu(n);
	return 0;
}
