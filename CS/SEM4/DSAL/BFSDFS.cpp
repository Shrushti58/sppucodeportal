#include<iostream>
#include<queue>
using namespace std;
void bfs(int start,vector<vector<int> >adj,int n)
{
	queue<int>q;
	q.push(start);
	
	vector<bool>visited(n,false);
	visited[start]=true;
	while(!q.empty())
	{
		int curr=q.front();
		cout<<curr;
		q.pop();
		for(int i=0;i<adj[curr].size();i++)
		{
			int child=adj[curr][i];
			if(!visited[child])
			{
				visited[child]=true;
				q.push(child);
				
			}
		}
	}
}

void dfs(int start,vector<vector<int> >adj,int n,vector<bool>v)
{
	v[start]=true;
	cout<<start;
	for(int i=0;i<adj[start].size();i++)
	{
		int child=adj[start][i];
		if(!v[child])
		{
			dfs(child,adj,n,v);
		}
	}
}
int main()
{
	int n;
	int e;
	cout<<"Enter no. of nodes :";
	cin>>n;
	cout<<"Enter no of edges :";
	cin>>e;
	vector<vector<int> >adj(n);
	int mat[100][100]={0};
	int u=0,v=0;
	for(int i=0;i<e;i++)
	{
		cout<<"Enter u & v"<<" ";
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		mat[u][v]=1;
		mat[v][u]=1;
	}
	
	cout<<"Adjanceny List :";
	for(int i=0;i<n;i++)
	{
		cout<<i<<" ";
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<adj[i][j]<<"->";
		}
		cout<<endl;
	}
	
	cout<<"Matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
//	bfs(0,adj,n);
	
	vector<bool>vis(n,false);
	dfs(0,adj,n,vis);
	
}
