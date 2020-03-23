#include<stdio.h>
#include<conio.h>
#define S 20
int min(int a,int b);
int main()
{
int n,i,j,k;
int adj[S][S],d[S][S];
printf("Enter number of vertices\n");
scanf("%d",&n);
printf("Enter the adjacency matrix\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
		scanf("%d",&adj[i][j]);
	printf("\n");
}
for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		d[i][j]=adj[i][j];

for(k=1;k<=n;k++)
{
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
}
printf("Distance matrix is displayed\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
		printf("%d\t",d[i][j]);
	printf("\n");
}
getch();
return 0;
}

int min(int a,int b)
{
if(a<b)
return a;
else
return b;
}

OUTPUT

Enter number of vertices
4
Enter the adjacency matrix
0
9999
3
9999

2
0
9999
9999

9999
7
0
1

6
9999
9999
0

Distance matrix is displayed
0       10      3       4
2       0       5       6
7       7       0       1
6       16      9       0
