#include<iostream>
#include<string.h>
#define max 50
using namespace std;
class stack
{
	int top;
	char a[max];
	public:
		stack()
		{
			top=-1;
		}
		void reverse();
		void convert(char []);
		void pali();
		void push(char c);
};
void stack::push(char c)
{
	top++;
	a[top]=c;
	a[top+1]='\0';
}
void stack::convert(char str[])
{
	int k,j,len=strlen(str);
	for(j=0,k=0;j<len;j++)
	{
		if(((int)str[j]>=97 && (int)(str[j]<=122)) ||((int)str[j]>=65 && (int)str[j]<=90))
		{
			if((int)str[j]<=90)
			{
				str[k]=(char)((int)str[j]+32);
			}
			else
			{
				str[k]=str[j];
			}
			k++;
		}
	}
	str[k]='\0';
	cout<<" "<<str;
}
void stack::reverse()
{
	int i,j;
	char str1[max];
	cout<<endl;
	for(i=top,j=0;i>=0;i--,j++)
	{
		cout<<a[i];
		str1[j]=a[i];
		
	}
}
void stack::pali()
{
	char str2[max];
	int i,j;
	for(i=top,j=0;i>=0;i--,j++)
	{
		str2[j]=a[i];
	}
	str2[j]='\0';
	if(strcmp(str2,a)==0)
	{
		cout<<"Pali";
	}
	else
	{
		cout<<"not";
	}
}

int main()
{
	stack s;
	char mainstr[max];
	cout<<"Enter string";
	cin.getline(mainstr,max);
	s.convert(mainstr);
	int i=0;
	while(mainstr[i]!='\0')
	{
		s.push(mainstr[i]);
		i++;
	}
	s.reverse();
	s.pali();
}

