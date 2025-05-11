#include<iostream>
using namespace std;
class node{
	public:
		string name;
		string meaning;
		node* left;
		node* right;
		int height;
		node(string n,string m)
		{
			name=n;
			meaning=m;
			left=NULL;
			right=NULL;
			height=1;
		}
};
class avl{
	public:
		int height(node* r)
		{
			return (r==NULL)?0:max(height(r->left),height(r->right));
		}
		int balance(node* r)
		{
			return r==NULL?0:height(r->left)-height(r->right);
		}
		
		node* findmin(node* root)
		{
			while(root!=NULL)
			{
				root=root->right;
			}
			return root;
		}
		node* search(node* root,string n)
		{
			if(root==NULL)
			{
				cout<<"Not Found!"<<endl;
				return NULL;
			}
			if(n==root->name)
			{
				cout<<"Found!"<<endl;
				return root;
			}
			else if(n<root->name)
			{
				return search(root->left,n);
			}
			else
			{
				return search(root->right,n);
			}
		}
		
		node* rotateright(node* root)
		{
			node* t1=root->left;
			node* t2=t1->right;
			t1->right=root;
			root->left=t2;
			t1->height=1+max(height(t1->left),height(t1->right));
			root->height=1+max(height(root->left),height(root->right));
			return t1;
		}
		
		node* rotateleft(node* root)
		{
			node* t1=root->right;
			node* t2=t1->left;
			t1->left=root;
			root->right=t2;
			t1->height=1+max(height(t1->left),height(t1->right));
			root->height=1+max(height(root->left),height(root->right));
			return t1;
		}
		
		
		
		node* insert(node* root,string n,string m)
		{
			if(root==NULL)
			{
				cout<<"Inserted "<<n;
				return new node(n,m);
			}
			if(n<root->name)
			{
				root->left=insert(root->left,n,m);
			}
			else if(n>root->name)
			{
				root->right=insert(root->right,n,m);
			}
			else{
				cout<<"Meaning Updated"<<endl;
				root->meaning=m;
				return root;
			}
			root->height=height(root);
			int factor=balance(root);
			
			if(factor>1 && n<root->left->name)
			{
				return rotateright(root);
			}
			if(factor<-1 && n>root->right->name)
			{
				return rotateleft(root);
			}
			if(factor>1 && n>root->left->name)
			{
				root->left=rotateleft(root->left);
				return rotateright(root);
			}
			if(factor<-1 && n<root->right->name)
			{
				root->right=rotateright(root->right);
				return rotateleft(root);
			}
			return root;
		}
		
		node* deletenode(node* root,string n)
		{
			if(root==NULL)
			{
				cout<<"Not Found!";
				return NULL;
			}
			if(n<root->name)
			{
				root->left=deletenode(root->left,n);
			}
			else if(n>root->name)
			{
				root->right=deletenode(root->right,n);
			}
			else
			{
				if(root->left==NULL && root->right==NULL)
				{
					cout<<root->name<<"Deleted"<<endl;
					delete root;
					root=NULL;
				}
				else if(root->left==NULL)
				{
					node* temp=root;
					root=root->right;
					cout<<"Deleted"<<temp->name;
					delete temp;
				}
				else if(root->right==NULL)
				{
					node* temp=root;
					root=root->left;
					cout<<"Deleted"<<temp->name;
					delete temp;
				}
				else
				{
					node* temp=findmin(root);
					root->name=temp->name;
					root->right=deletenode(root->right,temp->name);
				}
			}
				root->height=height(root);
			int factor=balance(root);
			if(factor>1 && n<root->left->name)
			{
				return rotateright(root);
			}
			if(factor<-1 && n>root->right->name)
			{
				return rotateleft(root);
			}
			if(factor>1 && n>root->left->name)
			{
				root->left=rotateleft(root->left);
				return rotateright(root);
			}
			if(factor<-1 && n<root->right->name)
			{
				root->right=rotateright(root->right);
				return rotateleft(root);
			}
			
			
			return root;
		
		}
		
		
		void asc(node* root)
		{
			if(root==NULL)
			{
				return;
			}
			asc(root->left);
			cout<<root->name<<" : "<<root->meaning<<endl;		
			asc(root->right);
		}
		void dsc(node* root)
		{
			if(root==NULL)
			{
				return;
			}
			dsc(root->right);
			cout<<root->name<<" : "<<root->meaning<<endl;
			dsc(root->left);
		}
};
int main()
{
	
	avl a;
	node* root=NULL;
	root=a.insert(root,"a","aa");
	root=a.insert(root,"z","bbb");
	root=a.insert(root,"b","aa");
	root=a.insert(root,"y","aa");
	root=a.insert(root,"c","aa");
	root=a.insert(root,"x","aa");
	root=a.insert(root,"d","aa");
	root=a.deletenode(root,"c");
	a.asc(root);
	a.dsc(root);
}
