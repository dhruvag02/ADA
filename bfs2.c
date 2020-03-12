#include<stdio.h>
#include<stdlib.h>
#define S 10
int adj[S][S],visited[S],q[S],r=-1,f=0,n;
int is_empty();
void bfs(int v);
int main()
{
	int v,i,j;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		visited[i]=0;
	printf("Enter adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
		printf("\n");
	}
	printf("Enter the source vertex\n");
	scanf("%d",&v);
	visited[v]=1;
	r=r+1;
	q[r]=v;
	bfs(v);
	return 0;
}
void bfs(int v)
{
	int i;
	if(!is_empty())
	{
		for(i=0;i<n;i++)
		{
			if(adj[v][i] && !visited[i])
			{
				r=r+1;
				q[r]=i;
				visited[r]=1;
			}
		}
		printf("%d\t",q[f]);
		f=f+1;
		bfs(q[f]);
	}
}
int is_empty()
{
	if(f>r)
	return 1;
	else 
	return 0;
}
