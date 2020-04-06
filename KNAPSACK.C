#include<stdio.h>
#include<conio.h>
#define S 10
int knapsack(int n,int m,int w[S],int p[S]);
int max(int num1,int num2);
int main()
{
int i,n,m,w[S],p[S];
int optimal;
clrscr();
printf("Enter number of objects\n");
scanf("%d",&n);
printf("Enter the knapsack capacity\n");
scanf("%d",&m);
printf("Enter the weights\n");
for(i=1;i<=n;i++)
{
	scanf("%d",&w[i]);
}
printf("Enter the profit\n");
for(i=1;i<=n;i++)
{
	scanf("%d\n",&p[i]);
}
printf("%d\n",knapsack(n,m,w,p));
getch();
return 0;
}

int knapsack(int n,int m,int w[S],int p[S])
{
int v[S][S],x[S],i,j;
for(i=0;i<=n;i++)
{
	for(j=0;j<=m;j++)
	{	if(i==0||j==0)
			v[i][j]=0;
		else if(w[i]>j)
			v[i][j]=v[i-1][j];
		else
			v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
	}
}
for(i=0;i<=n;i++)
	x[i]=0;
i=n;
j=m;
while(i!=0&&j!=0)
{
	if(v[i][j]!=v[i-1][j])
	{
		x[i]=1;
		j=j-w[i];
	}
i=i-1;
}
for(i=0;i<=n;i++)
{
	if(x[i]==1)
	{
		printf("Object %d is selected\n",i);
	}
	else
	{
		printf("Object %d is not selected\n",i);
	}
}
return v[n][m];
}
int max(int num1,int num2)
{
if(num1>num2)
return num1;
else
return num2;
}