#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define S 100
int adj[S][S],visited[S];
int n;
void dfs(int v);

int main()
{
	int i,j,count=0;
	printf("Enter number of vertex\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	printf("Enter adjacency matrix\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		scanf("%d",&adj[i][j]);
		}	
	printf("\n");
	}
	
	dfs(0);
	printf("\n****\n");
	for(i=0;i<n;i++)
	{
		if(visited[i])
		count++;
	}
	if(count==n)
		printf("Connected graph");
	else
		printf("Unconnected graph");
	return 0;
}

void dfs(int v)
{
	int i,j;
	printf("\n%d",v);
	visited[v]=1;
	
	for(i=0;i<n;i++)
		if(adj[v][i] && !visited[i])
				dfs(i);
}

