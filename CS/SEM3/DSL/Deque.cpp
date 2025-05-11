#include<iostream>
using namespace std;
#define max 100
class deque
{
	public:
	int front,rear;
	int a[max];	
	deque()
	{
		front=rear=-1;
	}
int empty()
{
	if(rear=front==-1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}

}
int full()
{
	if((rear+1)%max==front)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
	
}
void rearinsert()
{
	if(full())
	{
		cout<<"queue full";
	}
	else if(rear==-1)
	{
		int ele;
		cout<<"element:\n";
		cin>>ele;
		rear=front=0;
		a[rear]=ele;		
	}
	else
	{
		int ele;
		cout<<"element:\n";
		cin>>ele;
		rear=(rear+1)%max;
		a[rear]=ele;
	}
}
void frontinsert()
{
	if(full())
	{
		cout<<"queue full\n";
	}
	else if(front==-1)	
	{
		int ele;
		cout<<"element:\n";
		cin>>ele;
		rear=front=0;
		a[front]=ele;		
	}
	else
	{
		int ele;
		cout<<"element:\n";
		cin>>ele;
		front=(front-1+max)%max;
		a[front]=ele;
	}
}
void frontdelete()
{
	if(empty())
	{
		cout<<"Queue Empty\n";		
	}
	else if(rear==front)
	{
		int temp;
		temp=a[front];
		front=rear=-1;
	}
	else
	{
		int temp;
	    temp=a[front];
	    front=(front+1)%max;
	}
}
void reardelete()
{
	int temp;
	if(empty())
	{
		cout<<"Queue Empty\n";		
	}
	else if(rear==front)
	{
	
		temp=a[rear];
		front=rear=-1;
	    
	}
	else
	{
	    temp=a[rear];
	    rear=(rear-1+max)%max;
	}
}
void display()
{
	for(int i=front;i!=rear;i=(i+1)%max)
	{
		cout<<a[i]<<"\n";
	}	
	cout<<a[rear];
}
};
int main()
{
	deque d;
	d.rearinsert();
	d.rearinsert();
	d.rearinsert();
	d.rearinsert();
	d.reardelete();
	d.display();
	return 0;
}
