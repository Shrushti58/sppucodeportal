#include<iostream>
#include<string>
#include<vector>
using namespace std;
class node{
	public:
		string name;
		vector<node*>child;
		int childcount;
		node(string s)
		{
			name=s;
		}
		void addchild(node* childern)
		{
			child.push_back(childern);
		}
};
class gt{
	public:
		node* a;
		string name;
		int count;
		int chaptercount;
		int sectioncount;
		gt()
		{
			a=NULL;
		}
		void display(node* root)
		{
			cout<<"Title of Book :"<<root->name<<endl;
			cout<<"Chapters of Book :"<<endl;
			int chapterc=root->childcount;
			for(int i=0;i<chapterc;i++)
			{
				cout<<i <<root->child[i]->name<<endl;
				cout<<"Subsections :"<<endl;
				for(int j=0;j<root->child[i]->childcount;j++)
				{
					cout<<root->child[i]->child[j]->name<<endl;
				}
			}
		}
		void createtree()
		{
			cout<<"Enter Book Name :";
			cin>>name;
			a=new node(name);
			cout<<"Enter Total no. of Chapters :";
			cin>>chaptercount;
			a->childcount=chaptercount;
			for(int i=0;i<chaptercount;i++)
			{
				cout<<"Enter name of Chapter"<<i+1<<" :";
				cin>>name;
				node* chp=new node(name);
				a->addchild(chp);
				
				cout<<"Enter total no. of sections :";
				cin>>sectioncount;
				chp->childcount=sectioncount;
				
				for(int j=0;j<sectioncount;j++)
				{
					cout<<"Enter name of Section :";
					cin>>name;
					node* s=new node(name);
					chp->addchild(s);
					
				}
			}
			display(a);
		}
		
};
int main()
{
	gt g;
	g.createtree();

}
