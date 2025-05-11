#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void build(int root[10][10],vector<int>key,int i,int j){
	if(i==j)
	{
		cout<<"d:X "<<" ";
		return;
	}
	int r=root[i][j];
	cout<<"K :"<<key[r]<<" ";
	build(root,key,i,r-1);
	build(root,key,r,j);
}
int main()
{
	int n,a;
	cout<<"Enter no. of Nodes :"<<endl;
	cin>>n;
	vector<int>keys;
	vector<int>p;
	vector<int>q;
	int weight[10][10];
	int cost[10][10];
	int root[10][10];

	memset(weight,0,sizeof(weight));
	memset(cost,0,sizeof(weight));
	memset(root,0,sizeof(weight));


	
	keys.push_back(-1);
	p.push_back(-1);
	cout<<"Enter Keyss :"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		keys.push_back(a);
	}
	cout<<"Enter Sucess proablities :"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		p.push_back(a);
	}
	cout<<"Enter Unsucess pro :"<<endl;
	for(int i=0;i<=n;i++)
	{
		cin>>a;
		q.push_back(a);
	}
	
	for(int i=0;i<=n;i++){
		weight[i][i]=q[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			weight[i][j]=weight[i][j-1]+p[j]+q[j];
		}
	}
	
	cout<<"Weight :"<<endl;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<weight[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<=n;i++)
	{
		cost[i][i]=0;
		root[i][i]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		cost[i][i+1]=weight[i][i+1];
		root[i][i+1]=i+1;
	}
	
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<=n-l;i++)
		{
			int j=i+l;
			cost[i][j]=INT_MAX;
			for(int r=i+1;r<=j;r++)
			{
				int c=cost[i][r-1]+cost[r][j]+weight[i][j];
				if(c<cost[i][j])
				{
					cost[i][j]=c;
					root[i][j]=r;
				}
			}		
		}
	}
	
	cout<<endl;
	cout<<"Cost Matrix:"<<endl;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<cost[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	
	cout<<"Root matrix :"<<endl;
		for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<root[i][j]<<" ";
		}
		cout<<endl;
	}
	build(root,keys,0,n);
}
