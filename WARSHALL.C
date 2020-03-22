#include<conio.h>
#include<stdio.h>
#define S 20
int main()
{
int n,i,j,k;
int adj[S][S],p[S][S];
clrscr();
printf("Enter the number of vertices\n");
scanf("%d",&n);
printf("Enter the adjacency matrix for directed graph\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
	{
		scanf("%d",&adj[i][j]);
	}
	printf("\n");
}
for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		p[i][j]=adj[i][j];
for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(p[i][j]!=1 &&(p[i][k]==1&&p[k][j]==1))
				p[i][j]=1;

printf("Transitive closure is displayed\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
	{
		printf("%d\t",p[i][j]);
	 }
printf("\n");
}
getch();
return 0;
}