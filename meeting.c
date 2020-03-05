#include<stdio.h>
#define S 100
void insertsort(int arr[S],int n);
int main()
{
int st[S],ft[S],rs[S],rf[S],p[S];
int i,j,n,f,s;
printf("Enter total number of mmetings\n");
scanf("%d",&n);
printf("Enter Start time of meetings\n");
for(i=0;i<n;i++)
scanf("%d",&st[i]);
printf("Enter finish time of meetings\n");
for(i=0;i<n;i++)
scanf("%d",&ft[i]);
insertsort(st,n);
insertsort(ft,n);
rs[0]=st[0];
rf[0]=ft[0];
f=0;
s=0;
p[0]=1;
for(int i=1;i<n;i++)
{
	if(rf[f]<=st[i])
	{
		rs[++s]=st[i];
		rf[++f]=ft[i];
		p[S]=i+1;
	}
}
printf("Maximum number of meetings are:\n");
for(i=0;i<=s;i++)
printf("%d\n",p[i]);
for(i=0;i<=s;i++)
{
printf("%d %d\n",rs[i],rf[i]);
}
return 0;
}

void insertsort(int arr[S],int n)
{
int i,key,j;
for(i=0;i<n;i++)
{
key=arr[i];
j=i-1;
	while(j>=0 && arr[j]>key)
	{
	arr[j+1]=arr[j];
	j=j-1;
	}
arr[j+1]=key;
}
}


