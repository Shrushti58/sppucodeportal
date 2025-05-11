#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class stud{
	public:
		string name;
		string email;
		int roll;
		public:
			void create();
			void display();
			void search();
			void deleterec();
};
void stud::create(){
	ofstream fout("stud.txt",ios::app);
	int ch;
	do{
		cout<<"Enter Roll no :"<<endl;
		cin>>roll;
		cout<<"Enter name :"<<endl;
		cin>>ws;
		getline(cin,name);
		cout<<"Enter Email :"<<endl;
		cin>>ws;
		getline(cin,email);
		
		fout<<roll<<" "<<name<<" "<<email<<endl;
		cout<<"Enter choice"<<endl;
		cin>>ch;
		
	}while(ch==1);
	fout.close();
}
void stud::display(){
	ifstream fin("stud.txt");
	string s;
	string e;
	int r;
	while(fin>>r>>s>>e)
	{
		cout<<r<<" "<<s<<" "<<e<<endl;
	}
	fin.close();
}
void stud::search(){
	ifstream fin("stud.txt");
	if(!fin)
	{
		cout<<"Not found"<<endl;
	}
	string s;
	string e;
	int r;
	int f;
	cout<<"Enter roll no :"<<endl;
	cin>>f;
	bool found=false;
	while(fin>>r>>s>>e)
	{
		if(r==f)
		{
			cout<<"Record Found!"<<endl;
			cout<<r<<" "<<s<<" "<<e;
			found=true;
			break;
		}
	}
	if(!found)
	{
		cout<<"Not found!"<<endl;
	}
}
void stud::deleterec()
{
	ifstream fin("stud.txt");
	ofstream out("temp.txt");
	int f;
	string s;
	string e;
	bool found=false;
	int r;
	cout<<"Enter roll to be deletd"<<endl;
	cin>>f;
	while(fin>>r>>s>>e)
	{
		if(f==r)
		{
						found=true;

			continue;
		}
		out<<r<<" "<<s<<" "<<e<<endl;
	}
	 fin.close();
    out.close();
	remove("stud.txt");
	rename("temp.txt","stud.txt");
	if(!found)
	{
		cout<<"Record not found!"<<endl;
	}
}
int main()
{
	stud s;
	s.display();
	s.deleterec();
	s.display();

}
