#include<iostream>
#include<string>
using namespace std;
class node
{
	int prn;
	string name;
	node *next;
	public:
		node(int pn,string s)
		{
			prn=pn;
			name=s;
			next=NULL;
		}
		friend class list;
};
class list
{
	node *start;
	public:
		list()
		{
			start=NULL;
		}
		void create();
		void insertatbeg();
		void insertatmid();
		void insertatend();
		void delatbeg();
		void delatmid();
		void delatend();
		void display();
		void count();
		void concat(list &);
};
void list::create()
{
	int pn;
	string s;
	if(start==NULL)
	{
		cout<<"Enter prn of Member"<<endl;
		cin>>pn;
		cout<<"Enter name of Member"<<endl;
		cin>>s;
		start=new node(pn,s);
	}
	else
	{
		cout<<"Already created"<<endl;
	}
}
void list::insertatbeg()
{
	if(start==NULL)
	{
		create();
	}
	else
	{
		node *p;
		int pn;
		string s;
		cout<<"Enter prn of President"<<endl;
		cin>>pn;
		cout<<"Enter name of President"<<endl;
		cin>>s;
		p=new node(pn,s);
		p->next=start;
		start=p;
		
	}
}
void list::insertatmid()
{
	int prev;
	node *p;
	node *temp;
	int flag=0;
	if(start==NULL)
	{
		create();
	}
	else
	{
		cout<<"Enter prn of previos memeber"<<endl;
		cin>>prev;
		temp=start;
		while(temp!=NULL)
		{
			if(temp->prn==prev)
			{
				flag=1;
				break;
			}
			temp=temp->next;
		}
		if(flag==1)
		{
			node *p;
			int pn;
			string s;
			cout<<"Enter prn of new memeber"<<endl;
			cin>>pn;
			cout<<"Enter name of new memeber"<<endl;
			cin>>s;
			p=new node(pn,s);
			p->next=temp->next;
			temp->next=p;
			
		}
		else
			{
				cout<<"NOt found"<<endl;
			}
		
	}
}
void list::insertatend()
{
	node *temp;
	temp=start;
	if(start==NULL)
	{
		create();
	}
	else
	{
		node *p;
		int pn;
		string s;
		cout<<"Enter prn of seceratory"<<endl;
		cin>>pn;
		cout<<"Enter name of seceratory"<<endl;
		cin>>s;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		p=new node(pn,s);
		temp->next=p;
		
	}
}
void list::delatbeg()
{
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		node *temp;
		temp=start;
		start=start->next;
		cout<<"President Deleted"<<" "<<temp->prn<<" "<<endl;
		delete temp;
	}
}
void list::delatmid()
{
	node *temp,*p;
	int prndel;
	int flag=0;
	if(start==NULL)
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		cout<<"Enter prn of member to delete"<<endl;
		cin>>prndel;
		temp=start;
		while(temp->next!=NULL)
		{
			if(temp->prn==prndel)
			{
				flag=1;
				break;
			}
			p=temp;
			temp=temp->next;
		}
		if(flag==1)
		{
			p->next=temp->next;
			temp->next=NULL;
			delete temp;
		}
		else
		{
			cout<<"Not found"<<endl;
		}
		
	}
}
void list::delatend()
{
	node *temp,*p;
	temp=start;
	while(temp->next!=NULL)
	{
		p=temp;
		temp=temp->next;
	}
	cout<<"Screatory deleted"<<temp->prn<<endl;
	p->next=NULL;
	delete temp;
}
void list::display()
{
	node *temp;
	if(start==NULL)
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			cout<<" "<<temp->prn<<" "<<temp->name<<" ";
			temp=temp->next;
		}
	}
}
void list::count()
{
	node *temp;
	temp=start;
	int count=0;
	while(temp!=NULL)
	{
		count=count+1;
		temp=temp->next;
	}
	cout<<"Total Count of Members"<<count<<endl;
	
}
void list::concat(list &l1)
{
	node *temp,*p;
	temp=l1.start;
	if(temp==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;
	cout<<"Concated";
	display();
}
int main()
{
	list l1,l2;
	list *l;
	l=&l1;
	int c,i;
	cout<<"0.Select List 1.Create Club 2.Add President 3.Add Secratory 4.Add Member"<<endl;
	cout<<"5.Delete presidant 6.Delete sec 7.Delete Member"<<endl;
	cout<<"8.Display Club Members 9.Display Count 10.Concat"<<endl;
	X:cout<<"Enter 1 or 2"<<endl;
	cin>>i;
	if(i==1)
	{
		l=&l1;
	}
	else if(i==2)
	{
		l=&l2;
	}
	else
	{
		cout<<"Choose correct no"<<endl;
	}
	do
	{
		cout<<"Enter choice"<<endl;
		cin>>c;
		switch(c)
		{
			case 0:
				goto X;
				break;
			case 1:
				l->create();
				break;
			case 2:
				l->insertatbeg();
				break;
			case 3:
				l->insertatend();
				break;
			case 4:
				l->insertatmid();
				break;
			case 5:
				l->delatbeg();
				break;
			case 6:
				l->delatend();
				break;
			case 7:
				l->delatmid();
				break;
				
			case 8:
				l->display();
				break;
			case 9:
				l->count();
				break;
			case 10:
				l1.concat(l2);
				break;
				
		}
	}while(c!=11);

	
	

}