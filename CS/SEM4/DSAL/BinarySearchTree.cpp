#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
		node(int x)
		{
			data=x;
			left=NULL;
			right=NULL;
		}
};
class bst{
	public:
		node* insert(node* root,int val)
		{
			if(root==NULL)
			{
				return new node(val);
			}
			if(val<root->data)
			{
				root->left=insert(root->left,val);
			}
			else
			{
				root->right=insert(root->right,val);
			}
		}
		
		void display(node* root)
		{
			if(root==NULL)
			{
				return;
			}
			display(root->left);
			cout<<root->data<<" ";
			display(root->right);
		}
		
		int height(node* root)
		{
			if(root==NULL)
			{
				return -1;
			}
			int lefth=height(root->left);
			int righth=height(root->right);
			return max(lefth,righth)+1;
		}
		
		int mini(node* root)
		{
			if(root==NULL)
			{
				return -1;
			}
			while(root->left!=NULL)
			{
				root=root->left;
			}
			return root->data;
		}
		
		bool search(node* root,int key)
		{
			if(root==NULL)
			{
				return false;
			}
			if(root->data==key)
			{
				return true;
			}
			if(key<root->data)
			{
				search(root->left,key);
			}
			else
			{
				search(root->right,key);
			}
		}
		
		void mirror(node* root)
		{
			if(root==NULL)
			{
				return;
			}
			node* temp=root->left;
			root->left=root->right;
			root->right=temp;
			mirror(root->left);
			mirror(root->right);
		}
};
int main(){
	node* root=NULL;
	bst b;
	root=b.insert(root,34);
	root=b.insert(root,4);
	root=b.insert(root,3);
	b.mirror(root);
	b.display(root);
	cout<<b.height(root)<<" ";
	cout<<b.mini(root)<<" ";
	cout<<b.search(root,34);

	
}
