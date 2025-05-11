#include<iostream>
using namespace std;
#define max 100
class queue
{
	
	public:
	int front,rear;
	int a[max];
	queue()
	{
		front=rear=-1;	
	}
int full()
{
	 if(rear==max-1)
	 {
	 return 1;
	 }
	 else
	 {
	 	return 0;
	 }
	 
	 
}	
int empty()
{
	 if(front==-1)
	 {
	 return 1;
	 }
	 else
	 {
	 	return 0;
	 }
}	
void enqueue()
{
	int ele;
	if(full())
	{
		cout<<"queue is full";
	}
	else if(rear==-1)
	{
		cout<<"enter element";
		front=rear=0;
		cin>>ele;
		a[rear]=ele;
	}
	else
	{
		cout<<"enter element";
		cin>>ele;
		rear=rear+1;
		a[rear]=ele;
	}
}
void dequeue()
{
	if(empty())
	{
		cout<<"empty";
	}
	else if(rear==front)
	{
		int temp=a[front];
		front=rear=-1;
	}
	else
	{
		int temp=a[front];
		front=front+1;
	}
}
void display()
{
	for(int i=front;i<=rear;i++)
	{
		cout<<a[i]<<"\n";
		}	
}	
};
int main()
{
	queue q;
	q.enqueue();
	q.enqueue();
	q.enqueue();
	q.display();
	q.dequeue();
	cout<<"After Deletion";
	q.display();
	return 0;
}
