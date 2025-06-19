#include<iostream>
#include<map>
#include<string.h>
using namespace std;
int main()
{
	map<string,int>m;
	m.insert(pair<string,int>("Maharastra",100));
	m.insert(pair<string,int>("UP",10));
	m.insert(pair<string,int>("Bihar",50));
	m.insert(pair<string,int>("Goa",1));
	m.insert(pair<string,int>("Karnataka",50));
	m.insert(pair<string,int>("MP",80));
	map<string,int>::iterator i;
	for(i=m.begin();i!=m.end();i++)
	{
		cout<<i->first<<":"<<i->second<<"Million"<<endl;
	}
	string s;
	cout<<"Enter state"<<endl;
	cin>>s;
	i=m.find(s);
	if(i!=m.end())
	{
		cout<<i->first<<" "<<i->second<<endl;
	}
	else
	{
		cout<<"Not found"<<endl;
	}
	
	
	
}