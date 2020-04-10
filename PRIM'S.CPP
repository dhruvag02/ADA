#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define S 10
int minkey(int key[S],int mst[S],int n);
int print(int parent[S],int adj[S][S],int n);
void prims(int adj[S][S],int n);
int main()
{
int n,i,j;
int adj[S][S];
clrscr();
printf("Enter the number of vertices in the graph\n");
scanf("%d",&n);
printf("Enter the adjacency matrix\n");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		scanf("%d",&adj[i][j]);
	}
	printf("\n");
}
prims(adj,n);
getch();
return 0;
}
void prims(int adj[S][S],int n)
{
int mst[S];
int parent[S],key[S];
int i,count,v,u;
for(i=0;i<n;i++)
{
key[i]=INT_MAX;
mst[i]=0;
}
key[0]=0;
parent[0]=-1;
for(count=0;count<n-1;count++)
{
u=minkey(key,mst,n);
mst[u]=1;
for(v=0;v<n;v++)
{
if(adj[u][v] && mst[v]==0 && adj[u][v]<key[v])
{
parent[v]=u;
key[v]=adj[u][v];
}
}
}
print(parent,adj,n);
}

int print(int parent[S],int adj[S][S],int n)
{
int i;
printf("Edge \tWeight\n");
for(i=1;i<n;i++)
	printf("%d - %d\t%d \n",parent[i],i,adj[i][parent[i]]);
	return 0;
}
int minkey(int key[S],int mst[S],int n)
{
int min=INT_MAX;
int i,min_index;
for(i=0;i<n;i++)
{
if(mst[i]==0 && key[i]<min)
{
min=key[i];
min_index=i;
}
}
return min_index;
}