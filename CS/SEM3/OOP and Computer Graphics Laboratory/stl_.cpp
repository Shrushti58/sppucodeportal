#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
class item
{
	public:
		string name;
		int id;
		
};
void insert();
void display();
void search();
void sortitem();
vector<item>v;
bool compare(item &i1,item &i2)
{
	return i1.id<i2.id;
}
void insert()
{
	item i1;
	cout<<"Enter Name: ";
	cin.ignore();
	cin>>i1.name;
	cout<<"Enter id ";
	cin>>i1.id;
	v.push_back(i1);
}
void display()
{
	vector<item>::iterator i;
	for(i=v.begin();i!=v.end();i++)
	{
		cout<<i->name<<" ";
		cout<<i->id<<" ";
		cout<<endl;
	}
}
void search()
{
	int sid;
	cout<<"Enter Id to search"<<endl;
	cin>>sid;
	int flag=0;
	vector<item>::iterator i;
	for(i=v.begin();i!=v.end();i++)
	{
		if(sid==i->id)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"ID FOUND!!"<<endl;
	}
	else
	{
		cout<<"NOT"<<endl;
	}

}
void sortitem()
{
	sort(v.begin(),v.end(),compare);
	
}
int main()
{
	insert();
	insert();
	insert();
	sortitem();
	display();
	
	
}