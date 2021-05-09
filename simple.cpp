#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

int maxWidth(Node *root){
   
    if (root ==NULL) return 0;
    int count=1,res=1;
	cout<<" ------"<<endl;
    queue <Node* > q;
    q.push(root);q.push(NULL);
    while(!q.empty() && q.front()!=NULL)
    {
	cout<<" --[][][][][-"<<endl;
        count=0;
        while(q.front()!=NULL)
        {
	        cout<<" @#@#@#@#@#@#@#$#%$"<<endl;
			cout<<" count is "<<count<<endl;
            Node* curr =q.front(); q.pop();
            if(curr->left!=NULL) { q.push(curr->left);count++;}
            if(curr->right!=NULL) { q.push(curr->right);count++;}
            
        }
        q.push(NULL);
        q.pop();
        res=max(count, res);
		cout<< " res is "<< res<<endl;
    }
    return res;
}  

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	
	cout<<maxWidth(root);
	return 0;
}