#include<iostream>
using namespace std;
class node
{	public:
	node *next,*prev;
	int seat;
	int status;
	int id;
	friend class list;
};
class list
{
	public:
	node *head,*temp,*tail;
	void create();
	void book();
	void cancel();
	void ava();
	void display();
};
void list::create()
{
	int i;
	temp=new node;
	head=tail=temp;
	temp->seat=1;
	temp->status=0;
	temp->id=0;
	for(i=2;i<=71;i++)
	{
		node *p=new node;
		p->seat=i;
		p->status=0;
		p->id=0;
		tail->next=p;
		p->prev=tail;
		tail=p;
		tail->next=head;
		head->prev=tail;
	}
}
void list::display()
{
	int count=0;
	node *temp;
	temp=head;
	while(temp->next!=head)
	{
		if(temp->seat/10==0)
		{
			cout<<"S0"<<temp->seat;
		}
		else
		{
			cout<<"S"<<temp->seat;
		}
		count++;
		if(temp->status==0)
		{
			cout<<" "<<"|__|"<<" ";
		}
		else
		{
			cout<<" "<<"|_B|"<<" ";
		}
		if(count%7==0)
		{
			cout<<endl;
		}
		temp=temp->next;
	}
}
void list::book()
{
	int s,p;
	int flag=0;
	cout<<"Enter seat no to be boked"<<endl;
	cin>>s;
	temp=head;
	while(temp->next!=head)
	{
		if(temp->seat==s)
		{
			flag=1;
			break;
		}
		temp=temp->next;
	}
	cout<<"Enter id";
	cin>>p;
	if(flag==1)
	{
		if(temp->status==1)
		{
			cout<<"Already Booked"<<endl;
		}
		else
		{
			temp->status=1;
			temp->id=p;
		}
	}
	else
	{
		cout<<"Enter valid seat"<<endl;
	}
}
void list::cancel()
{
	int s,p;
	node *temp;
	temp=head;
	cout<<"Enter seat to cancel"<<endl;
	cin>>s;
	while(temp->next!=head)
	{
		if(temp->seat==s)
		{
			if(temp->status==0)
			{
				cout<<"Seat is unbboked"<<endl;
			}
			else
			{
				cout<<"Enter id"<<endl;
				cin>>p;
				if(temp->id==p)
				{
					temp->status=0;
				}
				else
				{
					cout<<"Worng id"<<endl;
				}
			}
		}
		temp=temp->next;
		
	}
}
void list::ava()
{
	int count=0;
	node *temp;
	temp=head;
	while(temp->next!=head)
	{
		if(temp->seat/10==0 && temp->status==0)
		{
			cout<<"S0"<<temp->seat<<" "<<"|__|"<<" ";
		}
		else if (temp->status==0)
		{
			cout<<"S"<<temp->seat<<" "<<"|__|"<<" ";
		}
		else
		{
			cout<<" ";
		}
		count++;
		if(count%7==0)
		{
			cout<<endl;
		}
		temp=temp->next;
	}
}
int main()
{
	list l;
	l.create();
	l.book();
	l.book();
//	l.cancel();
	l.display();
	cout<<"Available seat"<<endl;
	l.ava();
}