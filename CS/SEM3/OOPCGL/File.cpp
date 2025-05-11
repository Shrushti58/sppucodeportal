#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class emp
{
	public:
		string name;
	int id;
		void accept()
		{
			
			cout<<"Enter id"<<endl;
			cin>>id;
			cout<<"ENter name"<<endl;
			cin.ignore();
			getline(cin,name);
		}
		void display()
		{
			cout<<"Name"<<name<<endl;
			cout<<"Id"<<id<<endl;
		}
};

int main()
{
	emp e;
	fstream f1;
	f1.open("sample.txt",ios::out);
	if(!f1)
	{
		cout<<"Errorr in opening File!"<<endl;
	}
	e.accept();
	f1<<"Id:"<<e.id<<endl;
	f1<<"Name:"<<e.name<<endl;
	f1.close();
	fstream f2;
	f2.open("sample.txt",ios::in);
	if(!f2)
	{
		cout<<"Error";
	}
	string ch;
	cout<<"Reading File Contetnts"<<endl;
	while(getline(f2,ch))
	{
		cout<<ch<<endl;
		
	}
	f2.close();
}
