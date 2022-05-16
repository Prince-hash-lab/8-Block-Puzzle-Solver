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

Node *floor(Node *root, int x){
    Node *res=root;    Node *temp=root;
    while(temp!=NULL)
    {   if(((temp->key) > (res->key))  && (temp->key <=x))
           { res=temp;  }
        // cout<< temp->key<<" ";
        if(temp->key<=x) temp=temp->right;
        else temp=temp->left;
        
    }
    if(res->key > x) return NULL;
    return res;
} 

int main() {
	
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int x=17;
	
	cout<<"Floor: "<<(floor(root,17)->key);
}