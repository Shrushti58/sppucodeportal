#include<iostream>
#include<stack>
#include<string>
using namespace std;
class node{
	public:
		char data;
		node* left;
		node* right;
		node(char c){
			data=c;
			left=NULL;
			right=NULL;
		}
};
class expt{
	public:
		bool isop(char ch)
		{
			if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		node* createtree(string prefix)
		{
			stack<node*>st;
			for(int i=prefix.length()-1;i>=0;i--)
			{
				char ch=prefix[i];
				if(isspace(ch))
				{
					continue;
				}
				
				node* n=new node(ch);
				if(isop(ch))
				{
					
                	node* left = st.top(); st.pop(); 
                	node* right = st.top(); st.pop();  
					n->left=left;
					n->right=right;
				}
				st.push(n);
			}
			return st.top();				
		}
		void postorder(node* root){
			stack<node*>st1;
			stack<node*>st2;
			st1.push(root);
			while(!st1.empty())
			{
				node* curr=st1.top();
				st1.pop();
				st2.push(curr);
				
				if(curr->left){
					st1.push(curr->left);
				}
				if(curr->right)
				{
					st1.push(curr->right);
				}
			}
			
			while(!st2.empty()){
				cout<<st2.top()->data;
				st2.pop();
			}
		}
		
		void deletetree(node* root)
		{
			if(root==NULL){
				return;
			}
			deletetree(root->left);
			deletetree(root->right);
			
			delete root;
		}
};
int main(){
	expt e;
	string pre="+-a*bc/de";
	node* root=e.createtree(pre);
	e.deletetree(root);
	e.postorder(root);
	cout<<"succ";
}
