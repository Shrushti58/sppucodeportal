#include<iostream>
#define max 10
using namespace std;
class patient{
	public:
		string name;
		int prio;
		patient()
		{
			name="";
			prio=0;
		}
		patient(string n,int p)
		{
			name=n;
			prio=p;
		}
};
class pq{
	public:
		patient heap[max];
		int size;
		pq()
		{
			size=0;
		}
		void swap(patient &a,patient &b)
		{
			patient temp=a;
			a=b;
			b=temp;
		}
		void insert(string n,int p)
		{
			if(size>=max)
			{
				cout<<"Queuue is full"<<endl;
				return;
			}
			heap[size]=patient(n,p);
			int i=size;
			size++;
			while(i>0 && heap[i].prio>=heap[(i-1)/2].prio)
			{
				swap(heap[i],heap[(i-1)/2]);
				i=(i-1)/2;
			}
		}
		void display()
		{
			if(size==0)
			{
				cout<<"Quueue is empty"<<endl;
				return;
			}
			for(int i=0;i<size;i++)
			{
				cout<<"Name :"<<heap[i].name<<" "<<heap[i].prio<<endl;
			}
		}
		void serve()
		{
			if(size==0)
			{
				cout<<"Queue empty"<<endl;
				return;
			}
			
			heap[0]=heap[size-1];
			int i=0;
			size--;
			while(true)
			{
				int largest=i;
				int left=(2*i)+1;
				int right=(2*i)+2;
				if(left<size && heap[left].prio>heap[largest].prio)
				{
						largest=left;
				}
				if(right<size && heap[right].prio>heap[largest].prio)
				{
					largest=right;
				}
				if(i!=largest)
				{
					swap(heap[i],heap[largest]);
					i=largest;
				}
				else{
					break;
				}
				
			}
		}
};
int main()
{
	pq p;
	p.insert("a",3);
	p.insert("b",7);
	p.display();
	p.serve();
	p.display();
	p.serve();
	p.display();
}
