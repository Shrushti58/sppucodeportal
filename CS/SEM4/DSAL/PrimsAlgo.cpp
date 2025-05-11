#include<iostream>
#include<tuple>
#include<vector>
#include<queue>
using namespace std;
int primsalgo(vector<vector<pair<int,int>>>&adj,int n)
{
	priority_queue<
	tuple<int,int,int>,
	vector<tuple<int,int,int>>,
	greater<tuple<int,int,int>>>pq;
	vector<int>visited(n,0);
	vector<pair<int,int>>ans;
	visited[0]=1;
	int sum=0;
	for(int i=0;i<adj[0].size();i++)
	{
		int child=adj[0][i].first;
		int weight=adj[0][i].second;
		int parent=0;
		pq.push(make_tuple(weight,child,parent));
	}
	
	while(!pq.empty())
	{
		int w=get<0>(pq.top());
		int node=get<1>(pq.top());
		int par=get<2>(pq.top());
		pq.pop();
		
		if(visited[node]==1)
		{
			continue;
		}
		
		visited[node]=1;
		sum+=w;
		if(par!=-1)
		{
			ans.push_back(make_pair(node,par));
		}
		
		for(int i=0;i<adj[node].size();i++)
		{
			int child=adj[node][i].first;
			int w=adj[node][i].second;
			if(visited[child]==0)
			{
				pq.push(make_tuple(w,child,node));
			}
		}
	}
	
	 cout<<endl;
	 cout<<"MST :"<<endl;
	 for(int i=0;i<ans.size();i++)
	 {
	 	cout<<ans[i].first<<"->"<<ans[i].second<<endl;
	 }
	
	return sum;
}
int main()
{
	int n;
	int e;
	cout<<"Enter no of Cities :";
	cin>>n;
	cout<<"Enter no. Links :";
	cin>>e;
	int u=0;
	int v=0;
	int w=0;
	vector<vector<pair<int,int> > >adj(n);
	for(int i=0;i<e;i++)
	{
		cout<<"Enter u and v :";
		cin>>u>>v;
		cout<<"Enter weight :";
		cin>>w;
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<i<<" ";
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<adj[i][j].first<<adj[i][j].second;
		}
		cout<<endl;
	}
	
	cout<<primsalgo(adj,n);
}
