#include <bits/stdc++.h> 
using namespace std;
stack<int> s;
int n,a[30][30],q[30],f=0,r=-1;
void lexorder()
{
	vector<int> indeg(n,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==1)
				indeg[j]++;
		}
			
	}
	
	for(int i=0;i<n;i++)
	{
		if(indeg[i]==0)
			q[++r]=i;
	}
	int c=0;
	vector<int> toporder;
	while(f<=r)
	{
		int min=q[f++];
		
		toporder.push_back(min);
		for(int i=0;i<n;i++)
		{
			if(a[min][i]==1)
			{
				indeg[i]--;
				if(indeg[i]==0)
					q[++r]=i;
			}
			
		}
		c++;
	}
	if(c!=n)
	{
		cout<<-1<<endl;
		return;
	}
	for(int i=0;i<toporder.size();i++)
		cout<<toporder[i]<<" ";
			
}

int main()
{
	cout<<"Enter the no of vertices"<<endl;
	cin>>n;
	cout<<"Enter the adjacency matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	cout<<"lexicographically smallest topological ordering is"<<endl;
	lexorder();
	return 0;
}
