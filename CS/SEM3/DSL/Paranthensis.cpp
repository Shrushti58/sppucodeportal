#include<iostream>
#define max 50
using namespace std;
class stack
{
	int top;
	int a[max];
	public:
		stack()
		{
			top=-1;
		}
		void push(char);
		char pop();
		int full();
		int empty();
};
void stack::push(char c)
{
	top++;
	a[top]=c;
	a[top+1]='\0';
}
char stack::pop()
{
	char s;
	s=a[top];
	top--;
	return s;
}
int stack::full()
{
	if(top==max)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int stack::empty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	stack s;
	int i=0;
	char str[max];
	cout<<"Enter expersion";
	cin.getline(str,max);
	if(str[0]==']' || str[0]=='}' || str[0]==')')
	{
		cout<<"inavlid";
	}
	while(str[i]!='\0')
	{
		switch(str[i])
		{
			case '[':
				s.push(str[i]);
				break;
			case '{':
				s.push(str[i]);
				break;
			case '(':
				s.push(str[i]);
				break;
			case ')':
				s.pop();
				break;
			case ']':
				s.pop();
				break;
			case '}':
				s.pop();
				break;
		}
		i=i+1;
	}
	if(s.empty())
	{
		cout<<"Well";
		
	}
	else
	{
		cout<<"Not";
	}
}
